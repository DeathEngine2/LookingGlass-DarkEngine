/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/phystype.h 1.1 1997/01/08 22:36:43 mahk Exp $

#ifndef PHYSTYPE_H
#define PHYSTYPE_H

////////////////////////////////////////////////////////////
// PHYSICS SYSTEM TYPES
//


typedef struct PhysicsControls PhysicsControls;
typedef struct PhysicsState PhysicsState;
typedef float  PhysReal; // should be mxs_real.  Sadly, we don't want matrixs.h
typedef struct mxs_vector PhysVec; 
typedef ulong  PhysFlags;
typedef ushort PhysAng;  // should be mxs_ang
typedef struct _mxs_angvec PhysAngVec;
typedef struct Position PhysPos;

#define PHYSID_NULL -1

#endif // PHYSTYPE_H
