/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/editmode.h 1.5 1998/04/24 14:13:19 TOML Exp $
#ifndef __EDITMODE_H
#define __EDITMODE_H

////////////////////////////////////////////////////////////
// EDIT MODE DESCRIPTION
//
DEFINE_LG_GUID(LOOPID_EditMode, 0x22);

EXTERN struct sLoopModeDesc EditLoopMode;

//
// Editor minor modes
//


typedef enum 
{
   mmEditBrush,
   mmEditObjs,
   mmEditNoChange = -1,
   mmEditDefault = mmEditBrush,
} EditMinorMode;



typedef struct EditModeDesc
{
   struct sScrnMode* scrnmode; 
} EditModeDesc;

////////////////////////////////////////////////////////////
// GAME-SPECIFIC CLIENT INSTANTIATION
//
// Plugs a client (or a loopmode's clients) into editor mode.  Only the last call matters.
// 

EXTERN void EditModeSetGameSpecClient(const GUID* clientID);

//////////////////////////////////////////////////////////////
// Instantiate the Editor mode.
// a "null" descriptor will leave values unchanged from last time, 
// or use defaults if there was no last time.
//
EXTERN struct sLoopInstantiator* DescribeEditMode(EditMinorMode minorMode, EditModeDesc* desc);

// 
// Context data for starting the editor mode
//

  
////////////////////////////////////////////////////////////
// EDITOR LOOP CLIENT DESCRIPTION
//

DEFINE_LG_GUID(LOOPID_Editor, 0x2a);
EXTERN struct sLoopClientDesc EditorLoopClientDesc;



 
#endif // __EDITMODE_H
