/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

//
//
//

#ifndef MPUTIL_H
#define MPUTIL_H

//

#include <stdlib.h>		// min() and max().

// I hate macros.
#define clamp(x, lower, upper)	min(max(x, lower), upper)

void build_ramp(float * ramp, int size);

//

#endif



