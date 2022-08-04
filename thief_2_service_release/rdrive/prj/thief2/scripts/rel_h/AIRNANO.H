/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/airnano.h 1.4 1997/06/12 16:22:56 cnorden Exp $

#ifndef __AIRNANO_H
#define __AIRNANO_H

#include <nanodef.h>


#define NUM_NOUNS  7
#define NUM_ADJS   5
#define NUM_COMBOS 10

// Globals

// Public Functions
EXTERN void AirNanoInit();
EXTERN bool AirNanoSetCurrMacro(int index);
EXTERN int AirNanoGetCurrMacro(void);

EXTERN NanoNoun *AirNanoGetNoun();
EXTERN int AirNanoGetNumAdj();
EXTERN NanoAdj *AirNanoGetAdj(int index);
EXTERN int AirNanoGetCost();

#endif // __AIRNANO_H
