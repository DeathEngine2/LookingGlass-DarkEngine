/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/ai/RCS/aiscrctx.h 1.1 1998/04/26 18:13:30 TOML Exp $
//
//
//

#ifndef __AISCRCTX_H
#define __AISCRCTX_H

#include <aicortex.h>
#include <aiscrt.h>
#include <aiscrm.h>
#include <multparm.h>

class cMultiParm;

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAIScriptCtx HACK! HACK HACK HACK (toml 12-29-97)
//

class cAIScriptCtx : public cAICtx
{
public:
   cAIScriptCtx(tAIID ai, cAI * aiPtr);
   ~cAIScriptCtx() {}

   BOOL DoesAcceptEvent(const sAIEvent& event);
   void RespondToEvent(const sAIEvent &event);
   void Cycle();

   BOOL GotoObjLoc(ObjID objIdTarget, 
                   eAISpeed speed, 
                   eAIActionPriority priority, 
                   const cMultiParm & dataToSendOnReach);
   void Search();
                   
   BOOL DoManeuver(const char * pszManeuver, 
                   eAIActionPriority priority, 
                   const cMultiParm & dataToSendOnCompletion);
   BOOL FrobObj(ObjID objIdTarget, 
                ObjID objIdWith, 
                eAIActionPriority priority, 
                const cMultiParm &dataToSendOnReach);

   void OnDestinationReached();
   void OnDestinationFailed();
   
private:
   eAIAction       m_action;
   ObjID           m_targetObject;
   ObjID           m_withObject;
   eAIActionResult m_fResult; 
   cMultiParm      m_dataToSendOnReach;
};

///////////////////////////////////////////////////////////////////////////////

#endif /* !__AISCRCTX_H */
