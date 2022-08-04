/*
 * $Header: x:/prj/tech/libsrc/biped/RCS/biped.h 1.2 1996/08/23 18:33:29 kate Exp $
 * 
*/

#include <r3d.h>
#include <vec2d.h>
#include "scheddef.h"
#include <rect.h>
#include <newskel.h>

#ifndef __BIPED_H
#define __BIPED_H

bd_vec_interp(mxs_vector *,mxs_vector *,mxs_vector *,float);

typedef struct bpsLoc {
   float x,y,z;
   fixang theta,phi;
} bpsLoc;

#if 0
typedef struct Rect {
   vec2d ul;
   vec2d lr;
} Rect;
#endif

// center of grav is halfway between shoulder and butt
// that's the marble position

typedef struct schedule {
   long start_time;  // start time
   long delta_time;  // end time
   fix zmag;         // zmagnitude of change
   mxs_vector start;  // start targ
   mxs_vector end;    // end targ
   mxs_vector *dest;
   uchar state;  // 0=pending, 1=active, 2=done
   uchar start_type; //REL,ABS
   uchar end_type;   //REL,ABS
   uchar userinfo;
} schedule;

typedef struct crouch_info {
   uchar state;   // 0 = not crouching, 1 = crouching, 2 = hunching
   fix old_rest;  // when uncrouch, this is where it goes
   fixang old_lean;
} crouch_info;

typedef struct foot_info {
   fixang ang;    // angle of foot on ground
   fix fx,fy;     // foot vector, normalized
   bool planted;  // foot planted or not
   mxs_vector heel; // guess, loser
   uchar sound;   // sound it will make
   schedule sched;   // scheduled foot action
   uchar mstate;   // 0 = done, 1 = moving (Kate hack for motion capture)
   limb_sched lsc;
} foot_info;

typedef struct arm_info {
   uchar state;   // 0 = done, 1 = moving
   limb_sched lsc;
} arm_info;

typedef struct trunk_info {
   uchar state;   // 0 = done, 1 = doing motion
   trunk_sched ts;
} trunk_info;

// foot
#define BPD_LEFT 0
#define BPD_RIGHT 1

// crouch states

#define CROUCH_NOT      0
#define CROUCH_STRAIGHT 1
#define CROUCH_HUNCH    2

// scheduler
#define SCD_PENDING 0
#define SCD_ACTIVE  1
#define SCD_DONE    2
#define SCD_REL 1
#define SCD_ABS 0
#define SCD_VECTOR 0
#define SCD_POINT  0

// state
#define BPD_NORMAL 0
#define BPD_LANDING 1
#define BPD_AIRBORNE 2
#define BPD_EXPLODE 3

// locomotion state
#define BPD_STATIC 0
#define BPD_WALKING 1
#define BPD_RUNNING 2

// Motions have a start time and end time;
// Can be relative to body or in world coordinates
// Can be a vector for pointing, or a point to hit
// If hitting a point, has to renormalize if too far
// Should know how flexed to stay

// Firing:
// Raise upper arm up to new body relative vector
// Point lower arm towards world vector

#define NUM_JOINTS      20
#define NUM_NORMALS     5
#define NUM_SEGMENTS    15


typedef struct bps_info {
   // state everyone needs
   int type;   // just so we don't have to include the godamn universe to find it each time
   uchar bstate;  // biped state 0=still 1=walking 2=blowing apart, 3=slumping, 4=jjet etc
   int detail; // -1=not rendered,0 = max,
   int last_detail;  // Detail at last frame (basically, a phys detail)
   sks_skel skel;
   sks_seginfo sg[NUM_SEGMENTS];
   mxs_vector joints[NUM_JOINTS];   // joints
   // normals
   union {
      struct {mxs_vector norm_body,norm_rleg,norm_rarm,norm_lleg,norm_larm;};
      mxs_vector norm[NUM_NORMALS];
   };
   // fixed spec
   fix spine_len;  // butt to neck length
   fix head_len;   // neck to top of head length
   fix shoul_per;  // percentage from butt to neck
   fix shoul_width;  // shoulder width
   fix ab_per; // percentage from butt to abdomen
   fix hip_width;    // width of hip
   fix uparm;  // upper arm length
   fix lowarm; // lower arm length
   fix hand;   // hand length
   fix thigh;  // length
   fix shin;   // length
   fix heel;   // heel height (well, vertical height to ankle
   fix to_toe; // distance out to toe
   fix to_heel;   // distance back to heel from ankle
   fix cen_mass;  // how forward is the center of mass
   int knee;      // 1 for forward, -1 for back
   int foot_hor;  // is foot horizontal?
   fixang pigeon; // pigeon toed ness of dude
   fix walk_speed;
   fix run_speed;

   // tweakable specs
   fix stride; // walking stride 
   fix rest_hip_height; // percentage of blah
   fix foot_width;   // distance between feet
   int gamedata;   // game specific hook back to object
   fixang def_lean;   // how much default lean
   fixang def_head;  // cause it sounds cool (default heading)
   fix m_rad;   // z offset from marble for crouching etc. (or rest hip_height)

   // internal info
   // sin and cosine of heading
   fixang lean; // current spine lean forward
   fixang head; // current heading
   fix dhead;
   fix h_cos;
   fix h_sin;
   foot_info foot[2];
   arm_info arm[2];
   trunk_info trunk;
   crouch_info crouch;
   fix cur_rest_hip;
   fix hip_z;  // hip z position
   fix hip_zvel; // hip z velocity
   fix hip_height; // height of ground at hip
   fix last_zvel; // last z velocity for landing compute
   mxs_vector spine;  // current spine
   int loco;     // locomotion type
   fix speed;  // current speed

   // computed constants
   float k1;   // constants for finding knee
   fix thigh2; //thigh squared
   fix leg_height; // thigh + shin + heel
   fix leg_height2;  // squared
   fix leg_len;   // thigh + shin
   fix w1;  // constant for finding elbow
   fix armlen; // uparm + lowarm
   fix uparm2; // upper arm squared
   fixang old_theta; // hack for framerate limiting
   float old_z;
} bps_info;

#define LTOE  0
#define RTOE  1
#define LANKLE 2
#define RANKLE 3
#define LKNEE 4
#define RKNEE 5
#define LHIP  6
#define RHIP  7
#define BUTT  8
#define NECK  9
#define LSHLDR 10
#define RSHLDR 11
#define LELBOW 12
#define RELBOW 13
#define LWRIST 14
#define RWRIST 15
#define LFINGER  16
#define RFINGER  17
#define ABDOMEN 18
#define HEAD   19

#define RFOOT     0
#define RSHIN     1
#define RTHIGH    2
#define RUPPERARM 3
#define RFOREARM  4
#define RHAND     5
#define PELVIS    6
#define TORSO     7
#define FACE      8
#define LFOOT     9
#define LSHIN     10
#define LTHIGH    11
#define LUPPERARM 12
#define LFOREARM  13
#define LHAND     14
 
#define NORM_BODY 0
#define NORM_RLEG 1
#define NORM_RARM 2
#define NORM_LLEG 3
#define NORM_LARM 4

#define SCD_NORMAL  0
#define SCD_CANCELED 1
#define SCD_STATIC   2
#define SCD_WALKING   3
#define SCD_RUNNING_1 4
#define SCD_RUNNING_2 5
#define SCD_AIRBORNE  6

#endif
