/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkloot.h 1.2 1999/04/12 21:49:56 XEMU Exp $

#ifndef __SHKLOOT_H
#define __SHKLOOT_H

#include <dmgmodel.h>

EXTERN eDamageResult LGAPI ShockLootDamageListener(const sDamageMsg* pMsg, tDamageCallbackData data);

EXTERN void GenerateLoot(ObjID corpse);

#endif