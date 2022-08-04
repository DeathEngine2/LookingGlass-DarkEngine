/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shktcomp.h 1.1 1999/02/10 19:05:38 XEMU Exp $

#ifndef __SHKTCOMP_H
#define __SHKTCOMP_H

EXTERN void ShockTurretInit(int which);
EXTERN void ShockTurretTerm(void);
EXTERN void ShockTurretDraw(void);
EXTERN void ShockTurretStateChange(int which);

#endif