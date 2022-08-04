/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/mediface.h 1.2 1998/03/04 11:17:05 kate Exp $

#ifndef __MEDIFACE_H
#define __MEDIFACE_H

#include <gadget.h>

EXTERN LGadRoot *main_root;

#define MOTEDIT_BUTTON_HEIGHT 40

EXTERN void CreateMotionEditorInterface();
EXTERN void DestroyMotionEditorInterface();

EXTERN void MainInterfaceResetBotSlider(int num_frames);
EXTERN void MainInterfaceRefreshFlagBox();
EXTERN void MainInterfaceReset();

#endif
