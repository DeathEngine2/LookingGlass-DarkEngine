/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/mschyacc.h 1.1 1998/04/21 09:58:01 kate Exp $

#ifndef __MSCHYACC_H
#define __MSCHYACC_H

EXTERN void MotSchemaYaccParse(char *schemaFile);
EXTERN void MotSchemaYaccCount(char *schemaFile, int *schemaCount, 
                            int *sampleCount, int *sampleCharCount);
#endif


