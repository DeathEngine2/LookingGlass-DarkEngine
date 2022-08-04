/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/motion/RCS/motdmng_.h 1.2 1998/07/12 10:34:38 JUSTIN Exp $

#ifndef __MOTDMNG__H
#define __MOTDMNG__H

#include <resapi.h>

typedef struct 
{
   int numEntries;
   ulong offset[1];
} MotDataCTable;

typedef IRes *MotDataHandle;

EXTERN MotDataHandle *motDataHandles;

#define MotDmngeIsLocked(mot_num) (motDataHandles[mot_num]!=NULL)
#define MotDmngeHandle(mot_num) (motDataHandles[mot_num])


#endif
