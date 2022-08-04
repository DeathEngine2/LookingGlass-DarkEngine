/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/shock/RCS/shkaiswm.h 1.3 1999/06/18 22:17:28 JON Exp $
//

#ifndef __SHKAISWM_H
#define __SHKAISWM_H

#include <ai.h>
#include <aibasbhv.h>
#include <aibascmp.h>

///////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAISwarmer
//

class cAISwarmer : public cAI
{
public:
   STDMETHOD_(float, GetGroundOffset)();
};

///////////////////////////////////////////////////////////////////////////////
//
// Swarmer behavior set
//

class cAISwarmerBehaviorSet : public cAIBehaviorSet
{ 
public: 
   STDMETHOD_(const char *, GetName)()
   {
      return "Swarmer";
   }
   
   STDMETHOD_(cAI *, CreateAI)(ObjID id)
   {
      cAI * pAI = new cAISwarmer;
      if (pAI->Init(id, this) != S_OK)
         SafeRelease(pAI);
      return pAI;
   }

protected:
   virtual void CreateNonCombatAbilities(cAIComponentPtrs * pComponents);
   virtual void CreateCombatAbilities(cAIComponentPtrs * pComponents);
   virtual void CreateGenericAbilities(cAIComponentPtrs * pComponents);
};

///////////////////////////////////////////////////////////////////////////////

#endif /* !__SHKAISWM_H */
