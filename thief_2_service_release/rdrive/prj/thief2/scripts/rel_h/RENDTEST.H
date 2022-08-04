/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/rendtest.h 1.1 1997/08/12 07:48:01 dc Exp $

#ifndef __RENDTEST_H
#define __RENDTEST_H

#ifndef SHIP
// the rendtest command itself
EXTERN void do_rendtest_cmd(int cnt);
EXTERN void do_rendtest_rerun_cmd(char *fname);
#endif  // SHIP

#endif  // __RENDTEST_H
