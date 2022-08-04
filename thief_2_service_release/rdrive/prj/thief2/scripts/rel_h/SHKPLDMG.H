/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkpldmg.h 1.2 1999/03/07 20:44:15 XEMU Exp $

#ifndef __SHKPLDMG_H
#define __SHKPLDMG_H

#include <dmgmodel.h>

eDamageResult LGAPI ShockPlayerDamageFilter(ObjID victim, ObjID culprit, sDamage* damage, tDamageCallbackData data);

void ShockEquipArmor(ObjID equipperID, ObjID armorID);
void ShockUnequipArmor(ObjID equipperID, ObjID armorID);

void ShockPlayerDamageInit(void);
void ShockPlayerDamageTerm(void);

#endif // __SHKPLDMG_H
