/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/edlinkst.h 1.3 1997/05/14 13:32:35 mahk Exp $

#ifndef __EDLINKST_H
#define __EDLINKST_H

#include <linkbase.h>
#include <objtype.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

//
// Link Editor Flags (part of the editor descriptor)
//

enum _eLinkEditorFlags 
{
   kLinkEditDoneButton    = (1 << 0),  // Add a "Done" button
   kLinkEditCancelButton  = (1 << 1),  // Add a "Cancel" button
   kLinkEditApplyButton   = (1 << 2),  // Add an "Apply" button
};

#define kLinkEditAllButtons (kLinkEditDoneButton | kLinkEditCancelButton | kLinkEditApplyButton)

// 
// Link Editor Descriptor
//

struct LinkEditorDesc 
{
   char title[32]; // Title string appearing at top of gadget;
   eLinkEditorFlags flags;
};



#endif // __EDLINKST_H
