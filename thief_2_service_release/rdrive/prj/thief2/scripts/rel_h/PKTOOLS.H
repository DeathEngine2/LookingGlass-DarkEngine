/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/pktools.h 1.4 1997/09/18 00:08:52 mahk Exp $

#ifndef __PKTOOLS_H
#define __PKTOOLS_H

#include <objtype.h>
#include <physics.h>
#include <packets.h>

bool _pkBuildFullPhys(PhysicsState *where, ObjID usID);
bool _pkBuildPhys(PhysicsState *where, ObjID usID);
bool _pkParsePhys(PhysicsState *where, ObjID usID);

bool _pkBuildPos(struct Position *pos, ObjID usID);
bool _pkParsePos(struct Position *pos, ObjID usID);


#endif // __PKTOOLS_H

