/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkpsamp.h 1.2 1998/11/23 15:57:11 XEMU Exp $

#ifndef __SHKPSAMP_H
#define __SHKPSAMP_H

extern "C"
{
#include <event.h>
}

EXTERN void ShockPsiAmpInit(int which);
EXTERN void ShockPsiAmpTerm(void);
EXTERN void ShockPsiAmpDraw(void);
EXTERN bool ShockPsiAmpHandleMouse(Point pt);
EXTERN void ShockPsiAmpStateChange(int which);
EXTERN bool ShockPsiAmpCheckTransp(Point pt);

#endif