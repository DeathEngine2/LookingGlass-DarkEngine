/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/shktech.h 1.2 1998/02/27 17:22:32 XEMU Exp $

#ifndef __SHKTECH_H
#define __SHKTECH_H

#include <objtype.h>
extern "C"
{
#include <event.h>
}

EXTERN void ShockHackingInit(int which);
EXTERN void ShockHackingTerm(void);
EXTERN void ShockHackingDraw(void);
EXTERN bool ShockHackingHandleMouse(uiMouseEvent *mev);
EXTERN void ShockHackingStateChange(int which);
EXTERN void ShockHackingBegin(ObjID o);
EXTERN bool ShockHackingCheckTransp(Point pt);

#endif