//		B2TYPES.H		Babl2 types and disk formats
//		Rex E. Bradford (REX)
/*
* $Header: x:/prj/tech/libsrc/babl2/RCS/b2types.h 1.11 1996/10/23 11:08:25 TJS Exp $
* $Log: b2types.h $
 * Revision 1.11  1996/10/23  11:08:25  TJS
 * 8 menu clauses is not enough for such as WE!
 * 
 * Revision 1.10  1994/05/19  10:34:53  rex
 * Changed line debug struct
 * 
 * Revision 1.9  1993/12/13  17:38:50  rex
 * Changed menu flagType from short to ushort, 0x8000 now means default
 * 
 * Revision 1.8  1993/10/29  15:28:47  rex
 * Changed includes to angle brackets
 * 
 * Revision 1.7  1993/10/29  15:20:08  rex
 * Added MSG_SRC_TYPE and MSG_SRC_ID
 * 
 * Revision 1.6  1993/07/22  10:56:51  rex
 * Added ID_B2O_STRINGTAB
 * 
 * Revision 1.5  1993/07/16  17:30:45  rex
 * Added accelerator key field to menu struct
 * 
 * Revision 1.4  1993/07/13  16:18:08  rex
 * Added B2_STATIC_VAR to extern types
 * 
 * Revision 1.3  1993/07/13  16:15:20  rex
 * Revamped for new linker-related structures
 * 
*/

#ifndef B2TYPES_H
#define B2TYPES_H

#ifndef TYPES_H
#include <types.h>
#endif
#ifndef RES_H
#include <res.h>
#endif

//	-----------------
//	Basic Babl2 types
//	-----------------

typedef long Babint;		// BABL2 integers are longs
typedef ushort Baboff;	// offsets into code are ushorts

//	-------------------------------------------------------------
//	Disk structure of .b2o output files (in resource file format)
//	-------------------------------------------------------------

#define ID_B2O_EXTERNS		3		// compound of B2oExtern
#define ID_B2O_RELOCS		4		// non-compound, array of B2oReloc
#define ID_B2O_CODE			5		// compound of raw code streams
#define ID_B2O_STRINGTAB	6		// compound of strings
#define ID_B2O_DBGLINE		7		// optional, non-compound of B2oLineOfftab

//	The ID_B2O_EXTERNS resource is compound; each item is a B2oExtern

typedef enum {
	B2_PUBLIC_FUNC,				// public BABL2 function
	B2_EXTERN_FUNC,				// external BABL2 function
	B2_EXTERN_CFUNC,				// external C function
	B2_EXTERN_CVAR,				// external C var
	B2_GLOBAL_VAR,					// global var
	B2_STATIC_VAR,					// static var (used in reloc records only)
	B2_LOCAL_FUNC,					// patch local func id (used in reloc records)
	B2_LOCAL_STRING,				// patch string id (used in reloc records only)
} B2Extern;

typedef struct {
	B2Extern type;					// B2_XXX
	union {
		long arg;					// generic access
		RefIndex index;			// if B2_PUBLIC_FUNC, its ref index
		short numArgs;				// if B2_EXTERN_CFUNC, # args
		ushort size;				// if B2_GLOBAL_VAR, its size in bytes
		};
	char name[1];					// 0-terminated name (var-length)
} B2oExtern;

//	The ID_B2O_RELOCS resource is compound; each item is B2oReloc

typedef struct {
	B2Extern type;					// B2_XXX
	Baboff offset;					// offset in code to patch
} B2oReloc;

//	The ID_B2O_CODE resource is compound; the first item is a B2oHeader,
//	all other items are compiled BABL2 functions.

typedef struct {
	char name[9];					// 0-terminated name, without extension
	Baboff sizeStatics;			// size of static data
} B2oHeader;

//	The ID_B2O_DBGLINE is non-compound; it is a B2oLineOfftab

typedef struct {
	ushort numLines;				// # lines in source code (.bab)
	ushort offset[1];				// varlength, byte offset of each line of source
} B2oLineOfftab;

//	-------------------------------------------------------------
//	Disk structure of .res file output by linker
//	-------------------------------------------------------------

//	The first resource in a linked .res file is a Babl2ResHeader.
//	.b2o and .b2s resources are stored in pairs, starting at codeIds
//	(which is usually one greater than the id of the header resource).
//	If debug info is included, the id for debug info is set (else 0).

typedef struct {
	Id codeIds;						// base id of code resources
	Id debugId;						// if non-zero, id of debug resource
	short numObjs;					// number of .b2o files linked together
	Baboff globalSize;			// size of global space, in bytes
} Babl2ResHeader;

//	-------------------------------------------------------------
//	Structures contained with BABL2 compiled object code
//	-------------------------------------------------------------

//	Babl2 Menus look like this:

typedef struct {
	ushort flagType;			// 0 = constant, 1-6 = variable, 0x8000 = default
	ushort flagVal;			// flag value (non-zero means do it)
	ushort accKey;				// accelerator key
	RefIndex stringIndex;	// string index (id is code id + 1)
	Baboff offset;				// where to jump when select
} Babl2MenuItem;

#define MAX_BABL2MENUITEMS 32
typedef struct {
	short numItems;									// # menu items
	Babl2MenuItem item[MAX_BABL2MENUITEMS];	// menu items
} Babl2Menu;

//	---------------------------------------------------------
//	Special msg offset constants
//	---------------------------------------------------------

#define MSG_SRC_TYPE	30
#define MSG_SRC_ID	31


#endif

