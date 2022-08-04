/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

#ifndef _SYM_DATA_H_
#define _SYM_DATA_H_

#include <comtools.h>

F_DECLARE_INTERFACE(ISymSaver);
F_DECLARE_INTERFACE(ISymLoader);
F_DECLARE_INTERFACE(ISymSave);
F_DECLARE_INTERFACE(ISymLoad);

extern HRESULT SymLoadCreateInstance(void **ppIUnknown);
extern HRESULT SymSaveCreateInstance(void **ppIUnknown);

DECLARE_INTERFACE_(ISymSaver,IUnknown)
{
   DECLARE_UNKNOWN_PURE();

	STDMETHOD(Write)(THIS_ void *pMem,unsigned long nSize) PURE;

	// Tells the interface how big the file will be.
	// This is called before any Write is called.
	// If it returns an error, the saving will be aborted.
	STDMETHOD(SetSize)(THIS_ unsigned long nSize) PURE;

	// Tells the interface that SymData is done with this
	// File.
	STDMETHOD_(void,Done)(THIS) PURE;
};

DECLARE_INTERFACE_(ISymLoader,IUnknown)
{
   DECLARE_UNKNOWN_PURE();
	
	STDMETHOD(Read)(THIS_ void *pMem,unsigned long nSize) PURE;

	// Tells the interface that the SymFile is done with this
	// File.
	STDMETHOD_(void,Done)(THIS) PURE;
};


DECLARE_INTERFACE_(ISymSave,IUnknown)
{
   DECLARE_UNKNOWN_PURE();

	// Define a memory area.
	STDMETHOD(DefineMemory)(THIS_ void *pMem,unsigned long nSize) PURE;
	
	// Define a pointer, NULL pointers are ignored.
	STDMETHOD(DefinePointer)(THIS_ void **ppPointer) PURE;

	// Get the size the current data would be if saved.
	STDMETHOD_(unsigned long, Size)(THIS) PURE;

	// Save the data to a file.
	STDMETHOD(SaveFile)(THIS_ char *szFile) PURE;

	// Save the data to a memory block. If pMem is NULL, memory is allocated.
	STDMETHOD_(void *,SaveMemory)(THIS_ void *pMem PURE) PURE;

	// Save the data using a Interface.
	STDMETHOD(SaveInterface)(THIS_ ISymSaver *pInterface) PURE;

	// Restarts the process, all previous stored data is scratched.
	// After you call this you can start saving again if you like.
	STDMETHOD_(void,End)() PURE;
};

DECLARE_INTERFACE_(ISymLoad,IUnknown)
{
   DECLARE_UNKNOWN_PURE();

	// Load from file.
	// Returns NULL on non fatal error.
	STDMETHOD_(void *,LoadFile)(THIS_ char *szFile) PURE;

	// "Load" from memory. If you use this you will have a small chunk of
	// memory that will not be used after this.
	// Returns NULL on non fatal error.
	STDMETHOD_(void *,LoadMemory)(THIS_ void *pMem) PURE;

	// Load from a interface.
	// Returns NULL on non fatal error.
	STDMETHOD_(void *,LoadInterface)(THIS_ ISymLoader *pInterface) PURE;
};

#endif
