/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkctrl.h 1.6 1999/01/21 11:38:45 JON Exp $

#ifndef __SHKCTRL_H
#define __SHKCTRL_H

// This is mostly redundant - it's currently only used by the under-utilized camera control system
EXTERN bool ShockControlKeyParse(int keycode, ObjID controlObj, float speed);
EXTERN void ShockPlayerJump(void);

#endif
