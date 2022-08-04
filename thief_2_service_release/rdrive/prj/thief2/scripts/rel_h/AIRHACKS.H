/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/airhacks.h 1.3 1997/06/17 22:18:42 kcobb Exp $

#ifndef __AIRHACKS_H
#define __AIRHACKS_H

#include <objtype.h>

EXTERN void air_init_hacks(void);
EXTERN void air_update_hacks(ulong ms);
EXTERN void air_frob_hacks(ObjID obj);
EXTERN BOOL air_start_nano_effect(int cost);
EXTERN void air_clut_screen(BOOL on);
EXTERN void air_kill_hacks(void);
EXTERN void AirHacksToggleCamBot();

EXTERN int effect_time, effect_max;

#endif   // __AIRHACKS_H
