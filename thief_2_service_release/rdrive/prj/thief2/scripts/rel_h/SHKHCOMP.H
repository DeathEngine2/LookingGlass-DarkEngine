/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkhcomp.h 1.1 1999/01/02 13:57:22 XEMU Exp $

#ifndef __SHKHCOMP_H
#define __SHKHCOMP_H

#include <objtype.h>
extern "C"
{
#include <event.h>
}

EXTERN void ShockComputerInit(int which);
EXTERN void ShockComputerTerm(void);
EXTERN void ShockComputerDraw(void);
EXTERN void ShockComputerStateChange(int which);

#endif