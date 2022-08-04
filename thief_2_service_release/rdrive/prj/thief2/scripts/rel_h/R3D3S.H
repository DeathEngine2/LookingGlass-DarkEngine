/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*
 * $Source: x:/prj/tech/libsrc/r3d3/RCS/r3d3s.h $
 * $Revision: 1.3 $
 * $Author: JAEMZ $
 * $Date: 1996/09/29 20:07:17 $
 *
 * Base structure and type definitions
 *
 */

#ifndef __R3D3S_H
#define __R3D3S_H

#ifdef __R3DS_H
echo Wait!  You've included r3ds.h, incompatible!  This is
echo r3d3s.h!
#endif

#ifdef __R3D_H
echo Wait!  You've included r3d.h, incompatible!  This is
echo r3d3s.h!
#endif


#include <grspoint.h>
#include <matrixs.h>

// The big guy himself.  This may change over time
// is currently 48 bytes long
typedef struct _r3s_point {
   mxs_vector p;
   ulong ccodes;
   grs_point grp;
   ulong handle;  // app handle for d3d/hardware
} r3s_point;

typedef r3s_point * r3s_phandle;

#endif // __R3DS_H
