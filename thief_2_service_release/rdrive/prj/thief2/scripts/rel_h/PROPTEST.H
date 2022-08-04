/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/proptest.h 1.2 1998/04/12 17:16:29 mahk Exp $

#ifndef __PROPTEST_H
#define __PROPTEST_H

EXTERN void proptest_init_real(void);
EXTERN void proptest_term_real(void);

#ifdef EDITOR
#define proptest_init() proptest_init_real()
#define proptest_term() proptest_term_real()
#else
#define proptest_init() 
#define proptest_term() 
#endif




#endif // __PROPTEST_H
