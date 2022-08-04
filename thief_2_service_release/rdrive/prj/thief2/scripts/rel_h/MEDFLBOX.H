/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/medflbox.h 1.2 1998/03/04 14:22:19 kate Exp $

#ifndef __MEDFLBOX_H
#define __MEDFLBOX_H

#include <gadbox.h>

EXTERN uint edit_flag;

EXTERN uint FlagBoxGetCurrentFlag();
EXTERN void FlagBoxDrawCallback(void *data, LGadBox *vb);
EXTERN void FlagBoxSetMark(int frame,uchar side);
EXTERN void FlagBoxResetMarks(int num_frames);
EXTERN bool FlagBoxAddFlag(ulong value);

#endif
