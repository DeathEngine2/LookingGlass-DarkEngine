/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/preload.h 1.1 1997/02/14 17:51:00 dc Exp $
// stupid preloading system

#ifndef __PRELOAD_H
#define __PRELOAD_H

EXTERN BOOL preload_data(int type_code, char *name, char *aux);
EXTERN void preload_free_all(void);

// type codes
#define PRELOAD_SOUND 0x01
#define PRELOAD_BIN   0x02

#endif  // __PRELOAD_H
