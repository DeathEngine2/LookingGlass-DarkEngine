/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkscomp.h 1.1 1999/01/02 13:56:56 XEMU Exp $

#ifndef __SHKSCOMP_H
#define __SHKSCOMP_H

#include <objtype.h>
extern "C"
{
#include <event.h>
}

EXTERN void ShockSecCompInit(int which);
EXTERN void ShockSecCompTerm(void);
EXTERN void ShockSecCompDraw(void);
EXTERN void ShockSecCompStateChange(int which);

#endif