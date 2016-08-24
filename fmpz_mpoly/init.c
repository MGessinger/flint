/*
    Copyright (C) 2016 William Hart

    This file is part of FLINT.

    FLINT is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#include <gmp.h>
#include <stdlib.h>
#include "flint.h"
#include "fmpz.h"
#include "fmpz_mpoly.h"

void fmpz_mpoly_init(fmpz_mpoly_t poly, fmpz_mpoly_ctx_t ctx)
{
   poly->coeffs = NULL;
   poly->exps = NULL;

   poly->alloc = 0;
   poly->length = 0;
}

void fmpz_mpoly_init2(fmpz_mpoly_t poly, slong alloc, fmpz_mpoly_ctx_t ctx)
{
   if (alloc != 0)
   {
      poly->coeffs = (fmpz *) flint_calloc(alloc, sizeof(fmpz));
      poly->exps   = (ulong *) flint_calloc(alloc*ctx->N, sizeof(ulong));
   } else
   {
      poly->coeffs = NULL;
      poly->exps = NULL;
   }

   poly->alloc = alloc;
   poly->length = 0;
}

