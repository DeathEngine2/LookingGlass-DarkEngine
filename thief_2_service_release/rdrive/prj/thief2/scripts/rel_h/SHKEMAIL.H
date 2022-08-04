/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkemail.h 1.5 1999/03/22 21:28:54 XEMU Exp $

#ifndef __SHKEMAIL_H
#define __SHKEMAIL_H

extern "C"
{
#include <event.h>
}

EXTERN void ShockEmailInit(int which);
EXTERN void ShockEmailTerm(void);
EXTERN void ShockEmailDraw(void);
EXTERN bool ShockEmailHandleMouse(Point pt);
EXTERN void ShockEmailStateChange(int which);
EXTERN bool ShockEmailCheckTransp(Point pt);

EXTERN void ShockEmailPlayAudio(char *artname);
EXTERN void ShockEmailStop(void);
EXTERN void ShockEmailDisplay(int mode, int level, int which, BOOL show_mfd);

EXTERN int ShockFindLogData(ObjID obj, int usetype, int *plevel, int *pwhich);
#endif