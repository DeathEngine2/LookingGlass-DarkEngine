// smrtheap.hpp -- SmartHeap public C++ header file
// Professional Memory Management Library
//
// Copyright (C) 1991-1994 by Arthur D. Applegate
// All Rights Reserved.
//
// No part of this source code may be copied, modified or reproduced
// in any form without retaining the above copyright notice.
// This source code, or source code derived from it, may not be redistributed
// without express written permission of the author.
//
// COMMENTS:
// - Reasons to include this header file:
//     o to call the SmartHeap-specific versions of operators new (i.e. with
//       placement syntax)
//     o to call debugging version of global operator new
//
// - If you include this header file, you must compile and link shnew.cpp, or
//   link with one of the SmartHeap static operator new libraries:
//   sh[l|d]XXXX[d].lib, sh[d|l]mfcXd.lib, or sh[d|l]owlb[d].lib.
//
// - Can be used in both EXEs and DLLs.
//
// - For 16-bit x86 platforms, use only in large or compact memory model.
//
// - If you do not want to use SmartHeap's global operator new but you do
//   want to use SmartHeap's other facilities in a C++ application, then 
//   include the smrtheap.h header file but do not include this header file,
//   and do not link with shnew.cpp.  The two ".Xpp" files are present
//   ONLY for the purpose of defining operator new and operator delete.
//
// - Use the MemDefaultPool global variable to refer to a memory pool to pass
//   to SmartHeap functions that accept a pool as a parameter,
//   e.g. MemPoolCount, MemPoolSize, MemPoolWalk, etc.
//

#if !defined(_SMARTHEAP_HPP)
#define _SMARTHEAP_HPP

extern "C" {
#include "smrtheap.h"
}
#include <new.h>

#ifdef MEM_DEBUG
#define DBG_FORMAL , const char MEM_FAR *file, int line
#define DBG_ACTUAL , file, line
#else
#define DBG_FORMAL
#define DBG_ACTUAL
#endif

class MEM_NEAR _shi_New
{
public:
   static MEM_POOL GetPool()
      { return MemDefaultPool ? MemDefaultPool : MemInitDefaultPool(); }
   static void MEM_FAR *alloc(unsigned long sz, unsigned flags=0,
      MEM_POOL pool=GetPool());
#ifdef MEM_DEBUG
   // both debug and non-debug versions must both be defined so that calls
   // to _shi_New::alloc from inline versions of operator new in modules
   // that were not recompiled with MEM_DEBUG will resolve correctly
   static void MEM_FAR *alloc(unsigned long sz DBG_FORMAL, unsigned flags=0,
            MEM_POOL pool=GetPool());
#endif
};

/* MemPool defined for SmartHeap 1.5 compatibility: same as MemDefaultPool */
extern _shi_New MEM_NEAR MemPool;



// operator new variants:

#if ((defined(__BORLANDC__) && (__BORLANDC__ >= 0x450)) \
	|| (defined(__WATCOMC__) && __WATCOMC__ >= 1000))
#define SHI_ARRAY_NEW 1
#endif

// compiler-specific versions of new
#if defined(__BORLANDC__)
#if (defined(__LARGE__) || defined(__COMPACT__) || defined(__HUGE__))
void far *operator new(unsigned long sz);
#ifdef MEM_DEBUG
inline void far *operator new(unsigned long sz DBG_FORMAL)
   { return _shi_New::alloc(sz DBG_ACTUAL); }
#if __BORLANDC__ >= 0x450
inline void MEM_FAR *operator new[](unsigned long sz DBG_FORMAL)
   { return _shi_New::alloc(sz DBG_ACTUAL); }
#endif /* __BORLANDC__ >= 0x450 */
#endif /* MEM_DEBUG */
#endif /* __LARGE__ */


#elif defined(_MSC_VER)
#if (defined(M_I86LM) || defined(M_I86CM) || defined(M_I86HM))
extern void __huge * operator new(unsigned long count, size_t sz);
#define MEM_HUGE 0x8000u
#ifdef MEM_DEBUG
inline void __huge * operator new(unsigned long count, size_t sz DBG_FORMAL)
   { return (void __huge *)_shi_New::alloc(count * sz DBG_ACTUAL, MEM_HUGE); }
#endif
#endif

#endif /* compile-specific versions of new */

// version of new that passes memory allocation flags
// (e.g. MEM_ZEROINIT to zero-initialize memory)
// call with syntax 'ptr = new (flags) <type>'
inline void MEM_FAR *operator new(size_t sz, unsigned flags)
   { return _shi_New::alloc(sz, flags); }
#ifdef MEM_DEBUG
inline void MEM_FAR *operator new(size_t sz, unsigned flags DBG_FORMAL)
   { return _shi_New::alloc(sz DBG_ACTUAL, flags); }
#endif

