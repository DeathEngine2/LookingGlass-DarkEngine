/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkhazrd.h 1.2 1998/10/27 15:19:33 XEMU Exp $

#ifndef __SHKHAZRD_H
#define __SHKHAZRD_H

extern "C" 
{
#include <event.h>
}

EXTERN void ShockRadDraw(void);
EXTERN void ShockRadInit(int which);
EXTERN void ShockRadTerm(void);

EXTERN void ShockPoisonDraw(void);
EXTERN void ShockPoisonInit(int which);
EXTERN void ShockPoisonTerm(void);
#endif