/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/brobjpro.h 1.1 1997/10/20 20:28:13 dc Exp $
// expose brush property info to brush/editor system
// mostly for objects which have props which make them behave like other brush types

#ifndef __BROBJPRO_H
#define __BROBJPRO_H

#include <objtype.h>

// returns <0.0 if no light on obj, else 0->n light level
EXTERN float brObjProp_getLightLevel(ObjID o_id);

// returns the br filter code for the object
EXTERN int   brObjProp_getFilterType(ObjID o_id);

#endif  // __BROBJPRO_H
