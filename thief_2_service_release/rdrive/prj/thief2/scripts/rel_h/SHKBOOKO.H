/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkbooko.h 1.4 1998/11/23 15:55:35 XEMU Exp $

#ifndef __SHKBOOKO_H
#define __SHKBOOKO_H

extern "C"
{
#include <event.h>
}

EXTERN void ShockBookInit(int which);
EXTERN void ShockBookTerm(void);
EXTERN void ShockBookDraw(void);
EXTERN bool ShockBookHandleMouse(Point pos);
EXTERN void ShockBookStateChange(int which);

EXTERN void ShockBookDisplay(int level, int which);
#endif