/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/sdescold.h 1.1 1997/12/18 23:06:37 mahk Exp $

#ifndef SDESC_H
#define SDESC_H

#include <sdestype.h>

//
// Generic structure description API
//

// lookup a field by name
EXTERN const sFieldDesc* StructDescFindField(const sStructDesc* desc, const char* field);


// converts a field in a struct to a string
EXTERN BOOL StructFieldToString(const void *struc, const sStructDesc* desc, const sFieldDesc* field, char* dest);

// converts a string to a field in a struct
EXTERN BOOL StructStringToField(void *struc, const sStructDesc* desc, const sFieldDesc* field, char* src);

// actually sets a field in a struct
EXTERN BOOL StructSetField(void* struc, const sStructDesc* desc, const sFieldDesc* field, const void* val);

// reads a field from a struct
EXTERN BOOL StructGetField(const void* struc, const sStructDesc* desc, const sFieldDesc* field, void* val);

// dumps a struct to the monochrome
EXTERN void StructDumpStruct(const void* struc, const sStructDesc* desc);

// Register a struct desc in the global repository. 
EXTERN void StructDescRegister(const sStructDesc* desc);

// Look up a structdesc by name
EXTERN BOOL StructDescLookup(const char* name, const sStructDesc* (*desc));

// Clear the registry of structdescs, and free its memory.
EXTERN void StructDescClearRegistry(void);

//
// "Simple" structure support.  Simple structures have one field. 
//

// Is this StructDesc simple?
EXTERN BOOL StructDescIsSimple(const sStructDesc* desc);

// if the struct is simple, output it as a string, if not, output "..."
// returns whether or not it is simple
EXTERN BOOL StructToSimpleString(const void* struc, const sStructDesc* desc, char* out);

// if the struct is simple, read in a string describing its value, if not, do nothing.
// If the string is poorly formatted, mutates it to the nearest match
// returns whether or not it is simpleo
EXTERN BOOL StructFromSimpleString(void* struc, const sStructDesc* desc, char* in);


EXTERN BOOL StructToFullString(const void* struc, const sStructDesc* desc, char* out, int len);
EXTERN BOOL StructFromFullString(void* struc, const sStructDesc* desc, const char* in);

#endif   // SDESC_H

