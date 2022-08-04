/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Source: x:/prj/tech/libsrc/lgstream/RCS/lgstream.h $
// $Author: JAEMZ $
// $Date: 1997/09/18 12:14:36 $
// $Revision: 1.5 $
//

#ifndef __LGSTREAM_H
#define __LGSTREAM_H

#include <comtools.h>

///////////////////////////////////////////////////////////////////////////////

typedef struct Datapath Datapath;
F_DECLARE_INTERFACE(IStream);
F_DECLARE_INTERFACE(IProxiedStreamOpener);

#if defined(__WATCOMC__)
typedef struct __iobuf FILE;
#else
typedef struct _iobuf  FILE;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Large integer convenience handling macros
//


// Changed to use native long int assignment

#define LongToLarge(longval, largeval) \
   { (largeval).QuadPart = (longval); }

#define LargeToLong(largeval, longval) \
   { (longval) = ((largeval).LowPart); }

#define ULongToULarge(ulongval, largeval) \
   { (largeval).QuadPart = (ulongval); }

#define ULargeToULong(largeval, ulongval) \
   { (ulongval) = (largeval).LowPart; }

///////////////////////////////////////////////////////////////////////////////
//
// Stream factory methods
//

///////////////////////////////////////
//
// Create a stream from a file specification
//

EXTERN
HRESULT LGAPI StreamCreateFromFile(const char * pszName,
                                   const char * mode,
                                   const Datapath * pDataPath,
                                   BOOL fProxied,
                                   IStream ** ppResult);


///////////////////////////////////////
//
// Create a stream from an open file
//

EXTERN
HRESULT LGAPI StreamCreateFromHandle(FILE * hFile,
                                     IStream ** ppResult);


///////////////////////////////////////
//
// Create a stream from an memory buffer
//

EXTERN
HRESULT LGAPI StreamCreateFromBuffer(void * buffer,
                                     ulong bufSize,
                                     BOOL fDynamic,
                                     IStream ** ppResult);


///////////////////////////////////////
//
// Create a proxied stream.  Stream is not opened until needed.
//

EXTERN
HRESULT LGAPI StreamCreateProxied(IProxiedStreamOpener *,
                                  IStream ** ppResult);


///////////////////////////////////////////////////////////////////////////////
//
// INTERFACE: IProxiedStreamOpener
//
// Specifies functions to allow proxied streams to open files when
// needed.  Implementations need required to manage stream after
// opened.
//

#undef INTERFACE
#define INTERFACE IProxiedStreamOpener

DECLARE_INTERFACE_(IProxiedStreamOpener, IUnknown)
    {
    //
    // IUnknown Methods
    //
    DECLARE_UNKNOWN_PURE();

    //
    // Create a stream
    //
    STDMETHOD(Open)(THIS_ IStream **) PURE;

    };

#endif /* !__LGSTREAM_H */
