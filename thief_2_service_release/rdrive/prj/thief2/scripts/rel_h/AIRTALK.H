/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/airtalk.h 1.3 1997/01/18 17:15:10 mahk Exp $

#ifndef __AIRTALK_H
#define __AIRTALK_H

#define AIRTALK_STRING  0
#define AIRTALK_DEATH   1
#define AIRTALK_CAST    2
#define AIRTALK_REPORT  3
#define AIRTALK_GESTURE 4

// generic data values
#define AIRTALK_DATA_ATTRIB   (1<<31)
#define AIRTALK_DATA_DISTANCE (1<<30)

// generic "format a message from this stuff" kind of call
void airtalk_info(int code, int objSrc, int objDst, int data, char *s);

// generate objects or attribute strings
void _airtalk_attrib(ObjID obj, char *s);
void _airtalk_object(ObjID obj, char *s);

#endif // __AIRTALK_H
