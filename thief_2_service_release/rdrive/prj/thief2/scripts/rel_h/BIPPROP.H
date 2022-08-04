/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Source: r:/prj/cam/src/RCS/bipprop.h $
// $Author: kate $
// $Date: 1997/08/24 10:54:38 $
// $Revision: 1.4 $
//
// Biped property interfaces

#ifndef BIPPROP_H
#define BIPPROP_H

#include <property.h>
#include <biptype.h>

//------------------------------------------------------------
// Biped length property
//
F_DECLARE_INTERFACE(IBipedLengthsProperty);


// declare the IBipedLengthsProperty interface
#undef INTERFACE
#define INTERFACE IBipedLengthsProperty
DECLARE_COMPLEX_PROPERTY(BipedLengths,BipedLengths);

// Declare the "factory function" to create an IBipedLengthsProperty
DECLARE_CREATOR(BipedLengths);

#define PROP_BIPED_LENGTHS_NAME "BIPED_LENGTHS"

EXTERN IBipedLengthsProperty *BipedLengthsPropertyInit();


//------------------------------------------------------------
// Biped Property
//
F_DECLARE_INTERFACE(IBipedProperty);
#undef INTERFACE
#define INTERFACE IBipedProperty

// declare the IBipedProperty interface
DECLARE_COMPLEX_PROPERTY(Biped,Biped);

#define PROP_BIPED_NAME "BIPED"

EXTERN IBipedProperty *BipedPropertyInit(int *obj2biparray, 
                                         struct sCompactArrayProp *arrayprop);

#endif // BIPPROP_H
















