/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/motplay.h 1.9 1997/09/29 10:34:20 kate Exp $

#ifndef __MOTPLAY_H
#define __MOTPLAY_H

#include <multiped.h>
#include "objtype.h"

// how to convert motion numbers to res IDs and vica-versa
#define MOT_NUM_FROM_ID(id) ((id-IDBASE_MOTION-1)/2)
#define MOT_ID_FROM_NUM(num) (id*2+IDBASE_MOTION+1)

// must be called by any motion callback.  Unlocks the per-frame data
// associated with motion.  Automatically set by MotSimplePlay etc
EXTERN int MotFreeDataCallback(multiped *mp, int motion_num, int frame);

// callback for motions ending
EXTERN int MotEndCallback(multiped *mp, int motion_num, int frame, ulong appFlags);

// setup the motion info struct for object.  use when calling motplay directly.
// params is motion parameter structure to use
EXTERN void MotSetupInfo(ObjID obj_id, mps_start_info *info, mps_motion_param *params);

// play the motion at default priority
EXTERN void MotSimplePlay(ObjID obj_id, int motion_num);
// play the motion at the given priority
EXTERN void MotPriPlay(ObjID obj_id, int pri, int motion_num);
// play the motion and alter motion parameters
EXTERN void MotPlay(ObjID obj_id, int pri, mps_start_info *info);
// stop whatever motion we're currently playing
EXTERN void MotStop(ObjID obj_id);
// play a single frame of a motion instantly, then kill it
EXTERN void MotSinglePlay(ObjID obj_id, int motion_num);
// play a motion, make a callback when it ends
EXTERN void MotCallbackPlay(ObjID obj_id, int pri, int motion_num,
                     motion_callback callback);

#endif  // __MOTPLAY_H


