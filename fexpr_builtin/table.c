/*
    Copyright (C) 2021 Fredrik Johansson

    This file is part of Calcium.

    Calcium is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#include "fexpr.h"
#include "fexpr_builtin.h"

const fexpr_symbol_info fexpr_builtin_table[FEXPR_BUILTIN_LENGTH] = {
    { FEXPR_AGM, "AGM", "\\operatorname{agm}", NULL, },
    { FEXPR_Abs, "Abs", "", fexpr_write_latex_simple, },
    { FEXPR_Acos, "Acos", "\\operatorname{acos}", NULL, },
    { FEXPR_Acosh, "Acosh", "\\operatorname{acosh}", NULL, },
    { FEXPR_Acot, "Acot", "\\operatorname{acot}", NULL, },
    { FEXPR_Acoth, "Acoth", "\\operatorname{acoth}", NULL, },
    { FEXPR_Acsc, "Acsc", "\\operatorname{acsc}", NULL, },
    { FEXPR_Acsch, "Acsch", "\\operatorname{acsch}", NULL, },
    { FEXPR_Add, "Add", "", fexpr_write_latex_add, },
    { FEXPR_AiryAi, "AiryAi", "", NULL, },
    { FEXPR_AiryAiZero, "AiryAiZero", "", NULL, },
    { FEXPR_AiryBi, "AiryBi", "", NULL, },
    { FEXPR_AiryBiZero, "AiryBiZero", "", NULL, },
    { FEXPR_AlgebraicNumbers, "AlgebraicNumbers", "\\overline{\\mathbb{Q}}", NULL, },
    { FEXPR_All, "All", "", NULL, },
    { FEXPR_And, "And", "", fexpr_write_latex_logic, },
    { FEXPR_AngleBrackets, "AngleBrackets", "", fexpr_write_latex_simple, },
    { FEXPR_Arg, "Arg", "\\arg", NULL, },
    { FEXPR_ArgMax, "ArgMax", "", NULL, },
    { FEXPR_ArgMaxUnique, "ArgMaxUnique", "", NULL, },
    { FEXPR_ArgMin, "ArgMin", "", NULL, },
    { FEXPR_ArgMinUnique, "ArgMinUnique", "", NULL, },
    { FEXPR_Asec, "Asec", "\\operatorname{asec}", NULL, },
    { FEXPR_Asech, "Asech", "\\operatorname{asech}", NULL, },
    { FEXPR_Asin, "Asin", "\\operatorname{asin}", NULL, },
    { FEXPR_Asinh, "Asinh", "\\operatorname{asinh}", NULL, },
    { FEXPR_Atan, "Atan", "\\operatorname{atan}", NULL, },
    { FEXPR_Atan2, "Atan2", "\\operatorname{atan2}", NULL, },
    { FEXPR_Atanh, "Atanh", "\\operatorname{atanh}", NULL, },
    { FEXPR_BarnesG, "BarnesG", "G", NULL, },
    { FEXPR_BellNumber, "BellNumber", "\\operatorname{B}", fexpr_write_latex_subscript, },
    { FEXPR_BernoulliB, "BernoulliB", "B", fexpr_write_latex_subscript, },
    { FEXPR_BernoulliPolynomial, "BernoulliPolynomial", "", NULL, },
    { FEXPR_BesselI, "BesselI", "I", fexpr_write_latex_subscript_call, },
    { FEXPR_BesselJ, "BesselJ", "J", fexpr_write_latex_subscript_call, },
    { FEXPR_BesselJZero, "BesselJZero", "", NULL, },
    { FEXPR_BesselK, "BesselK", "K", fexpr_write_latex_subscript_call, },
    { FEXPR_BesselY, "BesselY", "Y", fexpr_write_latex_subscript_call, },
    { FEXPR_BesselYZero, "BesselYZero", "", NULL, },
    { FEXPR_BetaFunction, "BetaFunction", "\\mathrm{B}", NULL, },
    { FEXPR_Binomial, "Binomial", "", fexpr_write_latex_simple2, },
    { FEXPR_Braces, "Braces", "", fexpr_write_latex_simple, },
    { FEXPR_Brackets, "Brackets", "", fexpr_write_latex_simple, },
    { FEXPR_CC, "CC", "\\mathbb{C}", NULL, },
    { FEXPR_Cardinality, "Cardinality", "", fexpr_write_latex_simple, },
    { FEXPR_CarlsonRC, "CarlsonRC", "R_C", NULL, },
    { FEXPR_CarlsonRD, "CarlsonRD", "R_D", NULL, },
    { FEXPR_CarlsonRF, "CarlsonRF", "R_F", NULL, },
    { FEXPR_CarlsonRG, "CarlsonRG", "R_G", NULL, },
    { FEXPR_CarlsonRJ, "CarlsonRJ", "R_J", NULL, },
    { FEXPR_CartesianPower, "CartesianPower", "", NULL, },
    { FEXPR_CartesianProduct, "CartesianProduct", "", NULL, },
    { FEXPR_Case, "Case", "", NULL, },
    { FEXPR_Cases, "Cases", "", NULL, },
    { FEXPR_CatalanConstant, "CatalanConstant", "G", NULL, },
    { FEXPR_Ceil, "Ceil", "", fexpr_write_latex_simple, },
    { FEXPR_Characteristic, "Characteristic", "\\operatorname{char}", NULL, },
    { FEXPR_ChebyshevT, "ChebyshevT", "", NULL, },
    { FEXPR_ChebyshevU, "ChebyshevU", "", NULL, },
    { FEXPR_ClosedComplexDisk, "ClosedComplexDisk", "\\overline{D}", NULL, },
    { FEXPR_ClosedOpenInterval, "ClosedOpenInterval", "", fexpr_write_latex_simple2_small, },
    { FEXPR_Coefficient, "Coefficient", "", NULL, },
    { FEXPR_CommutativeRings, "CommutativeRings", "", NULL, },
    { FEXPR_ComplexBranchDerivative, "ComplexBranchDerivative", "", NULL, },
    { FEXPR_ComplexDerivative, "ComplexDerivative", "", NULL, },
    { FEXPR_ComplexInfinities, "ComplexInfinities", "", NULL, },
    { FEXPR_ComplexLimit, "ComplexLimit", "", NULL, },
    { FEXPR_ComplexSignedInfinities, "ComplexSignedInfinities", "", NULL, },
    { FEXPR_ComplexSingularityClosure, "ComplexSingularityClosure", "", NULL, },
    { FEXPR_Concatenation, "Concatenation", " \\,^\\frown ", fexpr_write_latex_infix, },
    { FEXPR_CongruentMod, "CongruentMod", "", NULL, },
    { FEXPR_Conjugate, "Conjugate", "", fexpr_write_latex_simple, },
    { FEXPR_ConreyGenerator, "ConreyGenerator", "g", fexpr_write_latex_subscript, },
    { FEXPR_Cos, "Cos", "\\cos", NULL, },
    { FEXPR_Cosh, "Cosh", "\\cosh", NULL, },
    { FEXPR_Cot, "Cot", "\\cot", NULL, },
    { FEXPR_Coth, "Coth", "\\coth", NULL, },
    { FEXPR_CoulombC, "CoulombC", "", NULL, },
    { FEXPR_CoulombF, "CoulombF", "", NULL, },
    { FEXPR_CoulombG, "CoulombG", "", NULL, },
    { FEXPR_CoulombH, "CoulombH", "", NULL, },
    { FEXPR_CoulombSigma, "CoulombSigma", "", NULL, },
    { FEXPR_Csc, "Csc", "\\csc", NULL, },
    { FEXPR_Csch, "Csch", "\\operatorname{csch}", NULL, },
    { FEXPR_Csgn, "Csgn", "\\operatorname{csgn}", NULL, },
    { FEXPR_Cyclotomic, "Cyclotomic", "", NULL, },
    { FEXPR_Decimal, "Decimal", "", NULL, },
    { FEXPR_DedekindEta, "DedekindEta", "\\eta", NULL, },
    { FEXPR_DedekindEtaEpsilon, "DedekindEtaEpsilon", "\\varepsilon", NULL, },
    { FEXPR_DedekindSum, "DedekindSum", "s", NULL, },
    { FEXPR_Def, "Def", "", NULL, },
    { FEXPR_Delta, "Delta", "\\Delta", NULL },
    { FEXPR_Delta_, "Delta_", "\\Delta", fexpr_write_latex_subscript },
    { FEXPR_Derivative, "Derivative", "", NULL, },
    { FEXPR_Det, "Det", "\\operatorname{det}", NULL, },
    { FEXPR_DigammaFunction, "DigammaFunction", "\\psi", NULL, },
    { FEXPR_DigammaFunctionZero, "DigammaFunctionZero", "x", fexpr_write_latex_subscript, },
    { FEXPR_DirichletCharacter, "DirichletCharacter", "", NULL, },
    { FEXPR_DirichletGroup, "DirichletGroup", "G", fexpr_write_latex_subscript, },
    { FEXPR_DirichletL, "DirichletL", "L", NULL, },
    { FEXPR_DirichletLZero, "DirichletLZero", "", NULL, },
    { FEXPR_DirichletLambda, "DirichletLambda", "\\Lambda", NULL, },
    { FEXPR_DiscreteLog, "DiscreteLog", "", NULL, },
    { FEXPR_Div, "Div", "", fexpr_write_latex_div, },
    { FEXPR_Divides, "Divides", "\\mid", fexpr_write_latex_infix, },
    { FEXPR_DivisorProduct, "DivisorProduct", "", NULL, },
    { FEXPR_DivisorSigma, "DivisorSigma", "", NULL, },
    { FEXPR_DivisorSum, "DivisorSum", "", NULL, },
    { FEXPR_DoubleFactorial, "DoubleFactorial", "", fexpr_write_latex_factorial, },
    { FEXPR_EisensteinE, "EisensteinE", "", NULL, },
    { FEXPR_EisensteinG, "EisensteinG", "", NULL, },
    { FEXPR_Element, "Element", "\\in", fexpr_write_latex_infix, },
    { FEXPR_Ellipsis, "Ellipsis", "\\ldots", NULL, },
    { FEXPR_EllipticE, "EllipticE", "E", NULL, },
    { FEXPR_EllipticK, "EllipticK", "K", NULL, },
    { FEXPR_EllipticPi, "EllipticPi", "\\Pi", NULL, },
    { FEXPR_Equal, "Equal", "=", fexpr_write_latex_infix, },
    { FEXPR_Equivalent, "Equivalent", "", fexpr_write_latex_logic, },
    { FEXPR_Erf, "Erf", "\\operatorname{erf}", NULL, },
    { FEXPR_Erfc, "Erfc", "\\operatorname{erfc}", NULL, },
    { FEXPR_Erfi, "Erfi", "\\operatorname{erfi}", NULL, },
    { FEXPR_Euler, "Euler", "\\gamma", NULL, },
    { FEXPR_EulerE, "EulerE", "E", fexpr_write_latex_subscript, },
    { FEXPR_EulerPhi, "EulerPhi", "\\varphi", NULL, },
    { FEXPR_EulerPolynomial, "EulerPolynomial", "", NULL, },
    { FEXPR_EulerQSeries, "EulerQSeries", "\\phi", NULL, },
    { FEXPR_Exists, "Exists", "", NULL, },
    { FEXPR_Exp, "Exp", "\\exp", fexpr_write_latex_exp, },
    { FEXPR_ExtendedRealNumbers, "ExtendedRealNumbers", "", NULL, },
    { FEXPR_Factorial, "Factorial", "", fexpr_write_latex_factorial, },
    { FEXPR_FallingFactorial, "FallingFactorial", "", fexpr_write_latex_simple2, },
    { FEXPR_False, "False", "\\operatorname{False}", NULL, },
    { FEXPR_Fibonacci, "Fibonacci", "F", fexpr_write_latex_subscript, },
    { FEXPR_Fields, "Fields", "", NULL, },
    { FEXPR_FiniteField, "FiniteField", "", NULL, },
    { FEXPR_Floor, "Floor", "", fexpr_write_latex_simple, },
    { FEXPR_For, "For", "", NULL, },
    { FEXPR_FormalLaurentSeries, "FormalLaurentSeries", "", fexpr_write_latex_alg_structure, },
    { FEXPR_FormalPowerSeries, "FormalPowerSeries", "", fexpr_write_latex_alg_structure, },
    { FEXPR_FormalPuiseuxSeries, "FormalPuiseuxSeries", "", fexpr_write_latex_alg_structure, },
    { FEXPR_Fun, "Fun", "", NULL, },
    { FEXPR_GCD, "GCD", "\\gcd", NULL, },
    { FEXPR_Gamma, "Gamma", "\\Gamma", NULL, },
    { FEXPR_GaussLegendreWeight, "GaussLegendreWeight", "", NULL, },
    { FEXPR_GaussSum, "GaussSum", "", NULL, },
    { FEXPR_GegenbauerC, "GegenbauerC", "", NULL, },
    { FEXPR_GeneralLinearGroup, "GeneralLinearGroup", "", NULL, },
    { FEXPR_GeneralizedBernoulliB, "GeneralizedBernoulliB", "", NULL, },
    { FEXPR_GeneralizedRiemannHypothesis, "GeneralizedRiemannHypothesis", "\\operatorname{GRH}", NULL, },
    { FEXPR_GoldenRatio, "GoldenRatio", "\\varphi", NULL, },
    { FEXPR_Greater, "Greater", ">", fexpr_write_latex_infix, },
    { FEXPR_GreaterEqual, "GreaterEqual", "\\ge", fexpr_write_latex_infix, },
    { FEXPR_GreekGamma, "GreekGamma", "\\Gamma", NULL },
    { FEXPR_GreekGamma_, "GreekGamma_", "\\Gamma", fexpr_write_latex_subscript },
    { FEXPR_GreekPi, "GreekPi", "\\Pi", NULL },
    { FEXPR_GreekPi_, "GreekPi_", "\\Pi", fexpr_write_latex_subscript },
    { FEXPR_HankelH1, "HankelH1", "", NULL, },
    { FEXPR_HankelH2, "HankelH2", "", NULL, },
    { FEXPR_HarmonicNumber, "HarmonicNumber", "H", fexpr_write_latex_subscript, },
    { FEXPR_HermiteH, "HermiteH", "", NULL, },
    { FEXPR_HilbertClassPolynomial, "HilbertClassPolynomial", "", NULL, },
    { FEXPR_HilbertMatrix, "HilbertMatrix", "H", fexpr_write_latex_subscript, },
    { FEXPR_HurwitzZeta, "HurwitzZeta", "\\zeta", NULL, },
    { FEXPR_Hypergeometric0F1, "Hypergeometric0F1", "\\,{}_0F_1", NULL, },
    { FEXPR_Hypergeometric0F1Regularized, "Hypergeometric0F1Regularized", "\\,{}_0{\\textbf F}_1", NULL, },
    { FEXPR_Hypergeometric1F1, "Hypergeometric1F1", "\\,{}_1F_1", NULL, },
    { FEXPR_Hypergeometric1F1Regularized, "Hypergeometric1F1Regularized", "\\,{}_1{\\textbf F}_1", NULL, },
    { FEXPR_Hypergeometric1F2, "Hypergeometric1F2", "\\,{}_1F_2", NULL, },
    { FEXPR_Hypergeometric1F2Regularized, "Hypergeometric1F2Regularized", "\\,{}_1{\\textbf F}_2", NULL, },
    { FEXPR_Hypergeometric2F0, "Hypergeometric2F0", "\\,{}_2F_0", NULL, },
    { FEXPR_Hypergeometric2F1, "Hypergeometric2F1", "\\,{}_2F_1", NULL, },
    { FEXPR_Hypergeometric2F1Regularized, "Hypergeometric2F1Regularized", "\\,{}_2{\\textbf F}_1", NULL, },
    { FEXPR_Hypergeometric2F2, "Hypergeometric2F2", "\\,{}_2F_2", NULL, },
    { FEXPR_Hypergeometric2F2Regularized, "Hypergeometric2F2Regularized", "\\,{}_2{\\textbf F}_2", NULL, },
    { FEXPR_Hypergeometric3F2, "Hypergeometric3F2", "\\,{}_3F_2", NULL, },
    { FEXPR_Hypergeometric3F2Regularized, "Hypergeometric3F2Regularized", "\\,{}_3{\\textbf F}_2", NULL, },
    { FEXPR_HypergeometricU, "HypergeometricU", "U", NULL, },
    { FEXPR_HypergeometricUStar, "HypergeometricUStar", "U^{*}", NULL, },
    { FEXPR_IdentityMatrix, "IdentityMatrix", "I", fexpr_write_latex_subscript, },
    { FEXPR_Im, "Im", "", NULL, },
    { FEXPR_Implies, "Implies", "", fexpr_write_latex_logic, },
    { FEXPR_IncompleteBeta, "IncompleteBeta", "", NULL, },
    { FEXPR_IncompleteBetaRegularized, "IncompleteBetaRegularized", "", NULL, },
    { FEXPR_IncompleteEllipticE, "IncompleteEllipticE", "E", NULL, },
    { FEXPR_IncompleteEllipticF, "IncompleteEllipticF", "F", NULL, },
    { FEXPR_IncompleteEllipticPi, "IncompleteEllipticPi", "\\Pi", NULL, },
    { FEXPR_Infimum, "Infimum", "", NULL, },
    { FEXPR_Infinity, "Infinity", "\\infty", NULL, },
    { FEXPR_IntegersGreaterEqual, "IntegersGreaterEqual", "", NULL, },
    { FEXPR_IntegersLessEqual, "IntegersLessEqual", "", NULL, },
    { FEXPR_Integral, "Integral", "", fexpr_write_latex_integral, },
    { FEXPR_Intersection, "Intersection", "\\cap", fexpr_write_latex_infix, },
    { FEXPR_Interval, "Interval", "", fexpr_write_latex_simple2_small, },
    { FEXPR_IsEven, "IsEven", "", NULL, },
    { FEXPR_IsOdd, "IsOdd", "", NULL, },
    { FEXPR_IsPrime, "IsPrime", "", NULL, },
    { FEXPR_Item, "Item", "", NULL, },
    { FEXPR_JacobiP, "JacobiP", "", NULL, },
    { FEXPR_JacobiSymbol, "JacobiSymbol", "", fexpr_write_latex_simple2, },
    { FEXPR_JacobiTheta, "JacobiTheta", "", NULL, },
    { FEXPR_JacobiThetaEpsilon, "JacobiThetaEpsilon", "", NULL, },
    { FEXPR_JacobiThetaPermutation, "JacobiThetaPermutation", "", NULL, },
    { FEXPR_KeiperLiLambda, "KeiperLiLambda", "\\lambda", fexpr_write_latex_subscript, },
    { FEXPR_KroneckerDelta, "KroneckerDelta", "", fexpr_write_latex_simple2_small, },
    { FEXPR_KroneckerSymbol, "KroneckerSymbol", "", fexpr_write_latex_simple2, },
    { FEXPR_LCM, "LCM", "\\operatorname{lcm}", NULL, },
    { FEXPR_LaguerreL, "LaguerreL", "", NULL, },
    { FEXPR_LambertW, "LambertW", "", NULL, },
    { FEXPR_Lamda, "Lamda", "\\Lambda", NULL },
    { FEXPR_Lamda_, "Lamda_", "\\Lambda", fexpr_write_latex_subscript },
    { FEXPR_LandauG, "LandauG", "g", NULL, },
    { FEXPR_LeftLimit, "LeftLimit", "", NULL, },
    { FEXPR_LegendreP, "LegendreP", "", NULL, },
    { FEXPR_LegendrePolynomialZero, "LegendrePolynomialZero", "", NULL, },
    { FEXPR_LegendreSymbol, "LegendreSymbol", "", fexpr_write_latex_simple2, },
    { FEXPR_Length, "Length", "", fexpr_write_latex_simple, },
    { FEXPR_LerchPhi, "LerchPhi", "\\Phi", NULL, },
    { FEXPR_Less, "Less", "<", fexpr_write_latex_infix, },
    { FEXPR_LessEqual, "LessEqual", "\\le", fexpr_write_latex_infix, },
    { FEXPR_Limit, "Limit", "", NULL, },
    { FEXPR_LiouvilleLambda, "LiouvilleLambda", "\\lambda", NULL, },
    { FEXPR_List, "List", "", fexpr_write_latex_collection, },
    { FEXPR_Log, "Log", "\\log", NULL, },
    { FEXPR_LogBarnesG, "LogBarnesG", "\\log G", NULL, },
    { FEXPR_LogGamma, "LogGamma", "\\log \\Gamma", NULL, },
    { FEXPR_LogIntegral, "LogIntegral", "\\operatorname{li}", NULL, },
    { FEXPR_LowerGamma, "LowerGamma", "\\gamma", NULL, },
    { FEXPR_Matrices, "Matrices", "", NULL, },
    { FEXPR_Matrix, "Matrix", "", NULL, },
    { FEXPR_Matrix2x1, "Matrix2x1", "", NULL, },
    { FEXPR_Matrix2x2, "Matrix2x2", "", NULL, },
    { FEXPR_Max, "Max", "\\max", NULL, },
    { FEXPR_Maximum, "Maximum", "", NULL, },
    { FEXPR_MeromorphicDerivative, "MeromorphicDerivative", "", NULL, },
    { FEXPR_MeromorphicLimit, "MeromorphicLimit", "", NULL, },
    { FEXPR_Min, "Min", "\\min", NULL, },
    { FEXPR_Minimum, "Minimum", "", NULL, },
    { FEXPR_Mod, "Mod", "\\bmod", fexpr_write_latex_infix, },
    { FEXPR_ModularGroupAction, "ModularGroupAction", "", NULL, },
    { FEXPR_ModularGroupFundamentalDomain, "ModularGroupFundamentalDomain", "\\mathcal{F}", NULL, },
    { FEXPR_ModularJ, "ModularJ", "j", NULL, },
    { FEXPR_ModularLambda, "ModularLambda", "\\lambda", NULL, },
    { FEXPR_ModularLambdaFundamentalDomain, "ModularLambdaFundamentalDomain", "\\mathcal{F}_{\\lambda}", NULL, },
    { FEXPR_MoebiusMu, "MoebiusMu", "\\mu", NULL, },
    { FEXPR_Mul, "Mul", "", fexpr_write_latex_mul, },
    { FEXPR_MultiZetaValue, "MultiZetaValue", "\\zeta", NULL, },
    { FEXPR_NN, "NN", "\\mathbb{N}", NULL, },
    { FEXPR_Neg, "Neg", "", fexpr_write_latex_neg_pos, },
    { FEXPR_Not, "Not", "", fexpr_write_latex_logic, },
    { FEXPR_NotElement, "NotElement", "\\notin", fexpr_write_latex_infix, },
    { FEXPR_NotEqual, "NotEqual", "\\ne", fexpr_write_latex_infix, },
    { FEXPR_NumberE, "NumberE", "e", NULL, },
    { FEXPR_NumberI, "NumberI", "i", NULL, },
    { FEXPR_Omega, "Omega", "\\Omega", NULL },
    { FEXPR_Omega_, "Omega_", "\\Omega", fexpr_write_latex_subscript },
    { FEXPR_One, "One", "1", fexpr_write_latex_subscript, },
    { FEXPR_OpenClosedInterval, "OpenClosedInterval", "", fexpr_write_latex_simple2_small, },
    { FEXPR_OpenComplexDisk, "OpenComplexDisk", "D", NULL, },
    { FEXPR_OpenInterval, "OpenInterval", "", fexpr_write_latex_simple2_small, },
    { FEXPR_OpenRealBall, "OpenRealBall", "", fexpr_write_latex_simple2_small, },
    { FEXPR_Or, "Or", "", fexpr_write_latex_logic, },
    { FEXPR_Otherwise, "Otherwise", "", NULL, },
    { FEXPR_Parentheses, "Parentheses", "", fexpr_write_latex_simple, },
    { FEXPR_PartitionsP, "PartitionsP", "p", NULL, },
    { FEXPR_Path, "Path", "\\rightsquigarrow", fexpr_write_latex_infix, },
    { FEXPR_Phi, "Phi", "\\Phi", NULL },
    { FEXPR_Phi_, "Phi_", "\\Phi", fexpr_write_latex_subscript },
    { FEXPR_Pi, "Pi", "\\pi", NULL, },
    { FEXPR_Pol, "Pol", "", NULL, },
    { FEXPR_PolyLog, "PolyLog", "", NULL, },
    { FEXPR_PolynomialDegree, "PolynomialDegree", "\\deg", NULL, },
    { FEXPR_PolynomialFractions, "PolynomialFractions", "", fexpr_write_latex_alg_structure, },
    { FEXPR_Polynomials, "Polynomials", "", fexpr_write_latex_alg_structure, },
    { FEXPR_Pos, "Pos", "", fexpr_write_latex_neg_pos, },
    { FEXPR_Pow, "Pow", "", fexpr_write_latex_pow, },
    { FEXPR_Prime, "Prime", "p", fexpr_write_latex_subscript, },
    { FEXPR_PrimePi, "PrimePi", "\\pi", NULL, },
    { FEXPR_PrimeProduct, "PrimeProduct", "", NULL, },
    { FEXPR_PrimeSum, "PrimeSum", "", NULL, },
    { FEXPR_Primes, "Primes", "\\mathbb{P}", NULL, },
    { FEXPR_PrimitiveDirichletCharacters, "PrimitiveDirichletCharacters", "", NULL, },
    { FEXPR_PrimitiveReducedPositiveIntegralBinaryQuadraticForms, "PrimitiveReducedPositiveIntegralBinaryQuadraticForms", "", NULL, },
    { FEXPR_Product, "Product", "", fexpr_write_latex_sum_product, },
    { FEXPR_ProjectiveComplexNumbers, "ProjectiveComplexNumbers", "", NULL, },
    { FEXPR_ProjectiveRealNumbers, "ProjectiveRealNumbers", "", NULL, },
    { FEXPR_Psi, "Psi", "\\Psi", NULL },
    { FEXPR_Psi_, "Psi_", "\\Psi", fexpr_write_latex_subscript },
    { FEXPR_QQ, "QQ", "\\mathbb{Q}", NULL, },
    { FEXPR_QuotientRing, "QuotientRing", "", NULL, },
    { FEXPR_RR, "RR", "\\mathbb{R}", NULL, },
    { FEXPR_Range, "Range", "", NULL, },
    { FEXPR_Re, "Re", "", NULL, },
    { FEXPR_RealAbs, "RealAbs", "", fexpr_write_latex_simple, },
    { FEXPR_RealAlgebraicNumbers, "RealAlgebraicNumbers", "", NULL, },
    { FEXPR_RealBall, "RealBall", "", fexpr_write_latex_simple2_small, },
    { FEXPR_RealDerivative, "RealDerivative", "", NULL, },
    { FEXPR_RealInfinities, "RealInfinities", "", NULL, },
    { FEXPR_RealLimit, "RealLimit", "", NULL, },
    { FEXPR_RealSignedInfinities, "RealSignedInfinities", "", NULL, },
    { FEXPR_RealSingularityClosure, "RealSingularityClosure", "", NULL, },
    { FEXPR_RiemannHypothesis, "RiemannHypothesis", "\\operatorname{RH}", NULL, },
    { FEXPR_RiemannXi, "RiemannXi", "\\xi", NULL, },
    { FEXPR_RiemannZeta, "RiemannZeta", "\\zeta", NULL, },
    { FEXPR_RiemannZetaZero, "RiemannZetaZero", "\\rho", fexpr_write_latex_subscript, },
    { FEXPR_RightLimit, "RightLimit", "", NULL, },
    { FEXPR_Rings, "Rings", "", NULL, },
    { FEXPR_RisingFactorial, "RisingFactorial", "", fexpr_write_latex_simple2, },
    { FEXPR_Root, "Root", "", NULL, },
    { FEXPR_RootOfUnity, "RootOfUnity", "", NULL, },
    { FEXPR_SL2Z, "SL2Z", "\\operatorname{SL}_2(\\mathbb{Z})", NULL, },
    { FEXPR_Sec, "Sec", "\\sec", NULL, },
    { FEXPR_Sech, "Sech", "\\operatorname{sech}", NULL, },
    { FEXPR_SequenceLimit, "SequenceLimit", "", NULL, },
    { FEXPR_SequenceLimitInferior, "SequenceLimitInferior", "", NULL, },
    { FEXPR_SequenceLimitSuperior, "SequenceLimitSuperior", "", NULL, },
    { FEXPR_Ser, "Ser", "", NULL, },
    { FEXPR_Set, "Set", "", fexpr_write_latex_collection, },
    { FEXPR_SetMinus, "SetMinus", "\\setminus", fexpr_write_latex_infix, },
    { FEXPR_Sets, "Sets", "", NULL, },
    { FEXPR_Sigma, "Sigma", "\\Sigma", NULL },
    { FEXPR_Sigma_, "Sigma_", "\\Sigma", fexpr_write_latex_subscript },
    { FEXPR_Sign, "Sign", "\\operatorname{sgn}", NULL, },
    { FEXPR_SignExtendedComplexNumbers, "SignExtendedComplexNumbers", "", NULL, },
    { FEXPR_Sin, "Sin", "\\sin", NULL, },
    { FEXPR_SinIntegral, "SinIntegral", "\\operatorname{Si}", NULL, },
    { FEXPR_Sinc, "Sinc", "\\operatorname{sinc}", NULL, },
    { FEXPR_SingularValues, "SingularValues", "\\sigma", NULL, },
    { FEXPR_Sinh, "Sinh", "\\sinh", NULL, },
    { FEXPR_Solutions, "Solutions", "", NULL, },
    { FEXPR_SpecialLinearGroup, "SpecialLinearGroup", "", NULL, },
    { FEXPR_Spectrum, "Spectrum", "\\operatorname{spec}", NULL, },
    { FEXPR_SphericalHarmonicY, "SphericalHarmonicY", "", NULL, },
    { FEXPR_Sqrt, "Sqrt", "", fexpr_write_latex_simple, },
    { FEXPR_SquaresR, "SquaresR", "", NULL, },
    { FEXPR_StieltjesGamma, "StieltjesGamma", "", NULL, },
    { FEXPR_StirlingCycle, "StirlingCycle", "", fexpr_write_latex_simple2, },
    { FEXPR_StirlingS1, "StirlingS1", "", fexpr_write_latex_simple2, },
    { FEXPR_StirlingS2, "StirlingS2", "", fexpr_write_latex_simple2, },
    { FEXPR_Sub, "Sub", "", fexpr_write_latex_sub, },
    { FEXPR_Subset, "Subset", "\\subset", fexpr_write_latex_infix, },
    { FEXPR_SubsetEqual, "SubsetEqual", "\\subseteq", fexpr_write_latex_infix, },
    { FEXPR_Subsets, "Subsets", "\\mathscr{P}", NULL, },
    { FEXPR_Sum, "Sum", "", fexpr_write_latex_sum_product, },
    { FEXPR_Supremum, "Supremum", "", NULL, },
    { FEXPR_SymmetricPolynomial, "SymmetricPolynomial", "", NULL, },
    { FEXPR_Tan, "Tan", "\\tan", NULL, },
    { FEXPR_Tanh, "Tanh", "\\tanh", NULL, },
    { FEXPR_Theta, "Theta", "\\Theta", NULL },
    { FEXPR_Theta_, "Theta_", "\\Theta", fexpr_write_latex_subscript },
    { FEXPR_True, "True", "\\operatorname{True}", NULL, },
    { FEXPR_Tuple, "Tuple", "", fexpr_write_latex_collection, },
    { FEXPR_Tuples, "Tuples", "", NULL, },
    { FEXPR_Undefined, "Undefined", "", NULL, },
    { FEXPR_Union, "Union", "\\cup", fexpr_write_latex_infix, },
    { FEXPR_UniqueSolution, "UniqueSolution", "", NULL, },
    { FEXPR_UniqueZero, "UniqueZero", "", NULL, },
    { FEXPR_UnsignedInfinity, "UnsignedInfinity", "{\\tilde \\infty}", NULL, },
    { FEXPR_UpperGamma, "UpperGamma", "\\Gamma", NULL, },
    { FEXPR_UpperHalfPlane, "UpperHalfPlane", "\\mathbb{H}", NULL, },
    { FEXPR_WeierstrassP, "WeierstrassP", "\\wp", NULL, },
    { FEXPR_WeierstrassSigma, "WeierstrassSigma", "\\sigma", NULL, },
    { FEXPR_WeierstrassZeta, "WeierstrassZeta", "\\zeta", NULL, },
    { FEXPR_Where, "Where", "", NULL, },
    { FEXPR_XGCD, "XGCD", "\\operatorname{xgcd}", NULL, },
    { FEXPR_Xi, "Xi", "\\Xi", NULL },
    { FEXPR_Xi_, "Xi_", "\\Xi", fexpr_write_latex_subscript },
    { FEXPR_ZZ, "ZZ", "\\mathbb{Z}", NULL, },
    { FEXPR_Zero, "Zero", "0", fexpr_write_latex_subscript, },
    { FEXPR_ZeroMatrix, "ZeroMatrix", "0", fexpr_write_latex_subscript, },
    { FEXPR_Zeros, "Zeros", "", NULL, },
    { FEXPR_alpha, "alpha", "\\alpha", NULL },
    { FEXPR_alpha_, "alpha_", "\\alpha", fexpr_write_latex_subscript },
    { FEXPR_beta, "beta", "\\beta", NULL },
    { FEXPR_beta_, "beta_", "\\beta", fexpr_write_latex_subscript },
    { FEXPR_chi, "chi", "\\chi", NULL },
    { FEXPR_chi_, "chi_", "\\chi", fexpr_write_latex_subscript },
    { FEXPR_delta, "delta", "\\delta", NULL },
    { FEXPR_delta_, "delta_", "\\delta", fexpr_write_latex_subscript },
    { FEXPR_ell, "ell", "\\ell", NULL },
    { FEXPR_ell_, "ell_", "\\ell", fexpr_write_latex_subscript },
    { FEXPR_epsilon, "epsilon", "\\varepsilon", NULL },
    { FEXPR_epsilon_, "epsilon_", "\\varepsilon", fexpr_write_latex_subscript },
    { FEXPR_eta, "eta", "\\eta", NULL },
    { FEXPR_eta_, "eta_", "\\eta", fexpr_write_latex_subscript },
    { FEXPR_gamma, "gamma", "\\gamma", NULL },
    { FEXPR_gamma_, "gamma_", "\\gamma", fexpr_write_latex_subscript },
    { FEXPR_iota, "iota", "\\iota", NULL },
    { FEXPR_iota_, "iota_", "\\iota", fexpr_write_latex_subscript },
    { FEXPR_kappa, "kappa", "\\kappa", NULL },
    { FEXPR_kappa_, "kappa_", "\\kappa", fexpr_write_latex_subscript },
    { FEXPR_lamda, "lamda", "\\lambda", NULL },
    { FEXPR_lamda_, "lamda_", "\\lambda", fexpr_write_latex_subscript },
    { FEXPR_mu, "mu", "\\mu", NULL },
    { FEXPR_mu_, "mu_", "\\mu", fexpr_write_latex_subscript },
    { FEXPR_nu, "nu", "\\nu", NULL },
    { FEXPR_nu_, "nu_", "\\nu", fexpr_write_latex_subscript },
    { FEXPR_omega, "omega", "\\omega", NULL },
    { FEXPR_omega_, "omega_", "\\omega", fexpr_write_latex_subscript },
    { FEXPR_phi, "phi", "\\phi", NULL },
    { FEXPR_phi_, "phi_", "\\phi", fexpr_write_latex_subscript },
    { FEXPR_pi, "pi", "\\pi", NULL },
    { FEXPR_pi_, "pi_", "\\pi", fexpr_write_latex_subscript },
    { FEXPR_rho, "rho", "\\rho", NULL },
    { FEXPR_rho_, "rho_", "\\rho", fexpr_write_latex_subscript },
    { FEXPR_sigma, "sigma", "\\sigma", NULL },
    { FEXPR_sigma_, "sigma_", "\\sigma", fexpr_write_latex_subscript },
    { FEXPR_tau, "tau", "\\tau", NULL },
    { FEXPR_tau_, "tau_", "\\tau", fexpr_write_latex_subscript },
    { FEXPR_theta, "theta", "\\theta", NULL },
    { FEXPR_theta_, "theta_", "\\theta", fexpr_write_latex_subscript },
    { FEXPR_varphi, "varphi", "\\varphi", NULL },
    { FEXPR_varphi_, "varphi_", "\\varphi", fexpr_write_latex_subscript },
    { FEXPR_vartheta, "vartheta", "\\vartheta", NULL },
    { FEXPR_vartheta_, "vartheta_", "\\vartheta", fexpr_write_latex_subscript },
    { FEXPR_xi, "xi", "\\xi", NULL },
    { FEXPR_xi_, "xi_", "\\xi", fexpr_write_latex_subscript },
    { FEXPR_zeta, "zeta", "\\zeta", NULL },
    { FEXPR_zeta_, "zeta_", "\\zeta", fexpr_write_latex_subscript },
};



/*
document: 

missing:
    UnitCircle: "\\mathbb{T}",
    Ellipsis: "\\ldots",
    PSL2Z: "\\operatorname{PSL}_2(\\mathbb{Z})",
    RationalFunctionDegree: "\\deg",
    ZZp: "\\mathbb{Z}",
    QQp: "\\mathbb{Q}",

todo: regular calls:
    derivative for RiemannZeta, HurwitzZeta, ...
    todo: subcall, derivative ...
        HankelH1: "H^{(1)}",
        HankelH2: "H^{(2)}",
        AiryAi: "\\operatorname{Ai}",
        AiryBi: "\\operatorname{Bi}",
        AiryAiZero: "a",
        AiryBiZero: "b",
        BesselJZero: "j",
        BesselYZero: "y",


infix_latex_table = {
    Mod: "\\bmod",
    Element: "\\in",
    NotElement: "\\notin",
    SetMinus: "\\setminus",
    Union: "\\cup",
    Intersection: "\\cap",
    Less: "<",
    LessEqual: "\\le",
    Greater: ">",
    GreaterEqual: "\\ge",
    Equal: "=",
    NotEqual: "\\ne",
    Subset: "\\subset",
    SubsetEqual: "\\subseteq",
    Divides: "\\mid",
    Path: "\\rightsquigarrow",
}

subscript_latex_table = {
    BellNumber: "B",
    BernoulliB: "B",
    ConreyGenerator: "g",
    DigammaFunctionZero: "x",
    DirichletGroup: "G",
    EulerE: "E",
    Fibonacci: "F",
    HarmonicNumber: "H",
    HilbertMatrix: "H",
    IdentityMatrix: "I",
    KeiperLiLambda: "\\lambda",
    One: "1",
    PrimeNumber: "p",
    RiemannZetaZero: "\\rho",
    Zero: "0",
    ZeroMatrix: "0",
}

subscript_pair_latex_table = {
    DirichletLZero: "\\rho",
    LegendrePolynomialZero: "x",
    GaussLegendreWeight: "w",
    GeneralizedBernoulliB: "B",
    BesselJZero: "j",
    BesselYZero: "y",
}

subscript_call_latex_table = {
    BernoulliPolynomial: "B",
    EulerPolynomial: "E",
    LegendrePolynomial: "P",
    ChebyshevT: "T",
    ChebyshevU: "U",
    HermitePolynomial: "H",
    HilbertClassPolynomial: "H",
    EisensteinG: "G",
    EisensteinE: "E",
    DivisorSigma: "\\sigma",
    IncompleteBeta: "\\mathrm{B}",
    IncompleteBetaRegularized: "I",
    PolyLog: "\\operatorname{Li}",
    JacobiThetaEpsilon: "\\varepsilon",
    JacobiThetaPermutation: "S",
#    JacobiTheta: "\\theta",
    SquaresR: "r",
    StirlingSeriesRemainder: "R",
    LogBarnesGRemainder: "R",
    GeneralLinearGroup: "\\operatorname{GL}",
    SpecialLinearGroup: "\\operatorname{SL}",
    Cyclotomic: "\\Phi",
    SymmetricPolynomial: "e",
    AGMSequence: "\\operatorname{agm}",
    CarlsonHypergeometricR: "R",
    CarlsonHypergeometricT: "T",
    EllipticInvariantG: "g",
    EllipticRootE: "e",
}

*/
