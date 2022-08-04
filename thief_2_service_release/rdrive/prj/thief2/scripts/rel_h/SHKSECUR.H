/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shksecur.h 1.1 1998/11/23 15:50:25 XEMU Exp $

#ifndef __SHKSECUR_H
#define __SHKSECUR_H

extern "C"
{
#include <event.h>
}

EXTERN void ShockSecurityInit(int which);
EXTERN void ShockSecurityTerm(void);
EXTERN void ShockSecurityDraw(void);
EXTERN bool ShockSecurityHandleMouse(Point pt);
EXTERN void ShockSecurityStateChange(int which);
EXTERN bool ShockSecurityCheckTransp(Point pos);

#endif