/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/frobsys.h 1.2 1997/09/03 23:51:37 dc Exp $

#ifndef __FROBSYS_H
#define __FROBSYS_H

#include <objtype.h>

// OBJ_NULL means no object focused on/whatever
// currently focused on objects - set them in your xxxxgame code
EXTERN ObjID cur_inv_focus_objid;
EXTERN ObjID cur_world_focus_objid;

// what obj are we now frobbing, is it in_inv
// this is since commands cant take multiple args, basically
EXTERN ObjID cur_frob_obj;
EXTERN BOOL  cur_frob_in_inv;

// are we "searching" for a frob object - ie. mouse/key down waiting for up
EXTERN BOOL  frob_search;

// say that yes indeed, i want a frobsystem
EXTERN void frobsysInit(void);

// is this object frobbable? (in_inv is inv or world)
EXTERN BOOL is_obj_frobbable(int o_id, BOOL in_inv);

// these are the commands, rarely will anyone call them, the idea is
// that they will be used internally by frobsys since people will bind
// interface keys to them, so, ah, probably you dont need them, right
EXTERN void do_world_frob_cmd(int o_id);
EXTERN void do_inv_frob_cmd(int o_id);

#endif  //  __FROBSYS_H
