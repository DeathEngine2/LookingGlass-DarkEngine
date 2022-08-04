/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkcross.h 1.1 1998/09/29 22:13:46 XEMU Exp $

#ifndef __SHKCROSS_H
#define __SHKCROSS_H

#include <rect.h>

EXTERN void ShockCrosshairDraw(void);
EXTERN void ShockCrosshairInit(int which);
EXTERN void ShockCrosshairTerm(void);
EXTERN bool ShockCrosshairCheckTransp(Point pt);

#endif