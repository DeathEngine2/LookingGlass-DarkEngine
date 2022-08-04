/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/simpwrap.h 1.1 1997/12/02 23:15:42 dc Exp $
// wrappers around darkdlgs dll "simple" menus and other ui tools

#ifndef __SIMPWRAP_H
#define __SIMPWRAP_H

typedef const char* menustring;

// bring up menu of the strings in list, of which there are cnt, titled Title
// return -1 if no pick, else the picked item
EXTERN int PickFromStringList(char *title, const menustring* list, int cnt);

#endif  // __SIMPWRAP_H
