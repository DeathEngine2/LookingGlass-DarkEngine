/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/plyrmed.h 1.4 1998/08/21 09:28:21 CCAROLLO Exp $
#ifndef __PLYRMED_H
#define __PLYRMED_H
#include <objtype.h>

//
// Given an object, and an assumption about what medium it was in last,
// play a sound effect appropriate to its medium, and to medium transitions
//
// Returns the object's new medium.
//

EXTERN int play_medium_sound(ObjID obj, int last_medium, int velocity_2);
EXTERN int play_medium_sound_known(ObjID obj, int last_medium, int new_medium, int velocity_2);

//
// load medium sounds from a cfg var
//

EXTERN void load_medium_sounds(void);

#endif // __PLYRMED_H
