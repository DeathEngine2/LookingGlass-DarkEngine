/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/* objkill.h
**
** Object destruction and callbacks
**
** $Header: r:/prj/cam/libsrc/eos/RCS/objkill.h 1.3 1997/01/06 15:58:26 mahk Exp $
** $Log: objkill.h $
 * Revision 1.3  1997/01/06  15:58:26  mahk
 * Added EXTERNs
 * 
 * Revision 1.2  1996/07/24  12:48:57  DFAN
 * ObjKillInit takes an argument
 * 
 * Revision 1.1  1996/07/10  17:58:58  DFAN
 * Initial revision
 * 
*/

#ifndef _OBJKILL_H
#define _OBJKILL_H

#include <objtype.h>

typedef void (* ObjKillCallback) (ObjID obj, uchar reasons);

// Initialize the system
EXTERN void ObjKillInit ();

// Clear all callbacks
EXTERN void ObjKillClear (void);

// Destroy everything 
EXTERN void ObjKillTerm (void);

// Call whenever an object is killed
EXTERN void ObjKillAddGlobalCallback (ObjKillCallback cb);

// Call whenever an object of this phylum is killed
EXTERN void ObjKillAddPhylumCallback (Phylum phylum, ObjKillCallback cb);

// Call whenever this particular object is killed
// (and delete the callback afterwards)
EXTERN void ObjKillAddIndividualCallback (ObjID obj, ObjKillCallback cb);

// Call all callbacks on the specified object in the order:
// individual, phylum, global
EXTERN ibool ObjKillCallCallbacks (ObjID obj, uchar reasons);

#endif

/*
Local Variables:
typedefs:("ObjID" "ObjKillCallback" "Phylum" "ObjKillCallbackNode" "uchar")
End:
*/



