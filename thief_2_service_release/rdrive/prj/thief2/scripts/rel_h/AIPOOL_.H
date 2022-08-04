/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/aipool_.h 1.5 1997/10/04 17:11:27 TOML Exp $

#ifndef __AIPOOL__H
#define __AIPOOL__H

#include <comtools.h>
#include <aipool.h>
#include <proptype.h>
#include <objtype.h>

F_DECLARE_INTERFACE(IProperty);
class cPImpCompactArray;


//////////////////////////////////////////////////////////////
// PROPERY-BASED AI POOL
//

class PropAIPool : public AIPool
{
   cPImpCompactArray* _impl;
   IProperty* _ai_prop;  // our property
   PropertyID _ai_propID;
   ObjID* _id2ObjID;

public:
   PropAIPool(const char* propertyname);
   ~PropAIPool();

   //
   // virtual AIPool methods that we have
   //
   void DestroyAllAIs();
   BOOL CreateAI(ObjID obj, eAITeamType team, BOOL isPlayer, tAIID &id);
   BOOL DestroyAI(tAIID ai);
   int MaxAIID() const;
   tAIID GetObjAIID(ObjID obj) const;
   BOOL GetObjAI(ObjID obj, cAI * &ai) const;
};


#endif /* !__AIPOOL__H */
