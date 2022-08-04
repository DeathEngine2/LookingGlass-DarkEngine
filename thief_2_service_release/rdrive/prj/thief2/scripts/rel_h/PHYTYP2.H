/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/RCS/phytyp2.h 1.1 1997/08/29 20:28:58 kate Exp $
//
// Physics types
//
// (Must be C friendly, so no classes)
//

#ifndef __PHYSTYP2_H
#define __PHYSTYP2_H

typedef int tPhysSubModId;

// a collision
typedef struct sPhysClsn sPhysClsn;

// enum types
typedef uint ePhysIntersectResult;
typedef uint ePhysClsnResult;

typedef enum ePhysForceType
{
   kPFT_Gravity = 0x0100,   // Force to 4 bytes
   kPFT_Wind,
   kPFT_Current,
   kPFT_Collision,
} ePhysForceType;

enum ePhysCtrlType
{
   kPCT_NoControl,
   kPCT_VelControl,
   kPCT_RotVelControl,
   kPCT_LocControl,
   kPCT_RotControl,
};

enum ePhysModelCreateFlags
{
   kPMCF_Default        = 0,
   kPMCF_NonMoveable    = 0x0001,
   kPMCF_Uncontrollable = 0x0002,
   kPMCF_NoGravity      = 0x0004,
   kPMCF_Remote         = 0x0008,
   kPMCF_LowDetail      = 0x0010,
};

#define kPhysSphereDefRadius 1

#endif /* !__PHYSTYP2_H */
