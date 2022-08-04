/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/editinh.h 1.2 1997/12/02 15:15:54 CCAROLLO Exp $
// Inheritance editor API

#ifndef __EDITINH_H
#define __EDITINH_H

#include <edinhtyp.h>
#include <objtype.h>

EXTERN InheritanceEditor* InheritanceEditorFancyCreate(ObjID id, ObjID root, BOOL concrete, BOOL to_obj, InheritanceEditorDesc* editdesc);
EXTERN InheritanceEditor* InheritanceEditorCreate(ObjID id, InheritanceEditorDesc* editdesc);
EXTERN void InheritanceEditorDestroy(InheritanceEditor* ed);

#endif // __EDITINH_H
