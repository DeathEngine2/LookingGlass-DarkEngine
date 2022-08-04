/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shklooko.h 1.2 1998/11/23 15:56:39 XEMU Exp $

#ifndef __SHKLOOK_H
#define __SHKLOOK_H

extern "C"
{
#include <event.h>
}
#include <objtype.h>

EXTERN void ShockLookInit(int which);
EXTERN void ShockLookTerm(void);
EXTERN void ShockLookDraw(void);
EXTERN bool ShockLookHandleMouse(Point pt);
EXTERN void ShockLookStateChange(int which);
EXTERN bool ShockLookCheckTransp(Point pt);
EXTERN void ShockLookPopup(ObjID o); // , const char *text);
EXTERN void ShockLookCursor(void);

#endif