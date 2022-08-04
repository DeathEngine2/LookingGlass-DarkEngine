/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/stupidui.h 1.2 1996/07/18 22:03:55 mahk Exp $

#ifndef __STUPIDUI_H
#define __STUPIDUI_H

#include <lg.h>
#include <event.h>

//
// This is an editor-only stupid polling interface to the ui.
//

EXTERN void stupid_ui_start(void);
EXTERN void stupid_ui_end(void);

//
// get the next ui event.  returns false iff there are none yet.
//

EXTERN bool get_stupid_ui_event(uiEvent* ev);


#endif // __STUPIDUI_H
