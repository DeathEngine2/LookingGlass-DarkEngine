/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/gridsnap.h 1.3 1997/02/14 17:49:58 dc Exp $

// grid functions

#ifndef __GRIDSNAP_H
#define __GRIDSNAP_H

typedef struct
{
   mxs_real line_spacing;
   mxs_vector phase_shift;   
   mxs_angvec orientation;
   bool grid_enabled;
} Grid;

 // @HACK: perhaps this should be less goofy than just here, eh?
EXTERN Grid cur_global_grid;

void gedit_vertex_snap(Grid *g, mxs_vector *dest, mxs_vector *src);

 //  prime_axis is axis to draw grid perpendicular to
 //  height is location along that axis at which to place grid
 //  start,end are corners of a bounding box of the area to engrid
void gedit_render_grid(Grid *g, int prime_axis, mxs_real height,
                       mxs_vector *start, mxs_vector *end);

#endif
