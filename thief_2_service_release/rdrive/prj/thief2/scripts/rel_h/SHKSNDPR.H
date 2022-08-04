/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/shksndpr.h 1.2 1998/04/13 13:13:09 XEMU Exp $

//#include <property.h>
#include <propdef.h>
//#include <editbr.h>

// Sound attached to an object

#define PROP_OBJ_SOUND_NAME "ObjSoundName" 

// Property stuff

F_DECLARE_INTERFACE(IObjSoundNameProperty);

#undef INTERFACE
#define INTERFACE IObjSoundNameProperty

DECLARE_PROPERTY_INTERFACE(IObjSoundNameProperty)
{
   DECLARE_UNKNOWN_PURE();                // IUnknown methods 
   DECLARE_PROPERTY_PURE();               // IProperty methods
   DECLARE_PROPERTY_ACCESSORS(Label *);  // Type-specific accessors, by reference
};

//EXTERN IObjSoundNameProperty *g_ObjSoundNameProperty;

EXTERN void ObjSoundNamePropInit(void);
