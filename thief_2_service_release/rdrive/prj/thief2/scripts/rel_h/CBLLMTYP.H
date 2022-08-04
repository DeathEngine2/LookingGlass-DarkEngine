/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/cbllmtyp.h 1.3 1998/01/29 17:31:30 kate Exp $

#ifndef __CBLLMTYP_H
#define __CBLLMTYP_H

typedef enum eManeuverTransitionType
{
   kMnvrTrans_Immediate,
   kMvnrTrans_AtEnd,
   kMnvrTrans_Invalid=0xff,
} eManeuverTransitionType;

// XXX NOTE: even idle motions actually preclude locomotions currently,
// since locomotive maneuvers are never explicity requested as such. KJ 1/98
typedef enum eManeuverPriority
{
   kMnvrPri_Death, // highest priority
   kMnvrPri_Script,
   kMnvrPri_Combat,
   kMnvrPri_Normal,
   kMnvrPri_Locomote,
   kMnvrPri_Idle,
   kMnvrPri_Invalid=0xff,
} eManeuverPriority;


#ifdef __cplusplus
   
typedef class ICerebellum ICerebellum;

#endif

#endif
