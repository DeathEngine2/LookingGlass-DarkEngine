/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/pkhndoff.h 1.2 1997/09/18 00:08:48 mahk Exp $

#ifndef __PKHNDOFF_H
#define __PKHNDOFF_H

#ifdef NETWORK_ENABLED

#include <packets.h>
#include <globalid.h>

typedef struct {
   packetHeader;
   GlobalID srcGID;
   int newOwner;
} packetHandoff;

void sendHandoffPacket(ObjID Handoffer, int new_owner);
void RecvHandoffPacket(packetHandoff *pk);

#define SendHandoffPacket(who,newOwn) \
   do { \
      if (netWork) \
         sendHandoffPacket(who,newOwn); \
   } while (0)

#else  // NETWORK_ENABLED

// just null this out
#define SendHandoffPacket(who,newown)

#endif // NETWORK_ENABLED

#endif // __PKHNDOFF_H

