/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/pklogin.h 1.3 1997/09/18 00:08:48 mahk Exp $

#ifndef __PKLOGIN_H
#define __PKLOGIN_H

#ifdef NETWORK_ENABLED

#include <packets.h>
#include <physics.h>
#include <globalid.h>

typedef struct {
   packetHeader;
   int whoami;
} packetLogin;

void sendLoginPacket(void);
void RecvLoginPacket(packetLogin *pk);

#define SendLoginPacket() \
   do { \
      if (netWork) \
         sendLoginPacket(); \
   } while (0)

#else  // NETWORK_ENABLED

// just null it out
#define SendLoginPacket()

#endif // NETWORK_ENABLED

#endif // __PKLOGIN_H
