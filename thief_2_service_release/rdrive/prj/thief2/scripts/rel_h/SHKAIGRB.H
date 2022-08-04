/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/shock/RCS/shkaigrb.h 1.2 1999/06/04 18:57:39 JON Exp $
//

#ifndef __SHKAIGRB_H
#define __SHKAIGRB_H

#include <ai.h>
#include <aibasbhv.h>
#include <aibascmp.h>

///////////////////////////////////////////////////////////////////////////////
//
// Grub behavior set
//

class cAIGrubBehaviorSet : public cAIBehaviorSet
{ 
public: 
   STDMETHOD_(const char *, GetName)()
   {
      return "Grub";
   }
   
protected:
   virtual void CreateNonCombatAbilities(cAIComponentPtrs * pComponents);
   virtual void CreateCombatAbilities(cAIComponentPtrs * pComponents);
   virtual void CreateGenericAbilities(cAIComponentPtrs * pComponents);
   virtual void CreateNonAbilityComponents(cAIComponentPtrs * pComponents);
};

///////////////////////////////////////////////////////////////////////////////

#endif /* !__SHKAIGRB_H */
