/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/editor/RCS/objedit.h 1.3 1998/09/17 02:56:40 dc Exp $

#ifndef __OBJEDIT_H
#define __OBJEDIT_H

#include <objtype.h>

#ifdef __cplusplus
#include <str.h>
#define ObjWarnName(obj) ((const char *)cStr(ObjEditName(obj)))
#else
#define ObjWarnName ObjEditName
#endif

//
// ObjEditName
//
// Get an object's printable name for editing/debugging
//

EXTERN const char* ObjEditName(ObjID obj);

//
// ObjEditNamed
//
// Gets the object described by a string
//

EXTERN ObjID  EditGetObjNamed(const char* name);

//
// ObjEditInit
//
// Initialize object editing
//

EXTERN void ObjEditInit(void);

#endif // __OBJEDIT_H
