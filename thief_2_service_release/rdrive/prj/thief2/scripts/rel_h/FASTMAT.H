/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * $Header: r:/prj/lib/src/fastmat/rcs/fastmat.h 1.21 1995/06/03 21:51:12 jaemz Exp $
 */

#ifndef __FASTMAT_H
#define __FASTMAT_H

#ifdef __cplusplus

#include "fixpp.h"

typedef Fixpoint Q;

void qfill3( Q c1, Q c2, Q c3, Q *vec );
void qfill2345( Q c1, Q c2, Q *vec );
void vecrotvec( Q *vec1, Q *vec2, Q *con1, Q *con2 );
void stuffvec( Q *c, Q *vec );
void drainvec( Q *c, Q *vec );
void clipvec( Q c, Q *vec );
void clipvec_nl( Q c, Q s, Q *vec );
void vecconstadd( Q c, Q *vec, Q *ans );
void vecconstsub( Q c, Q *vec, Q *ans );
void sincosvec( Q *vec, Q *sin, Q *cos );
void addvec( Q *vec1, Q *vec2, Q *ans );
void subvec( Q *vec1, Q *vec2, Q *ans );
void addmat( Q _mat1[][6], Q _mat2[][6], Q _ans[][6] );
void submat( Q _mat1[][6], Q _mat2[][6], Q _ans[][6] );

void printvec( ostream& os, Q *vec );
void printvec( Q *vec );
void printmat( ostream& os, Q mat[][6] );
void printmat( Q mat[][6] );

extern "C" {

void mult( Q mat[][6], Q *vec, Q *ans );
void scalevec( const Q &scale, Q *vec, Q *ans );
void mulvec( Q *vec1, Q *vec2, Q *ans );
void rotvec( Q *vec1, Q *vec2, const Q &c1, const Q &c2 );
Q dotp( Q *vec1, Q *vec2 );

#else

void mult( fix mat[][6], fix *vec, fix *ans );
void scalevec( fix *scale, fix *vec, fix *ans );
void mulvec( fix *vec1, fix *vec2, fix *ans );
void rotvec( fix *vec1, fix *vec2, fix *c1, fix *c2 );
fix dotp( fix *vec1, fix *vec2 );

#endif // !__cplusplus


// my apologies to the chef
#pragma aux mult parm [esi] [edi] [eax] modify exact [eax edx esi ecx edi ebx];
#pragma aux scalevec parm [ecx] [esi] [edi] modify exact [eax edx esi ecx edi];
#pragma aux mulvec parm [ecx] [esi] [edi] modify exact [eax edx esi ecx edi];
#pragma aux rotvec parm [esi] [edi] [ebx] [ecx] modify exact [eax edx esi ecx edi ebx];
#pragma aux dotp parm [esi] [edi] modify exact [eax ebx ecx edx esi edi]

#ifdef __cplusplus
}
#endif // !__cplusplus

#endif // !__FASTMAT_H

