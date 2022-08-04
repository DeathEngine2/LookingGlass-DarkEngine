/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/mseltype.h 1.1 1997/12/02 17:12:17 kate Exp $
//
// This declares all of the enums needed for motor skill selection via the
// motor skill set.  Some of these fields are explicitly set by the AI
// when it makes maneuver requests, and some are derived by the motion
// coordinator based on AI input and queries to the world rep etc.
//
// Convention is to place most common value first, so that if no value is
// specified in a request, its branch will be searched first

#ifndef __MSELTYPE_H
#define __MSELTYPE_H

#define MSEL_SIZE_PAD 0xff

////////////////////////////////////////////////////
////////////////////////////////////////////////////
///
/// Locomotion Enums
///
////////////////////////////////////////////////////
////////////////////////////////////////////////////

enum  // media modes
{
   kMS_Mode_OnGround,
   kMS_Mode_InWater,
   kMS_Mode_InAir,
   kMS_NumMediaModes,
   kMS_MediaModeInvalid = MSEL_SIZE_PAD,
};
typedef uchar eMS_MediaMode;

enum // facing offset from direction of motion
{
   kMS_Fac_Forwards,
   kMS_Fac_Left,
   kMS_Fac_Backwards,
   kMS_Fac_Right,
   kMS_NumFacings,
   kMS_FacingInvalid = MSEL_SIZE_PAD,
};
typedef uchar eMS_Facing;

enum // speed
{
   kMS_Speed_Normal,
   kMS_Speed_Stationary,
   kMS_Speed_Slow,
   kMS_Speed_Fast,
   kMS_NumSpeeds,
   kMS_SpeedInvalid = MSEL_SIZE_PAD,
};
typedef uchar eMS_Speed;

enum
{
   kMS_LocoKind_Normal,
   kMS_LocoKind_Searching,
   kMS_LocoKind_SwordCombat,
   kMS_NumLocoKinds,
   kMS_LocoKindInvalid = MSEL_SIZE_PAD,
};
typedef uchar eMS_LocoKind;

enum
{
   kMS_PhysCon_Normal,
   kMS_PhysCon_Vertical,
   kMS_PhysCon_Lateral,
   kMS_NumPhysConstraints,
   kMS_PhysConstraintInvalid = MSEL_SIZE_PAD,
};
typedef uchar eMS_PhysConstraint;

#endif

