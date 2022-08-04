/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/brquery.h 1.2 1997/08/12 19:53:55 dc Exp $
// some misc brush query/list control functions

#ifndef __BRQUERY_H
#define __BRQUERY_H

#include <editbrs.h>

// brush finder - returns the brush (if there is one) of brush id br_id 
EXTERN editBrush *brFind(int br_id);

// generic brush cycler - takes a "is brush ok" callback which you provide
EXTERN BOOL brCycle(int dir, BOOL (*br_ok)(editBrush *br));

// run br_ok on all brushes, run br_run on all that pass, returns count of ones which _run passes
EXTERN int brFilter(BOOL (*br_ok)(editBrush *br), BOOL (*br_run)(editBrush *br));

#endif  // __BRQUERY_H
