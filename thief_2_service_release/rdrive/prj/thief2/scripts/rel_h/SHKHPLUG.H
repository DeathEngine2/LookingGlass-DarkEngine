/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkhplug.h 1.2 1999/02/25 22:58:59 XEMU Exp $

#ifndef __SHKHPLUG_H
#define __SHKHPLUG_H

#include <objtype.h>
extern "C"
{
#include <event.h>
}

EXTERN void ShockHRMPlugInit(int which);
EXTERN void ShockHRMPlugTerm(void);
EXTERN void ShockHRMPlugDraw(void);
EXTERN void ShockHRMPlugSetMode(int mode, ObjID obj, int bonus = 0);
EXTERN void ShockHRMPlugStateChange(int which);
EXTERN bool ShockHRMPlugCheckTransp(Point pt);

#endif