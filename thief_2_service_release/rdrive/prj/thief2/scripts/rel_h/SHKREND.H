/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkrend.h 1.5 1999/01/17 17:46:40 JON Exp $

#ifndef __SHOCKREND_H
#define __SHOCKREND_H

EXTERN ObjID g_distPickObj;

EXTERN void shock_init_object_rend(void);
EXTERN void shock_term_object_rend(void);
EXTERN void shock_init_renderer(void);
EXTERN void shock_term_renderer(void);
EXTERN void shock_pick_reset(void);

#endif // __SHOCKREND_H
