/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shktrain.h 1.1 1998/12/12 17:57:28 XEMU Exp $

#ifndef __SHKTRSTA_H
#define __SHKTRSTA_H

#include <rect.h>

EXTERN void ShockBuyStatsInit(int which);
EXTERN void ShockBuyTechInit(int which);
EXTERN void ShockBuyWeaponInit(int which);

EXTERN void ShockTrainingTerm(void);
EXTERN void ShockTrainingDraw(void);
EXTERN bool ShockTrainingHandleMouse(Point pt);

EXTERN void ShockBuyStatsStateChange(int which);
EXTERN void ShockBuyTechStateChange(int which);
EXTERN void ShockBuyWeaponStateChange(int which);

#endif