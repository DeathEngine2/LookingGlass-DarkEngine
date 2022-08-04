/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

////////////////////////////////////////////
// $Header: r:/prj/cam/src/shock/RCS/shkpsipw.h 1.4 1999/04/05 21:30:05 XEMU Exp $
//
// Psionics system - powers
//

#ifndef __SHKPSIPW_H
#define __SHKPSIPW_H

#include <objtype.h>
#include <simtime.h>

#include <shkpltyp.h>
#include <shkpsity.h>

EXTERN const char* psiPowerNames[];

EXTERN void PsiPowersReset(void);

EXTERN BOOL PsiPowerGet(ePsiPowers power, sPsiPower** ppPower);
EXTERN float PsiPowerGetData(ePsiPowers power, int dataNum);
EXTERN ObjID PsiPowerGetObjID(ePsiPowers power);
EXTERN tSimTime PsiPowerGetTime(ePsiPowers power, ObjID userID);

EXTERN void PsiPowersInit();

EXTERN void ShockTeleportClear();

#endif