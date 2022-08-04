/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/shock/RCS/shkaiprb.h 1.4 1999/06/06 19:19:21 JON Exp $
//

#ifndef __SHKAIPRB_H
#define __SHKAIPRB_H

#include <shkaisbs.h>

///////////////////////////////////////////////////////////////////////////////
//
// Protocol behavior set
//

class cAIProtocolBehaviorSet : public cAIShockBehaviorSet
{ 
public: 
   STDMETHOD_(const char *, GetName)()
   {
      return "Protocol";
   }
   
protected:
   virtual void CreateCombatAbilities(cAIComponentPtrs * pComponents);
   virtual void CreateGenericAbilities(cAIComponentPtrs * pComponents);
};

///////////////////////////////////////////////////////////////////////////////

#endif /* !__SHKAIPRB_H */
