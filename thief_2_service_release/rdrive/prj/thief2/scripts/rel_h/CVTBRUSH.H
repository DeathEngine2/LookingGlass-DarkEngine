/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/editor/RCS/cvtbrush.h 1.4 1998/08/27 08:54:05 CCAROLLO Exp $

/* ----- /-/-/-/-/-/-/-/-/ <<< (((((( /\ )))))) >>> \-\-\-\-\-\-\-\-\ ----- *\
   cvtbrush.h

   export file

\* ----- \-\-\-\-\-\-\-\-\ <<< (((((( \/ )))))) >>> /-/-/-/-/-/-/-/-/ ----- */


#ifndef _CVTBRUSH_H_
#define _CVTBRUSH_H_

#include <wr.h>

EXTERN uchar ConvertFindFinalMedium(uchar medium);
EXTERN void ConvertRemovePersistance(PortalCell *cell, uchar final_medium);
EXTERN void ConvertPersistantCells(uchar added_flags);

#endif
