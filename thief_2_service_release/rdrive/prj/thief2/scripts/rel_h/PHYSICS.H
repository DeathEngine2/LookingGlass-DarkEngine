/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/physics.h 1.16 1997/09/05 17:21:35 CCAROLLO Exp $

#ifndef __PHYSICS_H

#include <phystype.h>
#include <objtype.h>

////////////////////////////////////////////////////////////
// PHYSICS STATE API
//


// Fixup for new physics
EXTERN void PhysFixFromOldPhysics();

//
// CREATORS 
//

// Create a phys state for an object, return success
EXTERN BOOL  PhysAddObj (ObjID obj);

// Removes the physstate for an object 
EXTERN BOOL PhysDelObj (ObjID obj);


//
// ACCESSORS
//

// return the PhysState for an ObjID
EXTERN PhysicsState* PhysGetObjState(ObjID obj);

#define ObjHasPhysState(obj) (PhysGetObjState(obj) != NULL)

// SET/GET Physics flags

EXTERN BOOL PhysGetObjFlags(ObjID obj, PhysFlags x); // true if any are true
EXTERN void PhysSetObjFlags(ObjID obj, PhysFlags x, BOOL val);  

// Get physics position

EXTERN PhysPos* PhysGetObjPos(ObjID obj);


// returns FALSE is pos is out of bounds
EXTERN BOOL pos_in_bounds(PhysVec* v);

// get the radius of a model
EXTERN PhysReal PhysGetRadius(ObjID objid);
// get the extent box of a model (also returns the distance from center to bottom)
EXTERN PhysReal PhysGetBBox(ObjID objid, PhysVec *bmin, PhysVec *bmax);

//
// MOMENTUM ACCESSORS/MUTATORS
//
EXTERN BOOL PhysSetObjVelocity(ObjID obj, PhysVec *vel);
EXTERN BOOL PhysSetObjAngVelocity(ObjID obj, PhysVec *angvel);
EXTERN BOOL PhysGetObjVelocity(ObjID obj, PhysVec *vel);
EXTERN BOOL PhysGetObjAngVelocity(ObjID obj, PhysVec *angvel);
EXTERN BOOL PhysStopObject   (ObjID obj);



//
// CONTROLS ACCESSORS
// 

EXTERN BOOL PhysSetControls     (ObjID obj, int axis, PhysReal val);
EXTERN BOOL PhysSetAngControls  (ObjID obj, int axis, PhysReal val);
EXTERN BOOL PhysZeroControls (ObjID obj);

// run an exciting FRAME OF PHYSICS! yeah!
EXTERN void PhysRun (int dt);

//
// INITIALIZATION/TERMINATION
//

// initialize the physics system
EXTERN void OldPhysInit   (void);
EXTERN void OldPhysTerm   (void);



#define __PHYSICS_H
#endif

/*
Local Variables:
typedefs:("ObjID" "PhysicsControls" "PhysicsState" "Position" "mxs_angvec" "PhysVec" "povPos")
End:
*/
