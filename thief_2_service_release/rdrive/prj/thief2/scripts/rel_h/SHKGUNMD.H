/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/shkgunmd.h 1.3 1998/03/13 18:31:04 JON Exp $

#ifndef __SHKGUNMD_H
#define __SHKGUNMD_H

#include <objtype.h>

EXTERN void PlayerGunModelOn(ObjID gunID);
EXTERN void PlayerGunModelPosUpdate(void);
EXTERN void PlayerGunModelOff(void);   // turn gun off by lowering it
EXTERN void PlayerGunModelKill(void);  // turn gun off instantly
EXTERN void PlayerGunModelUpdate(void);
EXTERN void PlayerGunModelInit(void);
EXTERN void PlayerGunModelShutdown(void);
EXTERN BOOL PlayerGunModelIsOn(void);
// the model controls firing
EXTERN BOOL PlayerGunModelFire(void);

#endif
