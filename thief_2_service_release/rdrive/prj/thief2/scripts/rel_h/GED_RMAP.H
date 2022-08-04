/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/ged_rmap.h 1.1 1997/12/02 23:14:46 dc Exp $
// remap brush horror

#ifndef __GED_RMAP_H
#define __GED_RMAP_H

typedef void (*ged_remap_callback)(int *mapping);

// go compress br_id space
EXTERN int ged_remap_brushes(void);

// add and remove remap callbacks
EXTERN BOOL ged_remap_add_callback(ged_remap_callback cb);
EXTERN BOOL ged_remap_rem_callback(ged_remap_callback cb);

#endif  // __GED_RMAP_H
