/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/physflag.h 1.2 1997/06/18 15:06:33 mahk Exp $

#ifndef PHYSFLAG_H
#define PHYSFLAG_H

//
// PHYSICS STATE FLAGS
// 

#define PHYS_CONTROLLED       (1<<0)
#define PHYS_GRAVITY          (1<<1)
#define PHYS_STAY_ON_FLOOR    (1<<2)
#define PHYS_LOCAL_ONLY       (1<<3)
#define PHYS_VIRTUAL          (1<<4)
#define PHYS_FACE_VELOCITY    (1<<5)

#define PHYS_PERM_FLAGS       (0xff)

//#define PHYS_ACTIVE           (1<<8)
#define PHYS_ON_FLOOR         (1<<9)
#define PHYS_TERRAIN_COLLIDE  (1<<10)

#endif // PHYSFLAG_H
