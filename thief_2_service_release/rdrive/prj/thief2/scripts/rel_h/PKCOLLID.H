/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/pkcollid.h 1.5 1997/09/18 00:08:38 mahk Exp $

#ifndef __PKCOLLID_H
#define __PKCOLLID_H

#ifdef NETWORK_ENABLED

#include <packets.h>
#include <physics.h>
#include <globalid.h>

typedef struct {
   packetHeader;
   GlobalID obj1;
   GlobalID obj2;
   int bits;
   int data;
} packetCollide;

void sendCollidePacket(ObjID o1, ObjID o2, int bits, int data);
void RecvCollidePacket(packetCollide *pk);

#define SendCollidePacket(oid1, oid2, bits, data) \
   do { \
      if (netWork) \
         sendCollidePacket(oid1, oid2, bits, data); \
   } while (0)

#else  // NETWORK_ENABLED

// just null it out
#define SendCollidePacket(oid1, oid2, bits, data)

#endif // NETWORK_ENABLED

#endif // __PKCOLLID_H

