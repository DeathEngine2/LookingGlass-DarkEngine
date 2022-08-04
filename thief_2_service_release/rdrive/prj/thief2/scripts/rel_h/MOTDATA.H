/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/motdata.h 1.2 1998/01/07 18:37:08 kate Exp $

#ifndef __MOTDATA_H
#define __MOTDATA_H

#include <mottype.h>

typedef struct
{
   char *name;
   int type;
   BOOL neckFixed;
   int blendType;
   int motionNum;
} MotDesc;
   
EXTERN MotDesc g_aMotDescs[];

EXTERN int g_NumMotDescs;

#endif
