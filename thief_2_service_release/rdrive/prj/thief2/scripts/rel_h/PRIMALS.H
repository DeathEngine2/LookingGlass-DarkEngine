/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/primals.h 1.1 1997/07/13 00:04:21 dc Exp $
// structures for primal brush system/setup

#ifndef __PRIMALS_H
#define __PRIMALS_H

#include <matrixs.h>

typedef struct {
   int points, edges, faces;
   int face_stride;      // number of edge or face entries per face, counting bonus -1 at end
   mxs_vector *pt_array; 
   int *edge_list;
   int *face_pts_list;
   int *face_edge_list;
} primalInfo;

#endif  // __PRIMALS_H
