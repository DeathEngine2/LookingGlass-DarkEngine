/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/appnet.h 1.3 1996/10/27 20:52:50 buzzard Exp $

// application specific network stuff for per frame code
// ie the app must have these functions to use netFrame

#ifndef __APPNET_H
#define __APPNET_H

#include <dpshell.h>

// returns whether it successfully read the sys packet
bool netappReadSysPacket(netSysPacketInfo *sysInf);

// returns whether or not it successfully parsed the packet
bool netappParsePacket(int from, uchar *buffer, ulong len);

// return number of packets sent
int netappSendPackets(void);

#ifdef NETWORK_ENABLED
// parse the network env, find players, so on
void appnetParseEnv(void);
#else
#define appnetParseEnv()
#endif

#endif // __APPNET_H
