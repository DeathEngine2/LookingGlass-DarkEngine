/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Source: x:/prj/tech/libsrc/loco/RCS/loco.h $
// $Author: dc $
// $Date: 1997/08/12 12:10:22 $
// $Revision: 1.5 $
//
// Locomotion

#ifndef __LOCO_H
#define __LOCO_H

#include <blockmem.h>
#include <idlist.h>
#include <vec2.h>
#include <matrixs.h>
#include <fix.h>
#include <mp.h>
#include <locotype.h>
#include <track.h>

/*
  Types of locomotion that we understand.
  How are these related to motion capture info?
*/
#define LOCO_STAND 0   
// following are also locomotive types
#define LOCO_WALK 1     
#define LOCO_RUN  2
#define LOCO_UNKNOWN UCHAR_MAX

// flags
#define LOCO_PLAYING 0x01       // we're currently playing a motion
#define LOCO_TRACK_CHANGED 0x02 // track has changed since last update

#define LOCO_END_ACCURACY 0.1 // default end accuracy

// motions
#define LOCO_NO_MOTION -1 // not currently playing a motion

// Basic locomotor structure - one per multiped
typedef struct Locomotor
{
   IDList;              // list management stuff
   uchar state;         // current loco type or standing
   uchar flags; 
   multiped *multiped;  // associated multiped
   int motion;  // motion we currently think we're playing
   Vec2 target;   // where we are heading
   fixang theta;  // target direction
   struct LocoSegment *segments;   // first segment in track
   ushort segments_num; // number of segments in track
   mxs_real end_accuracy; // how close we need to get to endpoint
   Vec2 loc;            // following data from multiped
   Vec2 last_loc;       // for estimating velocity
   // note - last_loc initialised to (FLT_MAX, FLT_MAX)
   Vec2 vel;            // estimated velocity
   mxs_real height;     // updated each time the loco is updated
   fixang heading;
   fixang facing;
   ulong last_update;   // last time we updated (init to ULONG_MAX)
} Locomotor;

// Locomotor data structures
extern IDListHead locomotors;
extern ListID locomotors_used;
extern ushort locomotors_num;

extern bool LocoInit(ushort locomotors_max, ushort segments_max, 
                     ushort tpts_max, ushort tpts_info_max,
                     LocomotorID(*loco_get_id_from_app_data)(),
                     void (*event_fn)(),
                     ulong *app_time);

// Multiped access functions
extern LocomotorID LocoRegisterMultiped(multiped *multiped);
extern void LocoUnregisterMultiped(LocomotorID loco_id);
extern void LocoUnregisterMultipeds();
extern LocomotorID LocoFindMultiped(multiped *multiped);

#define LOCO_SET_END_ACCURACY(loco_id, acc) \
   ((LOCO_FROM_ID(loco_id))->end_accuracy = acc)

// Locomotion position from multiped update
extern void LocoUpdatePosition(Locomotor *loco);

// Control the multipeds!
extern void LocoUpdate();
extern void LocoUpdateLocomotor(LocomotorID loco_id);

// Function the app must provide to get loco IDs from multipeds
extern LocomotorID (*loco_get_id_from_app_data)();

// Function the app must provide for error callbacks
// bool (*loco_event_callback)(LocomotorID loco_id, int event_type, void *data)
extern bool (*loco_event_callback)();

// Pointer to the app clock
extern ulong *loco_app_time;
// Get the app time
#define LOCO_GET_TIME ((loco_app_time!=NULL)?(*loco_app_time):0)

// Event codes
// Oops, I left the track
#define LOCO_EVENT_LEFT_TRACK 1
// The track appears to be bad
#define LOCO_EVENT_BAD_TRACK  2
// I can't find a motion that will move me along the track
#define LOCO_EVENT_NO_MOTION  3
// I deleted the first segment in the track for the locomotor
#define LOCO_EVENT_DEL_FIRST_SEGMENT  4
// The locomotor changed state
// data = new state
#define LOCO_EVENT_CHANGE_STATE  5

#define LOCO_SAFE_CALLBACK(loco, event, data) \
  if (loco_event_callback != NULL) \
     loco_event_callback(loco, event, data);

// Callback from multiped when motion ended
extern void LocoMotionEndedCallback(multiped *multiped, int motion, int frame);

#define LOCO_FROM_ID(loco_id) ((Locomotor*)ID_LIST_NODE(&locomotors, (loco_id)))

// debugging functions and macros
extern char loco_out_string[];

#define LOCO_SPEW_LOC(loco) \
{ \
   sprintf(loco_out_string, "Loco %d at (%f %f)\n", loco->id, \
           loco->loc.x, loco->loc.y); \
   mprintf("%s", loco_out_string); \
}

#endif  // __LOCO_H
