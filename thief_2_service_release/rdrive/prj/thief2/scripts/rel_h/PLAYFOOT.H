/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/playfoot.h 1.1 1998/06/04 19:07:15 mahk Exp $
#pragma once  
#ifndef __FOOTSTEP_H
#define __FOOTSTEP_H

EXTERN void player_footstep_init(void); 
EXTERN void player_footstep_trigger(int texture, float vel);
EXTERN void player_foot_fell(struct mxs_vector *pos);
EXTERN void player_footstep_run(int dt);

EXTERN BOOL foot_sounds;
EXTERN BOOL feet_in_editor;

#endif // __FOOTSTEP_H
