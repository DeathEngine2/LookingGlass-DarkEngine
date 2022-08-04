/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkpsiif.h 1.5 1999/04/07 22:45:52 XEMU Exp $

#ifndef __SHKPSIIF_H
#define __SHKPSIIF_H

extern "C"
{
#include <event.h>
}

typedef enum ePsiPowers;

EXTERN void ShockPsiInit(int which);
EXTERN void ShockPsiTerm(void);
EXTERN void ShockPsiDraw(void);
EXTERN bool ShockPsiHandleMouse(Point pt);
EXTERN void ShockPsiStateChange(int which);
EXTERN bool ShockPsiCheckTransp(Point pt);
EXTERN void ShockDrawPsiIcon(ePsiPowers which, int dx, int dy, int kind);
EXTERN void ShockPsiRefocus(ePsiPowers power);

EXTERN ePsiPowers ShockPsiQuickbind(void);

EXTERN void ShockPsiIconInit(int which);
EXTERN void ShockPsiIconTerm(void);
EXTERN void ShockPsiIconDraw(void);

EXTERN ePsiPowers psi_levels[];
#endif