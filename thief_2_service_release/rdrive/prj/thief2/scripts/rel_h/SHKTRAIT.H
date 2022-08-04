/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shktrait.h 1.2 1998/11/23 15:57:56 XEMU Exp $

#ifndef __SHKTRAIT_H
#define __SHKTRAIT_H

#include <rect.h>

extern "C"
{
#include <event.h>
}

typedef enum eTrait;

EXTERN void ShockTraitInit(int which);
EXTERN void ShockTraitTerm(void);
EXTERN void ShockTraitDraw(void);
EXTERN bool ShockTraitHandleMouse(Point pt);
EXTERN void ShockTraitStateChange(int which);
EXTERN bool ShockTraitCheckTransp(Point pt);
EXTERN void ShockTraitDrawIcon(eTrait which, int dx, int dy);


#endif