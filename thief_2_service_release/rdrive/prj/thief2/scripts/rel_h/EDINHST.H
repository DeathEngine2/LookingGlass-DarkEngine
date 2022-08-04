/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/edinhst.h 1.3 1997/12/02 15:15:16 CCAROLLO Exp $

//
// Inheritance editor structures
//

#ifndef __EDINHST_H
#define __EDINHST_H

#include <objtype.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <commctrl.h>

//
// Inheritance Editor Flags (part of the editor descriptor)
//

enum _eInheritanceEditorFlags 
{
   kInheritanceEditNone = 0,     // no flags for now
};

// 
// Inheritance Editor Descriptor
//

struct InheritanceEditorDesc 
{
   char title[32]; // Title string appearing at top of gadget;
   eInheritanceEditorFlags flags;
};

//
// Inheritance Editor
//

struct InheritanceEditor
{
   InheritanceEditorDesc   editdesc;
   int                     mode;          // are we viewing archetypes or metaproperties?
   BOOL                    in_progress;
   BOOL                    show_concrete;
   ObjID                   root_archetype;
   HWND                    hWnd;
   HWND                    hMainWnd;
   HINSTANCE               hInst;
   HWND                    hWndTree;
   HWND                    hWndCreateButton;    // so we can disable it later
   HTREEITEM               hRootItem;
   ObjID                   sel_archetype, sel_metaproperty;    // what were they looking at last?
   BOOL                    dragging;      // are we dragging something?
   HTREEITEM               drag_item;     // what are we dragging?
   HFONT                   hWndFont;
};

#endif // __EDINHST_H
