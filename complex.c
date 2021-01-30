/* Andre Augusto Giannotti Scota
 * andre.scota@gmail.com
 *
 * My Math Library
 *
 * MIT License
 *
 */

#pragma STDC FENV_ACCESS ON
#include <fenv.h>
#include <errno.h>
#include <math.h>

#include "complex.h"

#define __COMPLEX_CHECK_FLOATINGPOINT_OPERATION_DD_(__CFPO_FUNC_, __CFPO_RET_, __CFPO_A_ , __CFPO_B_) \
{                                                                                                     \
	errno = 0; feclearexcept(FE_ALL_EXCEPT);                                                           \
	__CFPO_RET_ = __CFPO_FUNC_(__CFPO_A_, __CFPO_B_);                                                  \
	if((errno != 0) || (fetestexcept(FE_ALL_EXCEPT) != 0)) return(COMPLEX_ERRO);                       \
}

int complexCartesianToPolar(complexCartesian_t *c, complexPolar_t *p)
{
	__COMPLEX_CHECK_FLOATINGPOINT_OPERATION_DD_(hypotf, p->radius, c->real, c->imaginary);
	__COMPLEX_CHECK_FLOATINGPOINT_OPERATION_DD_(atan2f, p->phase , c->real, c->imaginary);

	return(COMPLEX_OK);
}

#define __COMPLEX_CHECK_FLOATINGPOINT_OPERATION_D_(__CFPO_FUNC_, __CFPO_RET_, __CFPO_A_, __CFPO_B_) \
{                                                                                                   \
	errno = 0; feclearexcept(FE_ALL_EXCEPT);                                                         \
	__CFPO_RET_ = __CFPO_A_ * __CFPO_FUNC_(__CFPO_B_);                                               \
	if((errno != 0) || (fetestexcept(FE_ALL_EXCEPT) != 0)) return(COMPLEX_ERRO);                     \
}

int complexPolarToCartesian(complexPolar_t *p, complexCartesian_t *c)
{
	__COMPLEX_CHECK_FLOATINGPOINT_OPERATION_D_(cos, c->real     , p->radius, p->phase);
	__COMPLEX_CHECK_FLOATINGPOINT_OPERATION_D_(sin, c->imaginary, p->radius, p->phase);

	return(COMPLEX_OK);
}
