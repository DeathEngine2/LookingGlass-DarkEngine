/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkiface.h 1.11 1999/01/08 12:15:17 XEMU Exp $

#ifndef __SHKIFACE_H
#define __SHKIFACE_H

#include <objtype.h>

extern "C" 
{
#include <event.h>
}
   
// Draw the given string in the given color, with the cursor before
// character cursor. If cursor == -1, then no cursor is drawn:
EXTERN void ShockInterfaceDrawString(char *str, int color, int cursor);
EXTERN void ShockInterfaceDraw(void);
EXTERN void ShockInterfaceInit(int which);
EXTERN void ShockInterfaceTerm(void);
EXTERN bool ShockInterfaceHandleMouse(Point pos);
EXTERN bool ShockInterfaceCheckTransp(Point pt);
EXTERN void ShockInterfaceStateChange(int which);
EXTERN void ShockInterfaceMouseOver(ObjID o);

EXTERN void ShockMiniFrameDraw(void);
EXTERN void ShockMiniFrameInit(int which);
EXTERN void ShockMiniFrameTerm(void);

EXTERN ObjID g_ifaceFocusObj;
EXTERN BOOL gFocusTouched;
#endif
