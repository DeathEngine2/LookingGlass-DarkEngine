/* shmalloc.h -- SmartHeap ANSI Standard C memory API
 * Professional Memory Management Library
 *
 * Copyright (C) 1991-1994 by Arthur D. Applegate.  All Rights Reserved.
 * All Rights Reserved.
 *
 * No part of this source code may be copied, modified or reproduced
 * in any form without retaining the above copyright notice.
 * This source code, or source code derived from it, may not be redistributed
 * without express written permission of the author.
 */

#if !(defined(_SHMALLOC_H))
#define _SHMALLOC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "smrtheap.h"

/* ANSI Standard Memory Management API */

#if !defined(NO_MALLOC_MACRO) || defined(MALLOC_MACRO)
#ifdef malloc
#undef malloc
#endif
#define malloc(s) MEM_malloc(s)
#ifdef calloc
#undef calloc
#endif
#define calloc(s,c) MEM_calloc(s,c)
#ifdef realloc
#undef realloc
#endif
#define realloc(p,s) MEM_realloc(p,s)
#ifdef free
#undef free
#endif
#define free(p) MEM_free(p)
#endif  /* NO_MALLOC_MACRO */

#ifdef MEM_DEBUG
void MEM_FAR * MEM_ENTRY _dbgMEM_alloc(size_t, unsigned, MEM_API,
													const char MEM_FAR *, int);
void MEM_FAR * MEM_ENTRY _dbgMEM_realloc(void MEM_FAR *, size_t,
                                         const char MEM_FAR *, int);
void MEM_ENTRY _dbgMEM_free(void MEM_FAR *, const char MEM_FAR *, int);
#endif

#if defined(MEM_DEBUG) && !defined(NO_MALLOC_MACRO)

#define MEM_malloc(s) _dbgMEM_alloc(s, 0, MEM_MEM_MALLOC, __FILE__, __LINE__)
#define MEM_calloc(s,c) _dbgMEM_alloc((s)*(c), MEM_ZEROINIT, MEM_MEM_CALLOC, \
   __FILE__, __LINE__)
#define MEM_realloc(p, s) _dbgMEM_realloc(p, s, __FILE__, __LINE__)
#define MEM_free(p) _dbgMEM_free(p, __FILE__, __LINE__)

#else
void MEM_FAR * MEM_ENTRY_ANSI MEM_malloc(size_t size);
void MEM_FAR * MEM_ENTRY_ANSI MEM_calloc(size_t nobj, size_t size);
void MEM_FAR * MEM_ENTRY_ANSI MEM_realloc(void MEM_FAR *p, size_t size);
void MEM_ENTRY_ANSI MEM_free(void MEM_FAR *p);
#if defined(__WATCOMC__) && defined(__SW_3S)
/* Watcom stack calling convention */
   #pragma aux (syscall) MEM_malloc
   #pragma aux (syscall) MEM_realloc
   #pragma aux (syscall) MEM_calloc
   #pragma aux (syscall) MEM_free
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* !defined(_SHMALLOC_H) */
