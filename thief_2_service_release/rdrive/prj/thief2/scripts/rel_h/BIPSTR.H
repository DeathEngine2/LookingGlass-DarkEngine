/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

#ifndef _BIPSTR_H
#define _BIPSTR_H

#include<matrix.h>
#include<3d.h>
#include <schedstr.h>
#include <newskel.h>

typedef struct Head_info {
   uchar state;
   mxs_real head_len;   // neck to top of head length
   int free_table_id;
   effec_capture **table;
   Effec_sched *rest;
} Head_info;

typedef struct Foot_info {
   uchar state;
   mxs_ang pigeon; // pigeon toed ness of dude
   mxs_real heel;   // heel height (well, vertical height to ankle
   mxs_real to_toe; // distance out to toe
   int foot_hor;  // is foot horizontal? Necessary?
   mxs_real coef_fric;
   int free_table_id;
   effec_capture **table;
   Effec_sched *rest;
} Foot_info;

typedef struct Hand_info {
   mxs_real hand;   
   int weap;
   uchar state;  //0=open, 1=clenched, 2=pointing, etc. 
   // (For Later design the hand
   // motion will be diversified by the following.
   // mxs_ang finger_posup;
   // mxs_ang finger_poslow;
   // mxs_ang thumb_posup;
   // mxs_ang thumb_poslow;
   mxs_real grip_str;
   mxs_real coef_fric;

   int free_table_id;
   hand_capture **table;
   Hand_sched *rest;
   
} Hand_info;

typedef struct Shoul_info {
   uchar state;
   mxs_real shoul;   // neck to top of head length

   int free_table_id;
   effec_capture **table;
   Effec_sched *rest;
} Shoul_info;

typedef struct Leg_info {
   uchar mstate;   // 0 = done, 1 = moving (Kate hack for motion capture)
   //limb_sched lsc;

   mxs_real thigh;    // length
   mxs_real shin;     // length
   int knee;      // 1 for forward, -1 for back

   // Which of the following variables below is not certain here.
   mxs_real foot_width;   // distance between feet
   mxs_real k1;           // constants for finding knee
   mxs_real thigh2;       //thigh squared
   mxs_real leg_height;   // thigh + shin + heel
   mxs_real leg_height2;  // squared
   mxs_real leg_len;      // thigh + shin
   mxs_real coef_fric;
   mxs_real strength;

   int free_table_id;
   limb_capture **table;
   Limb_sched *rest;
} Leg_info;

typedef struct Arm_info {
   uchar state;     // 0 = done, 1 = moving
   //limb_sched lsc;  // arm schedule
   mxs_real uparm;      // upper arm length
   mxs_real lowarm;     // lower arm length
   mxs_real coef_fric;
   mxs_real strength;

   int free_table_id;
   limb_capture **table;
   Limb_sched *rest;
} Arm_info;

typedef struct Trunk_info {
   uchar state;   // 0 = done, 1 = doing motion

   //trunk_sched ts;
   mxs_vector base_pos;
   mxs_matrix lowerab_direc;
   mxs_matrix uppertorso_offset;

   mxs_real       inshoul_width;
   mxs_real       shoul_len;
   mxs_real       spine_len;      // butt to neck length
   mxs_real       shoul_per;      // percentage from butt to neck
   mxs_real       ab_per;         // percentage from butt to abdomen
   mxs_real       hip_width;      // width of hip
   mxs_real       hip_height;     // height of ground at hip
   mxs_vector spine;          // current spine

   int free_table_id;
   trunk_capture **table;
   Trunk_sched *rest;
} Trunk_info;

// foot
#define BPD_LEFT  0
#define BPD_RIGHT 1

// crouch states

#define CROUCH_NOT      0
#define CROUCH_STRAIGHT 1
#define CROUCH_HUNCH    2

// scheduler
#define SCD_PENDING 0
#define SCD_ACTIVE  1
#define SCD_DONE    2
#define SCD_REL     1
#define SCD_ABS     0
#define SCD_VECTOR  0
#define SCD_POINT   0

// state
#define BPD_NORMAL   0
#define BPD_LANDING  1
#define BPD_AIRBORNE 2
#define BPD_EXPLODE  3

// locomotion state
#define BPD_STATIC  0
#define BPD_WALKING 1
#define BPD_RUNNING 2

#define NUM_JOINT      24 // May add 20 for RPG
#define NUM_NORMAL     15
#define NUM_SEGMENT    21 // May add 20 for RPG
#define NUM_POSMATS     9
#define NUM_ATTRIBUTES  1

