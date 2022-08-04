/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/ged_undo.h 1.1 1997/07/20 23:49:55 dc Exp $

#ifndef __GED_UNDO_H
#define __GED_UNDO_H

#include <editbrs.h>

// command interface for gedit init
EXTERN void gedundoCommandRegister(void);

///////////////////
// various undo support

// classify the delta between new and old relative to base
EXTERN BOOL gedundo_check_brush_delta(editBrush *new_ver, editBrush *old_ver, editBrush *base_ver);

// check the textures between a newly restored undo/redo brush and current existing one
EXTERN BOOL gedundo_check_texture_delta(editBrush *new_ver, editBrush *old_ver);
// if the check returned true, call this with the new brush to make it so
EXTERN void gedundo_do_texture_delta(editBrush *us);

#endif  // __GED_UNDO_H
