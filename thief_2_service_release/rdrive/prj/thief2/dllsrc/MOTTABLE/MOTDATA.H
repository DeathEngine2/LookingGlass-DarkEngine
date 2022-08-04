/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/t2repos/thief2/dllsrc/mottable/motdata.h,v 1.1 1998/01/08 15:50:01 kate Exp $

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