// version of new that allocates from a specified memory pool with alloc flags
// call with the syntax 'ptr = new (pool, [flags=0]) <type>'
inline void MEM_FAR *operator new(size_t sz, MEM_POOL pool, unsigned flags=0)
   { return _shi_New::alloc(sz, flags, pool); }
#ifdef SHI_ARRAY_NEW
inline void MEM_FAR *operator new[](size_t sz, MEM_POOL pool, unsigned flags=0)
   { return _shi_New::alloc(sz, flags, pool); }
#endif
#ifdef MEM_DEBUG
inline void MEM_FAR *operator new(size_t sz, MEM_POOL pool DBG_FORMAL)
   { return _shi_New::alloc(sz DBG_ACTUAL, 0, pool); }
inline void MEM_FAR *operator new(size_t sz, MEM_POOL pool, 
                                  unsigned flags DBG_FORMAL)
   { return _shi_New::alloc(sz DBG_ACTUAL, flags, pool); }
#ifdef SHI_ARRAY_NEW
inline void MEM_FAR *operator new[](size_t sz, MEM_POOL pool DBG_FORMAL)
   { return _shi_New::alloc(sz DBG_ACTUAL, 0, pool); }
inline void MEM_FAR *operator new[](size_t sz, MEM_POOL pool, 
                                  unsigned flags DBG_FORMAL)
   { return _shi_New::alloc(sz DBG_ACTUAL, flags, pool); }
#endif // SHI_ARRAY_NEW
#endif // MEM_DEBUG


// version of new that changes the size of a memory block previously allocated
// from an SmartHeap memory pool
// call with the syntax 'ptr = new (ptr, flags) <type>'
#if !defined(MEM_DEBUG) || !defined(__HIGHC__)
/* bug in MetaWare High C++ parser confuses this with new(file,line) */
inline void MEM_FAR *operator new(size_t new_sz, void MEM_FAR *lpMem,
                                  unsigned flags)
   { return MemReAllocPtr(lpMem, new_sz, flags); }
#ifdef SHI_ARRAY_NEW
inline void MEM_FAR *operator new[](size_t new_sz, void MEM_FAR *lpMem,
                                  unsigned flags)
   { return MemReAllocPtr(lpMem, new_sz, flags); }
#endif // SHI_ARRAY_NEW
#endif
#ifdef MEM_DEBUG
inline void MEM_FAR *operator new(size_t new_sz, void MEM_FAR *lpMem,
                                  unsigned flags DBG_FORMAL)
   { return _dbgMemReAllocPtr1(lpMem, new_sz, flags, MEM_NEW DBG_ACTUAL); }
#ifdef SHI_ARRAY_NEW
inline void MEM_FAR *operator new[](size_t new_sz, void MEM_FAR *lpMem,
                                  unsigned flags DBG_FORMAL)
   { return _dbgMemReAllocPtr1(lpMem, new_sz, flags, MEM_NEW DBG_ACTUAL); }
#endif // SHI_ARRAY_NEW
#endif // MEM_DEBUG


/* To have SmartHeap track file/line of C++ allocations, define new as macro:
 * #define new DEBUG_NEW
 * In cases where you use explicit placement syntax, or in modules that define
 * operator new, you must undefine the new macro, e.g.:
 * #undef new
 *    void *x = new(placementArg) char[30];  // cannot track file/line info
 * #define new DEBUG_NEW
 *    void *y = new char[20];                // resume tracking file/line info
 */
#ifdef DEBUG_NEW
#undef DEBUG_NEW
#endif

#ifdef MEM_DEBUG
#ifndef _AFX   /* this must be defined out-of-line for MFC */
inline void MEM_FAR *operator new(size_t sz DBG_FORMAL)
   { return _shi_New::alloc(sz DBG_ACTUAL); }
#endif
#ifdef SHI_ARRAY_NEW
inline void MEM_FAR *operator new[](size_t sz DBG_FORMAL)
   { return _shi_New::alloc(sz DBG_ACTUAL); }
#endif

#define DEBUG_NEW new(__FILE__, __LINE__)
#ifdef DEFINE_NEW_MACRO
#ifdef macintosh  // MPW C++ bug precludes new --> DEBUG_NEW --> new(...)
#define new new(__FILE__, __LINE__)
#else
#define new DEBUG_NEW
#endif // macintosh
#endif // DEFINE_NEW_MACRO
#else
#define DEBUG_NEW new
#endif // MEM_DEBUG


// new_handler prototypes: note that MSC/C++ prototype differs from the
// protosed ANSI standard prototype for set_new_handler
#ifdef _MSC_VER
_PNH _set_new_handler( _PNH );
#if UINT_MAX == 0xFFFFu
_PNH _set_fnew_handler( _PNH );
_PNHH _set_hnew_handler( _PNHH );
#endif
#endif
typedef void (* pnh)();
pnh set_new_handler(pnh);


#endif /* !defined(_SMARTHEAP_HPP) */
