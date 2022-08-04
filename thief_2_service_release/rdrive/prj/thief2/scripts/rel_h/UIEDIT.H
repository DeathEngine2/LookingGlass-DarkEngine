/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/editor/RCS/uiedit.h 1.7 1998/09/18 22:33:31 mahk Exp $

#ifndef __UIEDIT_H
#define __UIEDIT_H
#include <guistyle.h>
#include <uigame.h>

EXTERN void EditorCreateGUI(void);
EXTERN void EditorDestroyGUI(void);

EXTERN void uieditStyleSetup(void);
EXTERN void uieditStyleCleanup(void); 
EXTERN void uieditRedrawAll(void);

#define uieditFixupColor guiScreenColor
EXTERN void redraw_all_cmd(void);

   
#endif // __UIEDIT_H





