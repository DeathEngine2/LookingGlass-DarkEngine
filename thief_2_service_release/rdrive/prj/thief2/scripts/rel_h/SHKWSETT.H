/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkwsett.h 1.2 1998/11/23 15:57:59 XEMU Exp $

#ifndef __SHKWSETT_H
#define __SHKWSETT_H

extern "C"
{
#include <event.h>
}
#include <objtype.h>

EXTERN void ShockSettingInit(int which);
EXTERN void ShockSettingTerm(void);
EXTERN void ShockSettingDraw(void);
EXTERN bool ShockSettingHandleMouse(Point pt);
EXTERN void ShockSettingStateChange(int which);

#endif