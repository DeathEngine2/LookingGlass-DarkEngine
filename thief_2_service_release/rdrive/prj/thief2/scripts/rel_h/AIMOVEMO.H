/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/aimovemo.h 1.4 1997/10/04 17:10:49 TOML Exp $

// This file defines the type returned by
// aiext.h : int   AIGetMoveMode(ObjID objWithAI);
// a.h             A::GetMoveMode()

#ifndef __AIMOVEMO_H
#define __AIMOVEMO_H

#define AI_MOVE_MODE_ERROR      0
#define AI_MOVE_MODE_CASUAL     1
#define AI_MOVE_MODE_RUNNING    2
#define AI_MOVE_MODE_SEARCHING  3
#define AI_MOVE_MODE_COMBAT     4
#define AI_MOVE_MODE_SLEEP      5

#endif
