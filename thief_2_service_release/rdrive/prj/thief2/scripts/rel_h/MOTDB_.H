/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/motdb_.h 1.1 1998/04/20 15:51:52 kate Exp $

// utilities for building motion database

#ifndef __MOTDB__H
#define __MOTDB__H

#include <label.h>
#include <motdbtyp.h>
#include <fcytagdb.h>


EXTERN void MotDBCreate(int nActors);
EXTERN void MotDBRegisterTag(Label *pName, sTagInfo *pInfo);
EXTERN void MotDBAddSchema(sMotSchemaDesc *pSchema);

#endif // __MOTDB__H
