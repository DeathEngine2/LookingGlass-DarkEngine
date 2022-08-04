/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/editlink.h 1.2 1997/09/05 14:02:24 mahk Exp $

#ifndef __EDITLINK_H
#define __EDITLINK_H

#include <edlnktyp.h>
#include <objtype.h>
#include <linktype.h>

EXTERN LinkEditor* LinkEditorCreate(ObjID objid_src, ObjID objid_dest, RelationID relid, LinkEditorDesc* editdesc);
EXTERN void LinkEditorDestroy(LinkEditor* ed);

EXTERN BOOL LinkEditorShowAllLinks(BOOL newval);

#endif // __EDITLINK_H
