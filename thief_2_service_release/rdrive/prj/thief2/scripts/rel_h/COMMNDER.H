/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Source: r:/prj/cam/src/RCS/commnder.h $
// $Author: TOML $
// $Date: 1997/08/03 13:51:30 $
// $Revision: 1.1 $
//

#ifndef __COMMNDER_H
#define __COMMNDER_H

#include <lg.h>
#include <cmdapi.h>
#include <aggmemb.h>
#include <dynarray.h>

///////////////////////////////////////////////////////////////////////////////

enum eArgs
{
   kArgInt      = 'i',
   kArgIntArr   = 'I',
   kArgUnsigned = 'u',
   kArgBool     = 'b',
   kArgBOOL     = 'B', 
   kArgFloat    = 'f', 
   kArgStr      = 's', 
   kArgVoidPtr  = 'v',
   
   kArgCmdPtr   = 'c',
   kArgClientData = 'd'
};

///////////////////////////////////////////////////////////////////////////////
//
// STRUCT: sCmdInfo
//
// Used to store information about commands
//

struct sCmdInfo : public sCmdDesc
{
   sCmdInfo(const sCmdDesc *);
   
   tCmdId id;
};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cCmdTable
//
// Used to store information about commands
//

class cCmdInfoTable : private cDynArray<sCmdInfo *>
{
public:
   ~cCmdInfoTable();

   unsigned   Size();

   void       NewCommand(const sCmdDesc *);
   
   sCmdInfo * Search(const char *);
   sCmdInfo * Search(tCmdId);

   sCmdInfo * GetFirst();
   sCmdInfo * GetNext(sCmdInfo * );

};

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cCommander
//

class cCommander : public ICommander
{
public:
   cCommander(IUnknown * pOuterUnknown);
   ~cCommander() {};

private:
   // IUnknown methods
   DECLARE_SIMPLE_AGGREGATION(cCommander);

   // Expose a new set of commands
   STDMETHOD (Register)(const sCmdDesc *, int count);

   // Context management
   STDMETHOD (SetContext)(unsigned fContexts);
   STDMETHOD_(unsigned, GetContext)();

   // Query for information on a command
   STDMETHOD_(tCmdId,           GetId)(const char * pszCommand);
   STDMETHOD_(const sCmdDesc *, GetDesc)(const char * pszCommand);
   STDMETHOD_(const sCmdDesc *, GetDesc)(tCmdId);

   char *             MakeHelpString(sCmdInfo *, char * pBuf);
   STDMETHOD_(char *, GetHelpString)(tCmdId, char * pBuf);
   STDMETHOD_(char *, GetHelpString)(const char * pszCommand, char * pBuf);

   // Given a text string, parse a command
   STDMETHOD (Parse)(const char * pszInput, sCmd * ppResult);

   // Utilities
   DWORD      ParseArg(char, const char *);
   HRESULT    MakeCommand(sCmdInfo * pInfo, va_list pArgs, sCmd * ppResult);

   // Execute a command
   HRESULT    Execute(const sCmdInfo *, const sCmd *);
   STDMETHOD (Execute)(const sCmd *);
   STDMETHOD (ExecuteById)(tCmdId, ...);
   STDMETHOD (ExecuteByName)(const char * pszCommand, ...);
   STDMETHOD (ExecuteText)(const char * pszInput);
   
   // Execute a series of commands
   STDMETHOD (ExecuteScript)(const char * pszFilename);
   
   // Given an text string, do a command line complete
   STDMETHOD_(const char *, LineComplete)(const char *, BOOL fRestart);
   
private:
   unsigned              m_fContexts;
   tCmdId                m_NextCompletionId;
   
   cCmdInfoTable         m_CmdInfoTable;   
};

///////////////////////////////////////////////////////////////////////////////

#endif /* !__COMMNDER_H */
