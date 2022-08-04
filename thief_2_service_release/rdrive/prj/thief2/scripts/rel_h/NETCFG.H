/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/netcfg.h 1.7 1997/01/15 16:29:32 mahk Exp $
// network config stuff

#ifndef __NETCFG_H
#define __NETCFG_H
#include <matrixs.h>

// useful parameters
#ifdef NETWORK_ENABLED

#define MAX_NAME_LEN 64

extern int  netOurTeam;
extern int  netConnect;
extern char netName[];
extern bool netServer;

// proto
bool netParseConfig(void);

// misc stats

// times in ms
extern int netSmoothEnv;  
extern int netHeartRate;

// deadreck params
extern float netDeadReckRad;
extern mxs_ang netDeadReckAng;


// misc freqs and sets and stuff
extern int netSendFreq;
extern bool doNetStats;
extern bool netShowReckoning;

#else

#define netConnect 0
#define netOurTeam 0
#define netName    "Me"
#define netServer  0

#endif

#endif // __NETCFG_H
