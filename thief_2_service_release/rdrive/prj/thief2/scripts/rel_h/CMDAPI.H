/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Source: r:/prj/cam/src/RCS/cmdapi.h $
// $Author: TOML $
// $Date: 1997/08/03 13:51:39 $
// $Revision: 1.1 $
//

#ifndef __CMDAPI_H
#define __CMDAPI_H

#include <comtools.h>

///////////////////////////////////////////////////////////////////////////////

F_DECLARE_INTERFACE(ICommander);

typedef struct sCmdDesc sCmdDesc;
typedef struct sCmd     sCmd;
typedef struct sCmd     sCmd;
typedef struct sCmdMsg  sCmdMsg;

typedef ulong           tCmdId;
typedef ulong           tHelpId;

///////////////////////////////////////////////////////////////////////////////

#define CommanderCreate() \
_CommanderCreate(IID_TO_REFIID(IID_ICommander), NULL, AppGetObj(IUnknown))

//
// Creates a commander, aggregating it with specfied pOuter,
// use IAggregate protocol if ppLoopManager is NULL, else self-init
//

EXTERN
tResult LGAPI _CommanderCreate(REFIID, ICommander ** ppLoopManager, IUnknown * pOuter);

///////////////////////////////////////////////////////////////////////////////
//
// Command handler function type.
//
//    - Command functions receive an arbitrary set of parameters, and return
//      void.
//
// Takes: - a pointer to the command details
//        - the context in which the command was fired
//        - info flags
//        - a pointer to an arguments block
//

typedef void *  tCmdFunc;

///////////////////////////////////////////////////////////////////////////////
//
// Command UI update function type.
//
// Takes: - a pointer to the command details
//        - the context in which the command was fired
//        - info flags
//        - a pointer to an arguments block
//
// Returns:
//        - S_OK: the command is available
//        - S_FALSE: the command is unavailable
//

typedef HRESULT (*tCmdUpdateFunc)(const sCmd * pCmd,
                                      ulong context,
                                      ulong flags,
                                      const DWORD * pArgsArray);


///////////////////////////////////////////////////////////////////////////////
//
// Special commands
//

///////////////////////////////////////
//
// kCommandSetVar
//
// Default command handler to set a variable according to the args. The command
// descriptor pData should point to the variable.
//

#define kCmdSetVar ((void *)(0x01))

///////////////////////////////////////
//
// kCmdToggleVar()
//
// Default command handler to toggle a variable. Variable must be an integer type.
//

#define kCmdToggleVar ((void *)(0x02))


///////////////////////////////////////////////////////////////////////////////
//
// STRUCT: sCmdDesc
//
// The descriptor used to register commands. The data pointed to by this 
// structure must be persistent for as long as the command is registered
//

//
// The command arguments string is a series of 0-kCmdMaxArgs items describing 
// the parameters taken bu the command function:
//
//    i - int
//    I - int array
//    u - unsigned
//    b - bool
//    B - BOOL
//    f - float
//    x - fix
//    s - const char *
//    v - void *
//
// Specials:
//    d - pointer to client data in sCmdDesc::pData
//    C - const sCmd *

#define kCmdContextAll  0xffffffff

struct sCmdDesc
{
   const char *   pszName;                       // Command name

   tCmdFunc       pfnDoIt;                       // Handler to execute command
   const char *   pszArgs;                       // Arguments string
   void *         pData;                         // Client-defined context data

   tCmdUpdateFunc pfnUpdate;                     // Handler to update UI representation of state/availability of command

   unsigned       fContexts;                     // Client-defined availability context
   unsigned       flags;                         // Flags; presently unused and must be zero

   const char *   pszDescription;                // Long description if the command, or zero
   const char *   pszToolhelp;                   // Toolhelp pop-up description of command, or zero
   tHelpId        helpId;                        // Context sensitive help ID, or zero
};

///////////////////////////////////////////////////////////////////////////////
//
// STRUCT: sCmd
//
// The structure representing a fully parsed command

#define kCmdIdInvalid ((tCmdId)-1)
#define kCmdMaxArgs 6

struct sCmd
{
   tCmdId   id;
   unsigned nArgs;
   DWORD    args[kCmdMaxArgs];

};

///////////////////////////////////////////////////////////////////////////////
//
// INTERFACE: ICommander
//

#undef INTERFACE
#define INTERFACE ICommander

DECLARE_INTERFACE_(ICommander, IUnknown)
{
   //
   // IUnknown methods
   //
   DECLARE_UNKNOWN_PURE();

   //
   // Expose a new set of commands
   //
   STDMETHOD (Register)(THIS_ const sCmdDesc *, int count) PURE;

   //
   // Context management
   //
   STDMETHOD (SetContext)(THIS_ unsigned fContexts) PURE;
   STDMETHOD_(unsigned, GetContext)(THIS) PURE;
   
   //
   // Query for information on a command
   //
   STDMETHOD_(tCmdId,           GetId)(THIS_ const char * pszCommand) PURE;
   STDMETHOD_(const sCmdDesc *, GetDesc)(THIS_ const char * pszCommand) PURE;
   STDMETHOD_(const sCmdDesc *, GetDesc)(THIS_ tCmdId) PURE;
   
   STDMETHOD_(char *, GetHelpString)(THIS_ tCmdId, char * pBuf) PURE;
   STDMETHOD_(char *, GetHelpString)(THIS_ const char * pszCommand, char * pBuf) PURE;

   //
   // Given a text string, parse a command. String arguments are dynamically
   // allocated and must be freed.
   //
   STDMETHOD (Parse)(THIS_ const char * pszInput, sCmd * ppResult) PURE;

   //
   // Execute a command
   //
   STDMETHOD (Execute)(THIS_ const sCmd *) PURE;
   STDMETHOD (ExecuteById)(THIS_ tCmdId, ...) PURE;
   STDMETHOD (ExecuteByName)(THIS_ const char * pszCommand, ...) PURE;
   STDMETHOD (ExecuteText)(THIS_ const char * pszInput) PURE;

   //
   // Execute a series of commands
   //
   STDMETHOD (ExecuteScript)(THIS_ const char * pszFilename) PURE;

   //
   // Given an text string, do a command line complete
   //
   STDMETHOD_(const char *, LineComplete)(THIS_ const char *, BOOL fRestart) PURE;

};

///////////////////////////////////////////////////////////////////////////////

#endif /* !__CMDAPI_H */