typedef struct bipeds_info {

   // state everyone needs
   int type;          // just so we don't have to include the godamn 
                      // universe to find it each time
   uchar bstate;      // biped state 0=still 1=walking 2=blowing apart, 
                      // 3=slumping, 4=jjet etc
   int gamedata;    // game specific hook back to object
   int detail;        // -1=not rendered,0 = max,
   int last_detail;   // Detail at last frame (basically, a phys detail)
   sks_skel skel;
   sks_seginfo sg[NUM_SEGMENT];
   mxs_vector joints[NUM_JOINT];   // joints
   // normals
   union {
      struct {mxs_vector norm_base,norm_upbody,norm_rleg,norm_lleg,norm_rcalf,norm_lcalf,norm_rarm,norm_larm,norm_rwrist,norm_lwrist;};
      mxs_vector norm[NUM_NORMAL];
   };
   mxs_matrix positions[NUM_POSMATS];

   mxs_vector prev_joints[NUM_JOINT];   // joints
   // normals
   union {
      struct {mxs_vector prev_norm_base,prev_norm_upbody,prev_norm_rleg,prev_norm_lleg,prev_norm_rcalf,prev_norm_lcalf,prev_norm_rarm,prev_norm_larm,prev_norm_rwrist,prev_norm_lwrist;};
      mxs_vector prev_norm[NUM_NORMAL];
   };
   mxs_matrix prev_positions[NUM_POSMATS];

   short Abilities[NUM_ATTRIBUTES];   

   mxs_vector *velocity;
   mxs_real stride; // walking stride 
   int loco;     // locomotion type
   mxs_real speed;  // current speed
   mxs_vector cen_mass;  // how forward is the center of mass should this be 
                  // a mxs_vector?
   mxs_real fatigue;

  //Torso
   Trunk_info trunk;
   Head_info head;

  //Arm
   Arm_info arm[2];
   Hand_info hand[2];

  //Leg
   Leg_info leg[2];
   Foot_info foot[2];

} bipeds_info;

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

#define SEG_LFOOT     0
#define SEG_RFOOT     1
#define SEG_LCALF     2
#define SEG_RCALF     3
#define SEG_LTHIGH    4
#define SEG_RTHIGH    5
#define SEG_BUTT      6
#define SEG_AB        7
#define SEG_HEAD      8
#define SEG_LSHLDR    9
#define SEG_RSHLDR   10
#define SEG_LBICPT   11
#define SEG_RBICPT   12
#define SEG_LFORE    13
#define SEG_RFORE    14
#define SEG_LHAND    15
#define SEG_RHAND    16
#define SEG_LCOLBONE 17
#define SEG_RCOLBONE 18
#define SEG_RWEAP    19
#define SEG_LWEAP    20

#define E_HEAD   0
#define E_RSHLDR 1
#define E_LSHLDR 2
#define E_RHAND  3
#define E_LHAND  4
#define E_RFOOT  5
#define E_LFOOT  6
#define E_WEAPR  7
#define E_WEAPL  8

#define SCH_TORSO  0
#define SCH_HEAD   1
#define SCH_RARM   2
#define SCH_LARM   3
#define SCH_RHAND  4
#define SCH_LHAND  5
#define SCH_RWHAND 6
#define SCH_LWHAND 7
#define SCH_LLEG   8
#define SCH_RLEG   9
#define SCH_LFOOT 10
#define SCH_RFOOT 11

#define MAT_BUTT  0
#define MAT_AB    1
#define MAT_HEAD  2
#define MAT_RHAND 3
#define MAT_LHAND 4
#define MAT_RWEAP 5
#define MAT_LWEAP 6
#define MAT_RFOOT 7
#define MAT_LFOOT 8

#define NORM_RCALF    0
#define NORM_RLEG     1
#define NORM_RARM     2
#define NORM_LLEG     3
#define NORM_LARM     4
#define NORM_LCALF    5
#define NORM_LWRIST   6
#define NORM_RWRIST   7
#define NORM_HEAD     8
#define NORM_TRUNK    9
#define NORM_UPTRUNK 10
#define NORM_LHAND   11
#define NORM_RHAND   12
#define NORM_LFOOT   13
#define NORM_RFOOT   13



#define SCD_NORMAL    0
#define SCD_CANCELED  1
#define SCD_STATIC    2
#define SCD_WALKING   3
#define SCD_RUNNING_1 4
#define SCD_RUNNING_2 5
#define SCD_AIRBORNE  6

#endif //_BIPED_H



