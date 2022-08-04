/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Source: r:/prj/cam/src/RCS/motbase.h $
// $Author: kate $
// $Date: 1997/09/03 17:00:58 $
// $Revision: 1.5 $
//
// Motion numbers

#ifndef __MOTBASE_H
#define __MOTBASE_H

#include <motion.h>

#define MP_UPDATE_FLAG_FAKE (1<<MP_RESERVED_CFLAG_SHIFT)

// motion numbers
#define MOT_NONE -1

#define MOT_STAND 0

#if 0 // obsolete.  see motdesc.[ch]
#define MOT_WALK 2
#define MOT_CLIMB_RIGHT 25
#define MOT_CLIMB_LEFT 26
#define MOT_WALK_RIGHT 28
#define MOT_WALK_LEFT 29
#define MOT_DESCEND_RIGHT 31
#define MOT_DESCEND_LEFT 32
#endif

// motion play priorities
#define MOT_PRI_DEFAULT 10

#endif // __MOTBASE_H
