/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/shkaihck.h 1.2 1998/01/13 06:51:12 JON Exp $

#ifndef __SHKAIHCK
#define __SHKAIHCK

#include <propface.h>
#include <ai.h>

enum EShockAIType {kShockAINone = 0, kShockAITurret = 1, kShockAIDroid = 2, kShockAIGrunt = 3, };

// Hacked AI Type
#define PROP_SHOCK_AI_TYPE_NAME "Shock AI"
EXTERN  IIntProperty* gPropShockAIType;
EXTERN  void ShockAITypePropInit();
EXTERN  int GetShockAIType(ObjID obj);

void ShockAIDie(cAI *pAI, int type);

#endif