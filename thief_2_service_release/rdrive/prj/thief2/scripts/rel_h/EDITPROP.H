/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/editprop.h 1.4 1997/04/21 23:09:49 mahk Exp $

#ifndef __EDITPROP_H
#define __EDITPROP_H

#include <comtools.h>
#include <objtype.h>

//
// Object property editor UI
//

F_DECLARE_INTERFACE(IProperty);

typedef struct PropertyEditor PropertyEditor;
typedef struct PropEditEvent PropEditEvent;

typedef ulong ePropEditEventType;

//
// Callback stuff - one callback per PropertyEditor, please
//

typedef struct PropEditEvent PropEditEvent;
typedef void* PropEditCBData;
typedef void (*PropEditCB)(PropEditEvent* event, PropEditCBData data);

// Create a property editor for a property
EXTERN PropertyEditor* PropertyEditorCreate(IProperty* prop, ObjID objid);

// Install a callback for a property editor
EXTERN void PropertyEditorInstallCallback(PropertyEditor* ped, PropEditCB cb, PropEditCBData data);

// Destroy a property editor
EXTERN void PropertyEditorDestroy(PropertyEditor *ped);


#endif   // __EDITPROP_H
