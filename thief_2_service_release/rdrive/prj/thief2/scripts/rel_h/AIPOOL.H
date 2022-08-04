/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/aipool.h 1.8 1998/03/26 13:51:32 mahk Exp $

#ifndef __AIPOOL_H
#define __AIPOOL_H

#include <aitype.h>
#include <proptype.h>
#include <dynarray.h>

class cAI;

///////////////////////////////////////////////////////////////////////////////
//                               AI HEAP CLASS
///////////////////////////////////////////////////////////////////////////////

// The AIPool is the storage mechanism for all AI classes
// in the game.  You must create the heap in order to
// create an AIs, and you can destroy the the heap when
// you are done with all of the AIs.

// 1/15/96 MAHK: I'm making this a mostly-abstract base class, to make propertization smoother
//               @OPTIMIZE: inline implementation as necessary
//               Oh, and I re-indented.  Sorry Briscoe

class AIPool
{

public:
   virtual ~AIPool() {};

   virtual void DestroyAllAIs() = 0;

   // To create a new ai...
   virtual BOOL CreateAI(ObjID obj, eAITeamType team, BOOL isPlayer, tAIID &id) = 0;

   // To destroy an existing ai...
   virtual BOOL DestroyAI(tAIID ai) = 0;

   // Get AI by ObjID
   virtual BOOL GetObjAI(ObjID obj, cAI * &ai) const = 0;

   // Get tAIID by ObjID
   virtual tAIID GetObjAIID(ObjID obj) const = 0;

   // Get a number larger than the largest ID in use
   virtual int MaxAIID() const = 0;

   // return the number of active ais
   virtual int GetAICount() const = 0;

   // Iteration
   virtual BOOL GetFirstAI(cAI * &ai) const = 0;
   virtual BOOL GetNextAI(tAIID ai, cAI * &nextAI) const = 0;
   virtual BOOL GetNextAI(cAI * &ai) const = 0;

   // To get an ai by his raw ID...
   virtual BOOL GetAI(tAIID id, cAI * &ai) const = 0;

};


//
// Factory function
//
extern AIPool*  AICreateAIPool();
extern void     AIDestroyAIPool(AIPool* );
extern AIPool * g_pAIPool;


#endif /* !__AIPOOL_H */
