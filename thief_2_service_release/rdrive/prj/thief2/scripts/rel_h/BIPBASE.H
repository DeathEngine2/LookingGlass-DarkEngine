/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Source: r:/prj/cam/src/RCS/bipbase.h $
// $Author: kate $
// $Date: 1997/09/29 16:47:02 $
// $Revision: 1.8 $
//
// Basic biped data structure

#ifndef __BIPBASE_H
#define __BIPBASE_H

#include <multiped.h>
#include <skel.h>

#define NUM_JOINTS      20
#define NUM_NORMALS     9
#define NUM_SEGMENTS    15

// supplementary structure to AppMultiped
struct Biped
{
   multiped m;
   sks_skel skel;
   sks_seginfo sg[NUM_SEGMENTS];    // seginfo arrays required for sks_skel
   mxs_vector joints[NUM_JOINTS];   // joints and normals required for both
   mxs_vector norm[NUM_NORMALS];    // sks_skel and multiped
   mxs_matrix orients[NUM_JOINTS];  // orients used by multiped
   int motion;       // current motion handle
   int priority;     // current motion priority
   int motion_flags;    // flags set if feet down
   mxs_vector bmin;  // bbox vec in world coords 
   mxs_vector bmax;  // bbox vec in world coords
   float      radius; // bounding radius
   mxs_ang    desiredHeading; // from AI
   mxs_ang    motionHeading; // direction of motion XXX only correct if playing locomotion
   float      desiredSpeed;   // as fraction of max speed.  motion independent.
   float      actualSpeed;   // as fraction of max speed.  motion independent.
   mxs_ang    reqHeading; // requested heading -- XXX hack to get turning in,
                           // should not be needed really
   float      reqSpeed;   // requested speed -- XXX hack to get turning in
   BOOL       isTurning; // XXX hack for turning
   float      motScale;    // amount by which to scale the motion xlats by default.
                           // this is function of biped_lengths primScale, and limb_stretch property                                                                                
};

#define BIPED_MODEL_NAME_LEN 8

struct BipedModel
{
   char model_name[BIPED_MODEL_NAME_LEN]; // name of model to use for art
   int model_idx;       // base index for model art
};

// Note: the following two quantities must correspond to the 
// number of torsos/limbs that the motion processor uses
#define NUM_TORSOS      2
#define NUM_LIMBS       5

struct BipedLengths
{
   torso torsos[NUM_TORSOS];        // torso and limb data for multiped
   limb limbs[NUM_LIMBS];
   float primScale;  // how much primary limb lengths are scaled from original
                     // motion capture skeleton
};

// Joints
#define LTOE      0
#define RTOE      1
#define LANKLE    2
#define RANKLE    3
#define LKNEE     4
#define RKNEE     5
#define LHIP      6
#define RHIP      7
#define BUTT      8
#define NECK      9
#define LSHLDR   10
#define RSHLDR   11
#define LELBOW   12
#define RELBOW   13
#define LWRIST   14
#define RWRIST   15
#define LFINGER  16
#define RFINGER  17
#define ABDOMEN  18
#define HEAD     19
#define LSHLDRIN 20
#define RSHLDRIN 21
#define LWEAP    22
#define RWEAP    23

// Segments
#define SEG_LFOOT     0
#define SEG_RFOOT     1
#define SEG_LCALF     2
#define SEG_RCALF     3
#define SEG_LTHIGH    4
#define SEG_RTHIGH    5
#define SEG_BUTT      6
#define SEG_AB        7
#define SEG_HEAD      8
#define SEG_LBICPT    9
#define SEG_RBICPT   10
#define SEG_LFORE    11
#define SEG_RFORE    12
#define SEG_LHAND    13
#define SEG_RHAND    14

// Normals
#define NORM_PELV    0
#define NORM_RLEG    1
#define NORM_RARM    2
#define NORM_LLEG    3
#define NORM_LARM    4
#define NORM_RHAND   5
#define NORM_LHAND   6
#define NORM_UPTORS  7
#define NORM_HEAD    8

#endif // __BIPBASE_H



