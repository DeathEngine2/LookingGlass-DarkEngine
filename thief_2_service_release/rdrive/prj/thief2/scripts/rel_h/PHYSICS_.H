/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/physics_.h 1.9 1997/06/17 23:34:55 dc Exp $
// internal physics system defines, state

#ifndef __PHYSICS__H
#define __PHYSICS__H

#include <comparry.h>

////////////////////////////////////////////////////////////
// PHYSICS SYSTEM INTERNALS
//

//
// GLOBAL ARRAYS
//
#define MAX_PHYS_OBJS 128

EXTERN PhysicsState* physStates[];
EXTERN ObjID         physObjIDs[];
EXTERN int*          ObjPhysIDs;  
EXTERN sCompactArrayProp physCompArrayProp;  // compact array property

#define Phys2Obj(physid)  (physObjIDs[physid])
#define Obj2Phys(objid)   (ObjPhysIDs[objid])

#define physPos(physid) (physStates[physid]->pos)
#define physObjPos(obj) (physPos(Obj2Phys(obj)))

#define PhysIsActive(physid) (Phys2Obj(physid) != OBJ_NULL)
#define ObjPhysIsActive(obj)  (OBJ_IS_CONCRETE(obj) && Phys2Obj(Obj2Phys(obj)) == (obj))

#define EPSILON 0.01
#define SLOW_ACC 2.5
#define FAST_ACC 5.0
#define GRAVITY -20.0

//
// SLEWING AND SLAMMING
//

EXTERN void PhysSlew (PhysicsState *ps, int ms);
// discourage normal people from using this, it is pretty netpacket tied
EXTERN void physUpdateState(int physid, PhysicsState *ps);

//
// SMOOTHING FOR DEAD RECKONING
//

EXTERN void smoothVec (PhysVec *newvec, PhysVec *dst, PhysVec *src, float diff_frac);
EXTERN PhysAng smoothAngElem(PhysAng dst, PhysAng src, float diff_frac);
EXTERN void smoothAng(PhysAngVec *newvec, PhysAngVec *dst, PhysAngVec *src, float diff_frac);

//
// Object Management 
//

// Delete a physstate by object or handle
EXTERN void PhysDelPhysID (int physID);
EXTERN void PhysDumpSingleObj(int physid);

//
// VARIOUS HANDLE-BASED ACCESSORS
//

EXTERN void PhysSetFlag(int physid, PhysFlags x, BOOL set);
// get a pointer to the state of the physID
EXTERN PhysicsState *physGetState(int physID);

// 
// CALCUALTION
//

// evaluate the controls for controlled objects
EXTERN void PhysEvaluateControls (int physID, int ms);

#endif // __PHYSICS__H
