/*
    Copyright (C) 2011 Fredrik Johansson

    This file is part of FLINT.

    FLINT is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#include "fmpz_mat.h"
#include "fmpq_mat.h"

void
_fmpz_mat_solve_dixon_den(fmpz_mat_t X, fmpz_t den,
                        const fmpz_mat_t A, const fmpz_mat_t B,
                    const nmod_mat_t Ainv, mp_limb_t p,
                    const fmpz_t N, const fmpz_t D)
{
    fmpz_t bound, ppow;
    fmpz_mat_t x, d, y, Ay, AX, Bden;
    fmpq_mat_t x_q;
    fmpz_t prod, mod, xknum, xkden;
    fmpz * xvec_num, * xvec_den;
    mp_limb_t * crt_primes;
    nmod_mat_t * A_mod;
    nmod_mat_t Ay_mod, d_mod, y_mod;
    slong i, j, k, l, n, s, cols, num_primes, nz_count = 0;
    slong nz_r[5], nz_c[5]; /* rows and cols of nonzero entries of x */
    int stabilised; /* has lifting stabilised (at 5 nonzero entries) */

    n = A->r;
    cols = B->c;

    fmpz_init(bound);
    fmpz_init(ppow);
    fmpz_init(prod);
    fmpz_init(mod);
    fmpz_init(xknum);
    fmpz_init(xkden);

    fmpz_mat_init(Bden, B->r, B->c);
    fmpz_mat_init(AX, B->r, B->c);
    fmpz_mat_init(x, n, cols);
    fmpz_mat_init(y, n, cols);
    fmpz_mat_init(Ay, n, cols);
    fmpz_mat_init_set(d, B);

    fmpq_mat_init(x_q, n, cols);

    xvec_num = _fmpz_vec_init(5);
    xvec_den = _fmpz_vec_init(5);

    /* Compute bound for the needed modulus. TODO: if one of N and D
       is much smaller than the other, we could use a tighter bound (i.e. 2ND).
       This would require the ability to forward N and D to the
       rational reconstruction routine.
     */
    if (fmpz_cmpabs(N, D) < 0)
        fmpz_mul(bound, D, D);
    else
        fmpz_mul(bound, N, N);
    fmpz_mul_ui(bound, bound, UWORD(2));  /* signs */

    crt_primes = fmpz_mat_dixon_get_crt_primes(&num_primes, A, p);
    A_mod = (nmod_mat_t *) flint_malloc(sizeof(nmod_mat_t) * num_primes);
    for (j = 0; j < num_primes; j++)
    {
        nmod_mat_init(A_mod[j], n, n, crt_primes[j]);
        fmpz_mat_get_nmod_mat(A_mod[j], A);
    }

    nmod_mat_init(Ay_mod, n, cols, UWORD(1));
    nmod_mat_init(d_mod, n, cols, p);
    nmod_mat_init(y_mod, n, cols, p);

    fmpz_one(ppow);

    i = 1; /* working with p^i */
    
    while (fmpz_cmp(ppow, bound) <= 0)
    {
        /* y = A^(-1) * d  (mod p) */
        fmpz_mat_get_nmod_mat(d_mod, d);
        nmod_mat_mul(y_mod, Ainv, d_mod);

        /* x = x + y * p^i    [= A^(-1) * b mod p^(i+1)] */
        fmpz_mat_scalar_addmul_nmod_mat_fmpz(x, y_mod, ppow);

        /* ppow = p^(i+1) */
        fmpz_mul_ui(ppow, ppow, p);
        if (fmpz_cmp(ppow, bound) > 0)
            break;

	if ((i & (i - 1)) == 0) /* check if v is a power of 2 */
        {
           /* on first iteration, identify five nonzero entries */
	   if (nz_count == 0)
           {
              slong stride;
              
              /* count nonzero entries */
	      for (k = 0; k < x->r; k++)
	         for (l = 0; l < x->c; l++)
	            if (!fmpz_is_zero(fmpz_mat_entry(x, k, l)))
		       nz_count++;

              stride = (nz_count - 1)/5;

	      nz_count = 0;

              /* find five nonzero entries equally spaced */
              for (k = 0, s = 0; k < x->r && s < 5; k++)
              {
                 for (l = 0; l < x->c && s < 5; l++)
                 {
                    if (!fmpz_is_zero(fmpz_mat_entry(x, k, l)))
		    {
		       nz_count++;

                       if (stride == 0)
		       {
		          for ( ; s < 5; s++)
			     nz_r[s] = k, nz_c[s] = l;
		       } else if (stride == 1 || (nz_count % stride) == 1)
                       {
                          nz_r[s] = k, nz_c[s] = l;
		          s++;
                       }
		    }
                 }
              }
	   }

	   /* check if the five nonzero entries are stabilised */
	   stabilised = nz_count != 0;

           for (s = 0; s < 5 && stabilised; s++)
           {
	      /* set stabilised to success of reconstruction */
              if ((stabilised = _fmpq_reconstruct_fmpz(xknum, xkden,
			fmpz_mat_entry(x, nz_r[s], nz_c[s]), ppow)))
              {
                 _fmpq_canonicalise(xknum, xkden);

		 stabilised &= fmpz_equal(xknum, xvec_num + s);
                 stabilised &= fmpz_equal(xkden, xvec_den + s);

		 fmpz_set(xvec_num + s, xknum);
		 fmpz_set(xvec_den + s, xkden);
	      }     
           }

	   /* full matrix stabilisation check */
	   if (stabilised || i == 1)
           {
              fmpq_mat_set_fmpz_mat_mod_fmpz(x_q, x, ppow);
              fmpq_mat_get_fmpz_mat_matwise(X, den, x_q);

              fmpz_mat_mul(AX, A, X);
              fmpz_mat_scalar_mul_fmpz(Bden, B, den);

	      if (fmpz_mat_equal(AX, Bden))
	         goto dixon_done;
           }
	}

	i++;

        /* d = (d - Ay) / p */
#if USE_SLOW_MULTIPLICATION
        fmpz_mat_set_nmod_mat_unsigned(y, y_mod);
        fmpz_mat_mul(Ay, A, y);
#else
        for (j = 0; j < num_primes; j++)
        {
            _nmod_mat_set_mod(y_mod, crt_primes[j]);
            _nmod_mat_set_mod(Ay_mod, crt_primes[j]);
            nmod_mat_mul(Ay_mod, A_mod[j], y_mod);
            if (j == 0)
            {
                fmpz_mat_set_nmod_mat(Ay, Ay_mod);
                fmpz_set_ui(prod, crt_primes[0]);
            }
            else
            {
                fmpz_mat_CRT_ui(Ay, Ay, prod, Ay_mod, 1);
                fmpz_mul_ui(prod, prod, crt_primes[j]);
            }
        }
#endif

        _nmod_mat_set_mod(y_mod, p);
        fmpz_mat_sub(d, d, Ay);
        fmpz_mat_scalar_divexact_ui(d, d, p);
    }

    /* TODO can be changed to one step */
    fmpq_mat_set_fmpz_mat_mod_fmpz(x_q, x, ppow);
    fmpq_mat_get_fmpz_mat_matwise(X, den, x_q);

