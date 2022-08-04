/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/pkcreate.h 1.9 1997/09/18 00:08:45 mahk Exp $

#ifndef __PKCREATE_H
#define __PKCREATE_H

#ifdef NETWORK_ENABLED

#include <packets.h>
#include <physics.h>
#include <physbase.h>
#include <wr.h> // for position

enum packetCreateFlags
{
   kCreatePacketPhysical = 1,  // object is physical
};

typedef ulong PacketCreateFlags;

#ifdef __cplusplus 
typedef struct packetCreate : public packetHeader { 
#else
typedef struct packetCreate {
   packetHeader;
#endif 
   GlobalID newGID;    
   int objtype;         // for the new object
   ObjID archetype;     // Archetype
   int owner;          // owner, almost certainly sender, but hey
   int team;           // team of the source object (really sender for player)
   PacketCreateFlags flags; // various flags
   PhysicsState phys;  // current phys
   Position pos;       // location and facing
} packetCreate;

EXTERN void sendCreatePacket(ObjID usID);
EXTERN void RecvCreatePacket(packetCreate *pk);

#define SendCreatePacket(oid) \
   do { \
      if (netWork) \
         sendCreatePacket(oid); \
   } while (0)

#else  // NETWORK_ENABLED

// just null it out
#define SendCreatePacket(oid)

#endif // NETWORK_ENABLED

#endif // __PKCREATE_H
