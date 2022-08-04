/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

//
// 386FX file & DLL loader functions/equates
//

#ifndef DLL_H
#define DLL_H

#include <string.h>  // (for size_t definition)

//
// MetaWare support
//

#ifdef __HIGHC__
#define cdecl _CC(_REVERSE_PARMS | _NEAR_CALL)
#pragma Global_aliasing_convention("_%r");
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef FILE_ERRS
#define FILE_ERRS

#define NO_ERROR        0
#define IO_ERROR        1
#define OUT_OF_MEMORY   2
#define FILE_NOT_FOUND  3
#define CANT_WRITE_FILE 4
#define CANT_READ_FILE  5
#define DISK_FULL       6

#endif

#ifndef TYPEDEFS
#define TYPEDEFS

typedef unsigned char  UBYTE;
typedef unsigned short UWORD;
typedef unsigned long  ULONG;
// @Note (toml 05-20-96): removed because incompatible with Windows
// these are defined as unsiged in both windows.h and our types.h
// If this breaks AIL, we'll have to explore a better way to
// resolve the conflict
#if 0
typedef char  BYTE;
typedef short WORD;
#endif
typedef long  LONG;

#endif

//
// malloc() / free() wrapper functions
//

extern void * (*MEM_alloc) (size_t);
extern void   (*MEM_free)  (void *);

void * cdecl MEM_use_malloc(void *(*fn)(size_t));
void * cdecl MEM_use_free  (void (*fn)(void *));

//
// Other memory-management functions
//

LONG   cdecl MEM_alloc_DOS    (ULONG  n_paras,
                               void **protected_ptr,
                               ULONG *segment_far_ptr,
                               ULONG *selector);

void   cdecl MEM_free_DOS     (void  *protected_ptr,
                               ULONG  segment_far_ptr,
                               ULONG  selector);

void * cdecl MEM_alloc_lock   (size_t size);

void   cdecl MEM_free_lock    (void  *ptr,
                               size_t size);

LONG   cdecl VMM_lock_range   (void  *p1, void *p2);
LONG   cdecl VMM_unlock_range (void  *p1, void *p2);

LONG   cdecl VMM_lock         (void  *start, ULONG size);
LONG   cdecl VMM_unlock       (void  *start, ULONG size);

ULONG  cdecl SEL_base         (ULONG  sel);

void   cdecl SEL_set_limit    (ULONG  sel,
                               ULONG  limit);

//
// DLL loader flags & functions
//

#define DLLSRC_FILE  0     // *source is filename string
#define DLLSRC_MEM   1     // *source is pointer to DLL image in memory
#define DLLMEM_USER  2     // *dll -> output memory block alloc'd by user
#define DLLMEM_ALLOC 4     // *dll = don't care; allocate & return output mem

ULONG  cdecl DLL_size   (void *source, ULONG flags);
void * cdecl DLL_load   (void *source, ULONG flags, void *dll);

//
// File functions
//

LONG   cdecl FILE_error (void);
LONG   cdecl FILE_size  (BYTE *filename);
void * cdecl FILE_read  (BYTE *filename, void *dest);
LONG   cdecl FILE_write (BYTE *filename, void *buf, ULONG len);
LONG   cdecl FILE_append(BYTE *filename, void *buf, ULONG len);

#ifdef __cplusplus
}
#endif

//
// MetaWare support
//

#ifdef __HIGHC__
#pragma Global_aliasing_convention();
#endif

#endif
