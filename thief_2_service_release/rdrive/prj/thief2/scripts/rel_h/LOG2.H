/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: x:/prj/tech/hsrc/RCS/log2.h 1.1 1999/03/09 14:03:21 JAEMZ Exp $

// Log2 and approximations.

#ifndef _LOG2_H
#define _LOG2_H
#pragma once

#include <math.h>

// Exact log2 of a number
// But this is lame.  Can someone inline asm it?  Should be doable.
inline float Log2(float f)
{
   return logf(f)/logf(2.0);
}

// Fast floor of a log2
inline int Log2Floor(float f)
{
   return ((*(ulong*)&f)>>23)-127;
}

// Gives a good approximation (8% accuracy) of a log2
inline float Log2Approx(float f)
{
   return (float)(*(long *)&f - 0x3F800000) * ((float)1.0/(float)(0x00800000));
}


// Takes the log2(pow(f,pow));
// Note that it's free with this algorithm if pow is constant!
inline float Log2Approx(float f,int pow)
{
   return (float)(*(long *)&f - 0x3F800000) * ((float)pow/(float)(0x00800000));
}



#endif
