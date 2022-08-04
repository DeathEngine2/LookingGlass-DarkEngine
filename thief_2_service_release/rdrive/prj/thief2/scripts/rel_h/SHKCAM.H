/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/shkcam.h 1.1 1998/02/24 14:42:48 JON Exp $

#ifndef __SHKCAM_H
#define __SHKCAM_H

#include <matrixs.h>
#include <objtype.h>
#include <osystype.h>

void PlayerCameraSetLocation(const mxs_vector *pPos, const mxs_angvec *pAng);
BOOL PlayerCameraAttach(ObjID objID);
BOOL PlayerCameraAttach(const Label *pName);
BOOL PlayerCameraAttach(const char *pName);

#endif