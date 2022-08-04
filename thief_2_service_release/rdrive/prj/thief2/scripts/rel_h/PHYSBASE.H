/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/physbase.h 1.3 1997/06/16 14:50:11 JON Exp $

#ifndef PHYSBASE_H
#define PHYSBASE_H

#include <matrixs.h>
#include <phystype.h>

////////////////////////////////////////////////////////////
// PHYSICS SYSTEM BASE TYPES
//

//
// Control Values for things that are controlled.  
//

struct PhysicsControls
{
   PhysVec des_vel;          // desired velocity
   PhysVec des_angvel;       // desired angular velocity (0.0 = 0 degrees, 16.0 = 360 degrees)
};

//
// Here it is! The actual physics state for an object
//

struct PhysicsState
{
   PhysVec      acc;         // acceleration
   PhysVec      vel;         // velocity
   PhysVec      angacc;      // angular acceleration (0.0 = 0 degrees, 16.0 = 360 degrees)
   PhysVec      angvel;      // angular velocity (0.0 = 0 degrees, 16.0 = 360 degrees)
   PhysicsControls controls; // control inputs (for controlled objects only)
   PhysPos      *pos;        // where our pos is
   PhysFlags    flags;       // misc flags
   ubyte        last_coll_texture; // tricky hack for texture collisions
   ubyte        last_foot_texture; // tricky hack for texture footsteps
};

// Length of stuff not to update?
#define DONT_UPDATE_LEN (sizeof(PhysFlags)+sizeof(PhysPos*)+2*sizeof(ubyte))




//
// ACCESSOR MACROS
//

#define PhysCheckFlag(physid, x) (((physGetState(physid))->flags & x) != 0)

#endif // PHYSBASE_H


