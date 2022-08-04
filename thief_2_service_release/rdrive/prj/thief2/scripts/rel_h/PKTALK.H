/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/pktalk.h 1.3 1997/09/18 00:08:51 mahk Exp $

#ifndef __PKTALK_H
#define __PKTALK_H

#ifdef NETWORK_ENABLED

#include <packets.h>
#include <globalid.h>

typedef struct {
   packetHeader;
   GlobalID srcGID;
} packetTalk;

void sendTalkPacket(ObjID Talker, char *txt);
void RecvTalkPacket(packetTalk *pk);

#define SendTalkPacket(src,dst) \
   do { \
      if (netWork) \
         sendTalkPacket(src,dst); \
   } while (0)

#else  // NETWORK_ENABLED

// just null this out
#define SendTalkPacket(src,dst)

#endif // NETWORK_ENABLED

#endif // __PKTALK_H

