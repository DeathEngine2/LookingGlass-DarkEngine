/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/filemenu.h 1.1 1997/06/26 14:44:01 mahk Exp $

#ifndef __FILEMENU_H
#define __FILEMENU_H

////////////////////////////////////////////////////////////
// FILE GUI API
//

//
// File dialog open modes
//

enum eFileMenuMode 
{
   kFileMenuLoad,
   kFileMenuSave,
};

typedef enum eFileMenuMode eFileMenuMode;

//
// filter for file names
//

struct sFileMenuFilter 
{
   char* text;  // text filter description
   char* pattern; // wildcarded file patter
};

typedef struct sFileMenuFilter sFileMenuFilter;

// 
// put up a file dialog, returns the selected file name
// takes a null-terminated list of filters
//

EXTERN char* FileDialog(eFileMenuMode mode, sFileMenuFilter* pFilters, const char* defaultExtension, char* fnamebuf, int buflen);

//
// Bring up a little menu of load and save buttons
// 

EXTERN void FileMenu(void);


#endif // __FILEMENU_H
