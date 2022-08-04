#ifndef __REAL_H
#define __REAL_H

#include <math.h>
typedef double real;

#define REAL_UNIT 1.0
#define REAL_UNIT_3 REAL_UNIT
#define real_make(i, f) \
   (((double )(i)) + ((double )(f))/65536.0)
#define fix_to_real(_x) (((double )(_x))/65536.0)

#define real_rint(_x) ((int )floor((_x)+0.5))
#define real_int(_x) ((int )floor(_x))

#define real_div(num, denom) ((num)/(denom))
#define real_div_16_16_3 real_div
#define real_div_3_16_3 real_div

#define real_mul(num, denom) ((num)*(denom))
#define real_mul_3_3_3 real_mul

#define __REAL_H
#endif
