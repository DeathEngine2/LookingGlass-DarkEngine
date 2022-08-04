/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

////////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/RCS/linkdraw.h 1.3 1998/04/06 15:29:27 CCAROLLO Exp $
//
// Link-drawing system
//

#ifndef __LINKDRAW_H
#define __LINKDRAW_H

#include <objtype.h>
#include <linktype.h>

EXTERN void InitDrawnRelations();
EXTERN void TermDrawnRelations();
EXTERN void ResetDrawnRelations();

EXTERN void AddDrawnRelation(const char *name, ubyte r, ubyte g, ubyte b);
EXTERN void AddDrawnRelationID(RelationID relationID, ubyte r, ubyte g, ubyte b);
EXTERN void RemoveDrawnRelation(const char *name);
EXTERN void RemoveDrawnRelationID(RelationID relationID);

EXTERN void DrawRelations();
EXTERN BOOL ObjHasDrawnLinks(ObjID objID);

#endif // __LINKDRAW_H
