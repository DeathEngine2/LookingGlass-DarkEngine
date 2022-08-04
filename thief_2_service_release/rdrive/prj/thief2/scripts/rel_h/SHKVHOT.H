/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkvhot.h 1.4 1999/11/19 14:52:53 adurant Exp $

This file has been moved to gunvhot.h AMSD


#ifndef __SHKVHOT_H
#define __SHKVHOT_H

#include <matrixs.h>
#include <objtype.h>

// Get the location of a vhot, taking into account joint rotations
EXTERN void VHotGetRaw(mxs_vector *pLoc, ObjID objID, int vhotNum);
// Get the location of a vhot, taking into account joint rotations
EXTERN void VHotGetLoc(mxs_vector *pLoc, ObjID objID, int vhotNum);
// Get the raw vhot offset
EXTERN void VHotGetOffset(mxs_vector *pOffset, ObjID objID, int vhotNum);

#endif // __SHKVHOT_H
