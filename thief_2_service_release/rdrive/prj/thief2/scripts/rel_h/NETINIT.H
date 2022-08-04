/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/netinit.h 1.3 1996/10/15 01:29:56 dc Exp $
// woo hoo

#ifndef __NETINIT_H
#define __NETINIT_H

#define netIsCool     0
#define netJoinFail  -1
#define netInitFail  -2
#define netDisabled  -3

#ifdef NETWORK_ENABLED

int  NetStartup(void);
bool NetShutdown(void);

extern int local_frame_id;

// the app stuff
bool netReadFrame(void);

#else // NETWORK_ENABLED
// return the startup didnt happen
#define NetStartup()  (netDisabled)
// these two can just be nulled out
#define NetShutdown()
#define netReadFrame()
#endif

#endif // __NETINIT_H
