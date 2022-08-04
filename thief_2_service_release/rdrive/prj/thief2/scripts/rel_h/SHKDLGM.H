/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/shkdlgm.h 1.1 1997/11/26 13:03:48 XEMU Exp $
#ifndef __SHKDLGM_H
#define __SHKDLGM_H

DEFINE_LG_GUID(LOOPID_DialogMode, 0xce);

EXTERN struct sLoopModeDesc DialogLoopMode;

EXTERN struct sLoopInstantiator* GetDialogLoopInst();

#endif 