dixon_done:

    _fmpz_vec_clear(xvec_num, 5);
    _fmpz_vec_clear(xvec_den, 5);

    nmod_mat_clear(y_mod);
    nmod_mat_clear(d_mod);
    nmod_mat_clear(Ay_mod);

    for (j = 0; j < num_primes; j++)
        nmod_mat_clear(A_mod[j]);

    flint_free(A_mod);
    flint_free(crt_primes);

    fmpz_clear(xknum);
    fmpz_clear(xkden);
    fmpz_clear(bound);
    fmpz_clear(ppow);
    fmpz_clear(prod);
    fmpz_clear(mod);

    fmpq_mat_clear(x_q);

    fmpz_mat_clear(AX);
    fmpz_mat_clear(Bden);
    fmpz_mat_clear(x);
    fmpz_mat_clear(y);
    fmpz_mat_clear(d);
    fmpz_mat_clear(Ay);
}

int
fmpz_mat_solve_dixon_den(fmpz_mat_t X, fmpz_t den,
                        const fmpz_mat_t A, const fmpz_mat_t B)
{
    nmod_mat_t Ainv;
    fmpz_t N, D;
    mp_limb_t p;

    if (!fmpz_mat_is_square(A))
    {
        flint_printf("Exception (fmpz_mat_solve_dixon_den). Non-square system matrix.\n");
        flint_abort();
    }

    if (fmpz_mat_is_empty(A) || fmpz_mat_is_empty(B))
        return 1;

    fmpz_init(N);
    fmpz_init(D);
    fmpz_mat_solve_bound(N, D, A, B);

    nmod_mat_init(Ainv, A->r, A->r, 1);
    p = fmpz_mat_find_good_prime_and_invert(Ainv, A, D);
    if (p != 0)
        _fmpz_mat_solve_dixon_den(X, den, A, B, Ainv, p, N, D);

    nmod_mat_clear(Ainv);
    fmpz_clear(N);
    fmpz_clear(D);

    return p != 0;
}
