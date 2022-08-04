/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/csgbbox.h 1.1 1997/05/04 18:25:41 buzzard Exp $

extern void compute_poly_bbox(PortalPolygon *poly, BspVertex *minv, BspVertex *maxv);
extern void compute_ph_bbox(PortalPolyhedron *poly, BspVertex *minv, BspVertex *maxv);
