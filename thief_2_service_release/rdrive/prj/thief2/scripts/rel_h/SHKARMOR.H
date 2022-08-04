/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkarmor.h 1.2 1998/08/13 09:38:58 JON Exp $

#ifndef __SHKARMOR__H
#define __SHKARMOR__H

#include <dmgmodel.h>

eDamageResult LGAPI ShockArmorFilter(ObjID victim, ObjID culprit, sDamage* damage, tDamageCallbackData data);

void ShockArmorInit(void);
void ShockArmorTerm(void);
void ShockArmorStartGamemode(void);

#endif // __SHKARMOR__H
