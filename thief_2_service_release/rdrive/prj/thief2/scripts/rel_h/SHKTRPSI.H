/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shktrpsi.h 1.1 1998/12/12 18:00:33 XEMU Exp $

#ifndef __SHKTRPSI_H
#define __SHKTRPSI_H

#include <rect.h>

EXTERN void ShockBuyPsiInit(int which);
EXTERN void ShockBuyPsiTerm(void);
EXTERN void ShockBuyPsiDraw(void);
EXTERN bool ShockBuyPsiHandleMouse(Point pt);
EXTERN void ShockBuyPsiStateChange(int which);

#endif