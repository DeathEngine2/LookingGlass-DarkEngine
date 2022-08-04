/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkhud.h 1.2 1999/05/19 20:26:50 XEMU Exp $

#ifndef __SHKHUD_H
#define __SHKHUD_H

#include <objtype.h>

EXTERN void ShockHUDDraw(void);
EXTERN void ShockHUDInit(int which);
EXTERN void ShockHUDTerm(void);
EXTERN void ShockHUDDrawRect(Rect r, ObjID o);

EXTERN void ShockHUDClear();

#endif