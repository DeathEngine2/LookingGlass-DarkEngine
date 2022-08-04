/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/shkplpsi.h 1.6 1998/02/26 13:37:16 JON Exp $

#ifndef __SHKPLPSI_H
#define __SHKPLPSI_H

#include <shkpsity.h>
#include <dmgmodel.h>

EXTERN void PlayerPsiInit(void);
EXTERN void PlayerPsiHandleRUp(void);
EXTERN void PlayerPsiHandleRDown(void);
EXTERN void PlayerPsiFrame(int dt);
EXTERN void PlayerPsiSelect(ePsiType type);
EXTERN BOOL PlayerPsiActivate(void);
EXTERN void PlayerPsiDeactivate(void);
EXTERN BOOL PlayerPsiIsActive(void);
EXTERN ePsiType PlayerPsiGetType(void);
EXTERN float PlayerPsiGetPower(void);
EXTERN float PlayerPsiGetMaxPower(void);
EXTERN void PlayerPsiSetMaxPower(float maxPower);
EXTERN void PlayerPsiSetPower(float power);
EXTERN BOOL PlayerPsiIsCrashing(void);
EXTERN eDamageResult PlayerPsiCrashImpactHandler();

#endif