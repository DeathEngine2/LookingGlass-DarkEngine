/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Source: x:/prj/tech/libsrc/loco/RCS/track.h $
// $Author: JON $
// $Date: 1996/11/06 10:20:14 $
// $Revision: 1.3 $
//
// Track API and data structures

#ifndef __TRACK_H
#define __TRACK_H

#include <blockmem.h>
#include <idlist.h>
#include <vec2.h>
#include <mp.h>

#include "loco.h"

// flags
#define LOCO_DONT_CARE_FACING  0x01     // facing not important
#define LOCO_DONT_CARE_HEADING 0x02     // heading not important

/*
  A segment is the basic unit of locomotion. Each segment
  describes movement from one point to another (along a 
  straight line segment) using a single locomotive motion
  type.
*/
typedef struct LocoSegment
{
   BlockMem;
   uchar type;         // type of locomotion to use
   struct LocoTPt *back_tpt; // transition point at start of segment
   struct LocoTPt *forward_tpt;   // transition point at end of segment
   mxs_real vertical_clearance; // vertical room along segment
   mxs_real slope;      // ground slope along segment
   fixang facing;      // facing to be used along segment
   uchar flags;
} LocoSegment;

/*
  A transition point describes a location at the start 
  or end of a segment. Each transition point is associated
  with an information structure that is shared between the
  transition point at the end of one segment and the point
  at the start of the next segment.
*/
#define LOCO_BACK_TPT   0x00    // This is a back pt
#define LOCO_FORWARD_TPT     0x01    // This is an forward pt

typedef struct LocoTPt
{
   BlockMem;
   uchar flags; // back or forward point
   mxs_real height; // ground height at this point
   struct LocoSegment *next_prev; // next (end) or previous (start) segment 
   struct LocoTPtInfo *info;   // transition point info
} LocoTPt;

/*
  A transition point info structure contains the actual
  information about a transition point and is shared between
  two transition points.
*/
typedef struct LocoTPtInfo
{
   BlockMem;
   Vec2 left, right, mid; // leftmost/rightmost/mid locations to go to
   // this a redundant representation but we keep mid and width
   // for ease of use.
   // if this is an start or end tpt then only the left location is
   // valid (its the start or end point)
   mxs_real width;
   fixang facing;      // desired facing at this point
   fixang heading;     // desired heading at this point
   uchar flags;
} LocoTPtInfo;

// Some positional macros
#define SEGMENT_START_POS(segment) ((segment)->back_tpt->info->left)
#define SEGMENT_END_POS(segment) ((segment)->forward_tpt->info->left)
#define SEGMENT_BACK_LEFT(segment) ((segment)->back_tpt->info->left)
#define SEGMENT_BACK_RIGHT(segment) ((segment)->back_tpt->info->right)
#define SEGMENT_BACK_MID(segment) ((segment)->back_tpt->info->mid)
#define SEGMENT_BACK_WIDTH(segment) ((segment)->back_tpt->info->width)
#define SEGMENT_FWD_LEFT(segment) ((segment)->forward_tpt->info->left)
#define SEGMENT_FWD_RIGHT(segment) ((segment)->forward_tpt->info->right)
#define SEGMENT_FWD_MID(segment) ((segment)->forward_tpt->info->mid)
#define SEGMENT_FWD_WIDTH(segment) ((segment)->forward_tpt->info->width)

#define SEGMENT_NEXT(segment) (segment->forward_tpt->next_prev)
#define SEGMENT_PREV(segment) (segment->back_tpt->next_prev)

/*
  Data
*/
extern BlockHead segments;
extern BlockHead tpts;
extern BlockHead tpts_info;

/*
  API
*/

// The info for the backwards transition point of a segment
#define LOCO_SEGMENT_BACK_INFO(segment) \
   ((segment==NULL)?NULL:((segment->back_tpt==NULL)?NULL:segment->back_tpt->info))
// The info for the forwards transition point of a segment
#define LOCO_SEGMENT_FORWARD_INFO(segment) \
   ((segment==NULL)?NULL:((segment->forward_tpt==NULL)?NULL:segment->forward_tpt->info))

// Get a pointer to a locomotion entity from its ID - NULL if invalid
extern struct Locomotor *LocoGetFromID(LocomotorID locomotor_id);

/*
  Add a segment to the track database connecting to the
  last segment added for the multiped.
*/
extern LocoSegment *LocoAppendSegment(LocomotorID Locomotor_id, 
                                      uchar type, mxs_real height,
                                      mxs_real vertical_clearance, 
                                      mxs_real slope, 
                                      Vec2 *left, Vec2 *right,
                                      fixang facing,
                                      fixang heading,
                                      uchar flags);

extern LocoSegment *LocoPrependSegment(LocomotorID Locomotor_id, 
                                      uchar type, mxs_real height,
                                      mxs_real vertical_clearance, 
                                      mxs_real slope, 
                                      Vec2 *left, Vec2 *right,
                                      fixang facing,
                                      fixang heading,
                                      uchar flags);

// Delete the first segment in a track
extern void LocoDeleteFirstSegment(LocomotorID Locomotor_id);

// Delete all segments for a multiped
extern void LocoDeleteTrack(LocomotorID Locomotor_id);

#endif // __TRACK_H





