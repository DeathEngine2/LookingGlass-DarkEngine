/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

////////////////////////////////////////////////
// $Header: r:/prj/cam/src/shock/RCS/shkmelee.h 1.5 1999/04/28 13:44:51 JON Exp $
// Melee weapons

#ifndef __SHKMELEE_H
#define __SHKMELEE_H

#include <shkmelpr.h>

extern void ShockMeleeInit(void);
extern void ShockMeleeTerm(void);

extern BOOL IsMelee(ObjID weapon);
extern BOOL EquipMelee(ObjID owner, ObjID weapon, int type);
extern BOOL UnEquipMelee(ObjID owner, ObjID weapon);
extern BOOL DestroyMelee(ObjID owner, ObjID weapon);
extern BOOL IsCurrentPlayerArm(ObjID weapon);

extern void StartMeleeAttack(ObjID owner, ObjID weapon);
extern void FinishMeleeAction(ObjID owner, ObjID weapon);

// player melee action types
enum {
   kPlayerMeleeActionSwingMediumLeft,
   kPlayerMeleeActionSwingLong,
   kPlayerMeleeNumActions,
};

enum eShockWeaponType
{
   kSWT_Wrench,
};

#endif
