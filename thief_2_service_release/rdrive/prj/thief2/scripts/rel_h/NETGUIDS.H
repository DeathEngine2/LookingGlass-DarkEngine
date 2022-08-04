/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/netguids.h 1.3 1998/10/02 17:28:37 JUSTIN Exp $

// Defines the table of GUIDs that might register parsers with the
// network manager.  (i.e. INetManager:RegisterMessageParser).  Note
// that it actually defines the table, rather than just declaring it,
// since the only source file that includes this should be netman.h.
// I didn't put the table inside of netman.cpp, since I would like
// people to be able to add to the table, without having to modify
// netman.cpp.

#include <comtools.h>
#include <netmniid.h>
#include <propguid.h>
#include <aiguid.h>
#include <chatiid.h>
#include <plyrloop.h>
#include <frobguid.h>
#include <appnetid.h>
#include <phnetid.h>

// The offset of a GUID in this table is its OneByteGUID.
const IID *g_MsgParserComponents[] = {
   &GUID_NULL,  // 0 is the NULL OneByteGUID
   &IID_INetManager,
   &IID_IObjectSystem,
   &IID_IPropertyManager,
   &IID_IAIManager,
   &IID_IChat,
   &GUID_Frob,
   &GUID_AppNet,
   &GUID_PhysNet,
   &LOOPID_Player,  // PlayerLoop client uses the fact that the guid need not by an IID.
};

