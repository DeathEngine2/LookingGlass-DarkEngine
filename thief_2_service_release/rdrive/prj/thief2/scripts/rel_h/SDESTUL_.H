/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/sdestul_.h 1.5 1998/01/02 14:43:39 mahk Exp $
#pragma once  
#ifndef __SDESTUL__H
#define __SDESTUL__H

#include <sdestool.h>
#include <aggmemb.h>
#include <hashpp.h>

#include <config.h>
#include <cfgdbg.h>



class cSdescTools : public IStructDescTools
{

   typedef cHashTable<const char*,const sStructDesc*,cHashFunctions> DescTable;

public:
   DECLARE_AGGREGATION(cSdescTools);
   cSdescTools(IUnknown* pOwner); 

   STDMETHOD_(const sFieldDesc*, GetFieldNamed)(const sStructDesc* desc, const char* field); 
   STDMETHOD(ParseField)(const sFieldDesc* fdesc, const char* string, void* fielddata);
   STDMETHOD(UnparseField)(const sFieldDesc* fdesc, const void* fielddata, char* string, int len); 
   STDMETHOD(Dump)(const sStructDesc* sdesc, const void* struc); 
   STDMETHOD(SetIntegral)(const sFieldDesc* fdesc, long value, void* fielddata);
   STDMETHOD(GetIntegral)(const sFieldDesc* fdesc, const void* fielddata, long* value);
   STDMETHOD_(const sStructDesc*, Lookup)(const char* name); 
   STDMETHOD(Register)(const sStructDesc* desc) ; 
   STDMETHOD(ClearRegistry)() ; 


   STDMETHOD_(BOOL,IsSimple)(const sStructDesc* desc);
   STDMETHOD_(BOOL,ParseSimple)(const sStructDesc* desc, const char* string, void *struc);
   STDMETHOD_(BOOL,UnparseSimple)(const sStructDesc* desc, const void* struc, char* buf, int len);
   STDMETHOD_(BOOL,ParseFull)(const sStructDesc* sdesc, const char* string, void* struc); 
   STDMETHOD_(BOOL,UnparseFull)(const sStructDesc* sdesc, const void* struc, char* out, int buflen); 

   // Aggie protocol
   HRESULT Init() { return S_OK; };
   HRESULT End() { ClearRegistry(); return S_OK; }; 

protected:
   DescTable mRegistry;
   
};


#endif // __SDESTUL__H
