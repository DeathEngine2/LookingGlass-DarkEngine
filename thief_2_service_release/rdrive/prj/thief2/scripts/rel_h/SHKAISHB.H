/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/shock/RCS/shkaishb.h 1.2 1999/03/31 18:51:50 JON Exp $
//

#ifndef __SHKAISHB_H
#define __SHKAISHB_H

#include <shkaisbs.h>

///////////////////////////////////////////////////////////////////////////////
//
// Shodan behavior set
//

class cAIShodanBehaviorSet : public cAIShockBehaviorSet
{ 
public: 
   STDMETHOD_(const char *, GetName)()
   {
      return "Shodan";
   }
   
protected:
   virtual void CreateCombatAbilities(cAIComponentPtrs * pComponents);
};

///////////////////////////////////////////////////////////////////////////////

#endif /* !__SHKAISHB_H */
