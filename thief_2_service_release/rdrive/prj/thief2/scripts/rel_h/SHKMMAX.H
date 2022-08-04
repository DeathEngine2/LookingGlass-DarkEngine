/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkmmax.h 1.1 1999/06/06 19:16:02 XEMU Exp $

#ifndef __SHKMMAX_H
#define __SHKMMAX_H

EXTERN void minimax_setup(void* boardpos, uint pos_siz, uchar depth, bool minimize,
   int (*evaluator)(void*), bool (*generate)(void*,int,bool),
   bool (*horizon)(void*));
EXTERN void minimax_step(void);
EXTERN bool minimax_done(void);
EXTERN void minimax_get_result(int* value, char* which);
EXTERN void fstack_init();

#endif