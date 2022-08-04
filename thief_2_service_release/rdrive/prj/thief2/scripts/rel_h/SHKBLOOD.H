/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkblood.h 1.1 1999/04/14 08:30:39 JON Exp $

#ifndef __SHKBLOOD_H
#define __SHKBLOOD_H

#include <dmgmodel.h>

extern void ShockBloodInit(void);
extern void ShockBloodTerm(void);
extern void ShockReleaseBlood(const sDamageMsg* msg);

#endif // __SHKBLOOD_H
