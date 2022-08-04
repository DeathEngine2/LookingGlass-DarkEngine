/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/netobj.h 1.1 1997/09/18 00:06:54 mahk Exp $

#ifndef __NETOBJ_H
#define __NETOBJ_H
#include <objtype.h>

////////////////////////////////////////////////////////////
// Networked Object Support
//
// Handles attaching/detaching objects from net game.
//
// 

typedef ulong eDetachMode;

enum eDetachMode_ 
{
   kDetachObjDelete,
   kDetachObjKeep,
};

EXTERN BOOL NetObjAttachAll(int PID);
EXTERN BOOL NetObjDetachAll(eDetachMode mode);
EXTERN void NetObjInitObj(ObjID obj);

#endif // __NETOBJ_H
