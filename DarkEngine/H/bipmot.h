#ifndef _BIPMOTION_H
#define _BIPMOTION_H
#include<matrix.h>
#include<3d.h>
#include <schedstr.h>
#include <bipstr.h>

#define MAXNUM_MOTCAPS 5

typedef struct motcap_loc {
   Id Resource;
   ushort offset;
   int numframes;
} motcap_loc;

typedef struct mot_info {
  int nonsense;
} mot_info;

typedef struct biped_motion {
  int id;
  int type; // 0 = virtual motion, 1 = motion captured
  mxs_real start_time;
  mxs_real duration;
  short   num_frames;
  int inc_with_current;
  mxs_real (*speed)();

  Trunk_sched torso;
  Effec_sched head;
  Limb_sched arm[2];
  Limb_sched leg[2];
  //effec_sched shldr[2];
  Effec_sched foot[2];
  Hand_sched hand[2];

} biped_motion;

typedef struct biped_locomotion {

  int id;
  int type;
  mxs_real start_time;
  mxs_real duration;
  short   num_frames;
  int inc_with_current;
  g3s_vector start_loc;
  g3s_vector end_loc;
  mxs_real (*speed)();

  Trunk_sched torso;
  Effec_sched head;
  Limb_sched arm[2];
  Limb_sched leg[2];
  // effec_sched shldr[2];
  Effec_sched foot[2];
  Hand_sched hand[2];

} biped_locomotion;

#define LOCO_BLKSIZE 5

#define locomotion_table biped_locomotion*

#endif //_BIPMOTION_H
