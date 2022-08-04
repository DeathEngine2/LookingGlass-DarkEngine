/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/pkphysic.h 1.5 1997/09/18 00:08:49 mahk Exp $

#ifndef __PKPHYSIC_H
#define __PKPHYSIC_H

#ifdef NETWORK_ENABLED

#include <packets.h>
#include <physics.h>
#include <physbase.h>
#include <globalid.h>
#include <wr.h> // for Position

typedef struct {
   packetHeader;
   GlobalID ourGID;
   PhysicsState phys;
   Position pos;
} packetPhysics;

void sendPhysicsPacket(ObjID usID);
void RecvPhysicsPacket(packetPhysics *pk);

#define SendPhysicsPacket(oid) \
   do { \
      if (netWork) \
         sendPhysicsPacket(oid); \
   } while (0)

#else  // NETWORK_ENABLED

// just null it out
#define SendPhysicsPacket(oid)

#endif // NETWORK_ENABLED

#endif // __PKPHYSIC_H

