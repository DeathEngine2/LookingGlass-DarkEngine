/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/netphys.h 1.7 1997/06/15 02:57:20 mahk Exp $
// well, this will soon be the real home of dead reckoning and smoothing

#ifndef __NETPHYS_H
#define __NETPHYS_H
#include <objtype.h>
#include <phystype.h>

#ifdef NETWORK_ENABLED

EXTERN void netPhysInit(void);
EXTERN void netPhysTerm(void);
EXTERN void netPhysReckon(int ms);
EXTERN void netPhysHandoff(ObjID obj, int newOwn);
EXTERN void netPhysSetupObj(ObjID obj);
EXTERN void netPhysToastObj(ObjID obj);
EXTERN void netPhysUpdateSmooth(ObjID o, PhysicsState *newps, PhysPos *pos);

#else  // NETWORK_ENABLED

// just null it out
#define netPhysReckon(ms)
#define netPhysSetupObj(obj)
#define netPhysToastObj(obj)
#define netPhysInit()
#define netPhysTerm()

#endif // NETWORK_ENABLED

#endif //  __NETPHYS_H
