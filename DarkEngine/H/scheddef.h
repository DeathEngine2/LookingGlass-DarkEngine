#ifndef __SCHEDDEF_H
#define __SCHEDDEF_H

#include <matrix.h>

typedef struct limb_sched {
   fix start_time;
   fix duration;
   short   num_frames;
   short   base_joint_id;
   short   end_joint_id;
   short   normal_id;
   fix   len1;  // length of base->joint segment
   fix   len2;  // length of joint->end segment
   mxs_vector *e_data; // num_frames array of end position (rel to base joint
                     //  and normal to limbs.
   mxs_vector *n_data;
} limb_sched;

typedef struct trunk_sched {
   fix start_time;
   fix duration;
   short   num_frames;
   short   base_id;
   short   neck_id;
   fix spine_len;
   mxs_vector *base_data; // num_frames array of base position (rel to base at
                          // time 0)
   mxs_vector *neck_data; // num_frames array of neck position (rel to base)
   fixang *heading_data;
} trunk_sched;

#define LS_EDATA_OFFSET (sizeof(long)*2+sizeof(short)*4+sizeof(fix)*4)

#define TS_DATA_OFFSET  (sizeof(long)*3+sizeof(short)*3+sizeof(fix)*3)
#endif
