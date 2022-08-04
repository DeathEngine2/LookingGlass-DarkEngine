/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/frobbase.h 1.1 1997/07/27 22:41:15 dc Exp $
// internal definitions

#ifndef __FROBBASE_H
#define __FROBBASE_H

#include <osystype.h>

#define MAX_FROB_CMDS 4

typedef struct {
   Label cmds[MAX_FROB_CMDS];
} sFrobCmd;

#endif  // __FROBBASE_H
