/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkiftul.h 1.3 1999/01/26 22:40:01 XEMU Exp $

#ifndef __SHKIFTUL_H
#define __SHKIFTUL_H

EXTERN void ShockMFDNavButtonsInit();
EXTERN void ShockMFDNavButtonsTerm();
EXTERN void ShockMFDNavButtonsBuild(Rect *r);
EXTERN void ShockMFDNavButtonsDestroy();
EXTERN void ShockMFDNavButtonsDraw();

EXTERN void SetLeftMFDRect(int which, Rect full_rect);
EXTERN void SetRightMFDRect(int which, Rect full_rect);

#endif
