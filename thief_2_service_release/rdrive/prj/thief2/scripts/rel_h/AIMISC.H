/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/aimisc.h 1.25 1998/01/20 14:21:28 TOML Exp $
///////////////////////
//
// aimisc.h
//
// Briscoe Rodgers
// Looking Glass Technologies, Inc.
// 6/3/96
//
///////////////////////

#ifndef __AIMISC_H
#define __AIMISC_H

#include <aitype.h>
#include <_ai.h>
//#include <ai.h>
//#include <aitask.h>
#include <dbg.h>
#include <math.h>
#include <fltang.h>
#include <limits.h>

#pragma pack(4)

#if 0
//////////////////////////////////////////////////////////////////////////////
//                          cAIMultiLinkedListHeap
//////////////////////////////////////////////////////////////////////////////

class cAIMultiLinkedListHeap
{
   private:
      void*  _data;   // array of node data
      int*   _prev;   // array of node previous "ptrs"
      int*   _next;   // array of node next "ptrs"
      int    _head[MAX_NUM_AI]; // array list heads for each ai
      int    _maxNodes;  // max nodes in node arrays
      size_t _nodeSize;  // size of node data

      void     SetData(int nodeIndex, void* data);
      void     GetData(int nodeIndex, void* data);
      void     GetDataPtr(int nodeIndex, void* &data);

   public:
               cAIMultiLinkedListHeap(size_t objectSize, long maxObjects);
               ~cAIMultiLinkedListHeap();

      void     CreateNode(tAIID ai, void* data);
      void     GetNode(int nodeIndex, void* data);
      void     GetNodePtr(int nodeIndex, void* &dataPtr);
      void     SetNode(int nodeIndex, void* data);
      BOOL     GetFirstNode(tAIID ai, int &nodeIndex, void* data);
      BOOL     GetFirstNodePtr(tAIID ai, int &nodeIndex, void* &dataPtr);
      BOOL     HaveFirstNode(tAIID ai) {return _head[ai] != 0;}
      BOOL     GetNextNode(int &nodeIndex, void* data);
      BOOL     GetNextNodePtr(int &nodeIndex, void* &dataPtr);
      BOOL     RemoveNodeAndGetNext(tAIID ai, int &nodeIndex, void* data);
      BOOL     RemoveNodeAndGetNextPtr(tAIID ai, int &nodeIndex, void* &dataPtr);
};
#endif
#if 0
//////////////////////////////////////////////////////////////////////////////
//                           cAIActivationTracker
//////////////////////////////////////////////////////////////////////////////

// Each cAIActivationTracker is expected to be used by each Coordinator
// in the Task Community.  The cAIActivationTracker remembers recent "
// decisions", where a decision represents a change between which client task
// is the "chosen" or "goal" or"active" task.  The Coordinator is expected to
// report to the cAIActivationTracker every time it chooses a new goal task.

struct AIActivationSwitch
{
   eAITaskType   newlyActiveTask;
   long         timeOfActivation;
};

#define NUMBER_OF_ACTIVATIONS_TO_REMEMBER 20

class cAIActivationTracker
{
   private:
      AIActivationSwitch _activationList[NUMBER_OF_ACTIVATIONS_TO_REMEMBER];
      int                _mostRecentActivation;

   public:
           cAIActivationTracker();

      void RememberActivationSwitch(eAITaskType newlyActivatedTask);
              // Notify the cAIActivationTracker that
              // there is a new "active" task.

      long GetLastTimeTaskActive(eAITaskType theTask);
              // returns the last time the task became
              // the active task.  -1 means NEVER!.

      int  GetTaskActivationCount(eAITaskType theTask, long withinTimePeriod);
              // returns the number of times a task has
              // become the active task by the Coordinator
};
#endif
#if 0
//////////////////////////////////////////////////////////////////////////////
//                      QueryCache & Public Interfaces
//////////////////////////////////////////////////////////////////////////////

// When adding a new query type, you should add a new
// public interface and add code in the "we best do
// the work now" section of the AIQueryCache::GetQueryResult
// method code.

typedef enum {
   kLOSCacheQuery,
   kSenseCacheQuery,
   kCombatTargetQuery,
   kAIQueryTypeIntMax=0xffffffff // force it use an int
} AIQueryType;

struct AIQuery {
   AIQueryType   type;
   long          arg1, arg2;
   long          result1, result2;
};

#define AIQUERY_STORAGE_SIZE 50

class AIQueryCache
{
   private:
      AIQuery _queryData[AIQUERY_STORAGE_SIZE];
      int     _mostRecentQuery;
      BOOL    _fullyUsed;

   public:
              AIQueryCache() {_mostRecentQuery = -1; _fullyUsed = FALSE;}

              // Call this once at the beginning of every AI frame.
      void    ClearCache()   {_mostRecentQuery = -1; _fullyUsed = FALSE;}

              // Call this to see if the query has already been asked this frame
      BOOL    GetQueryResult(AIQueryType type, long arg1, long arg2, long &result1, long &result2);

              // Call this to add a query result, which will show up in GetQueryResult(s) later this frame...
      void    AddQueryResult(AIQueryType type, long arg1, long arg2, long result1, long result2);
};

extern AIQueryCache gAIQueryCache;
#endif

/////////////////////////////////////////
//                SPEW
/////////////////////////////////////////

extern tAIID     g_AICurrentAIID; // for debugging purposes.

#define AISpew(x,y)         DBGS(x, Spew(x,y))
#define AISpewID(x, a)      Spew(x, ("AI %d: ", a));
#define AISpewWithID(a,x,s) DBGS(x, {AISpewID((x),(a)); Spew((x), s);})
//DBGS(d, Spew(d, e);)

// ai creation, deletion, etc.
#define AISpewPool(x)              AISpew(DSRC_AI_POOL, x)

// step by step, function by function record
#define AISpewCode(a, s)           AISpewWithID(a, DSRC_AI_CODE, s)

// spew the final pool of event at end of AI frame
#define AISpewEventList(x)         AISpewWithID(g_AICurrentAIID, DSRC_AI_EVNTLIST,x)

// spew "high level" (modes, etc) event creation
#define AISpewHighEvents(a,x)      AISpewWithID(a, DSRC_AI_HIGHEVTS, x)

// spew "low level" (physics, etc) event creation
#define AISpewLowEvents(a,x)       AISpewWithID(a, DSRC_AI_LOWEVTS,x)

// spew commands coming from outside of the AI
#define AISpewExternalCommand(a,x) AISpewWithID(a, DSRC_AI_EXTCMNDS,x)

// spew all movement suggestion creations
#define AISpewMoveSuggestion(x)    AISpewWithID(g_AICurrentAIID, DSRC_AI_MOVESUGG,x)

// spew the movement goal
#define AISpewMoveGoal(x)          AISpewWithID(g_AICurrentAIID, DSRC_AI_MOVEGOAL,x)

// spew the biped suggestions
#define AISpewBipedSuggestion(x)   AISpewWithID(g_AICurrentAIID, DSRC_AI_BIPDSUGG,x)

// spew the biped goal
#define AISpewBipedGoal(x)         AISpewWithID(g_AICurrentAIID, DSRC_AI_BIPEDGOAL,x)

// spew all AI state at begin & end of frame
#define AISpewAIState(s)           AISpewWithID(g_AICurrentAIID, DSRC_AI_AISTATE,s)

// spew all requests for new paths
#define AISpewPathRequests(x)      AISpewWithID(g_AICurrentAIID, DSRC_AI_PATHREQ,x)

// spew pathfinding data
#define AISpewPathFind(x)          AISpewWithID(g_AICurrentAIID, DSRC_AI_PATHFIND,x)

// spew hld goal changes
#define AISpewHLDChange(a,x)       AISpewWithID(a, DSRC_AI_HLDCHANGE, x)

// spew sound stuff
#define AISpewSound(a,x)           AISpewWithID(a, DSRC_AI_SOUND, x)

inline float AIDistance(float x1, float y1, float x2, float y2)
{
   float a, b;

   a = x2 - x1;
   b = y2 - y1;

   if (a < 0) a = -a;
   if (b < 0) b = -b;

   if (a > b)
      return (a + b/2);
   else
      return (b + a/2);

//   return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

inline float AIDistance(const mxs_vector &p1, const mxs_vector &p2)
{
   float a, b, c;

   a = p2.x - p1.x;
   b = p2.y - p1.y;
   c = p2.z - p1.z;

   if (a < 0) a = -a;
   if (b < 0) b = -b;
   if (c < 0) c = -c;

   if (a > b && a > c)
      return (a + b/2 + c/2);

   if (b > a && b > c)
      return (b + a/2 + c/2);

   return (c + a/2 + b/2);

//   return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
}

inline float AIXYDistance(const mxs_vector &p1, const mxs_vector &p2)
{
   float a, b;

   a = p2.x - p1.x;
   b = p2.y - p1.y;

   if (a < 0) a = -a;
   if (b < 0) b = -b;

   if (a > b)
      return (a + b/2);

   return (b + a/2);
}

inline float AIDistanceSq(float x1, float y1, float x2, float y2)
{
   return ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

inline float AIDistanceSq(const mxs_vector &a, const mxs_vector &b)
{
   return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
}

BOOL InGameMode();

/////////////////////////////////////////
// Misc helpfull little functions
/////////////////////////////////////////

void GetObjDirectionOfMovement(ObjID obj, floatang &zPlane);
void GetObjLocation(ObjID obj, sAIPoint * p);
void GetObjFacing(ObjID obj, floatang &facing);
void GetObjVelocity(ObjID obj, float &x, float &y, float &z);
void GetObjAngVelocity(ObjID obj, float &x, float &y, float &z);

// generates a random between low & high, inclusive.
int AIRandom(int low, int high);

extern ulong g_nAICycle; // this doesn't seem to be used for anything (toml 09-25-97)
extern ulong g_ulAITime;

inline ulong AIGetTime()                {return g_ulAITime;}
inline ulong AIGetCycle()               {return g_nAICycle;}

inline void ProjectFromLocationOnZPlane(sAIPoint startLoc, float distance, floatang angle, sAIPoint &result)
{
   result.x = startLoc.x + cos(angle.value) * distance;
   result.y = startLoc.y + sin(angle.value) * distance;
   result.z = startLoc.z;
}

// return TRUE if line of sight succeeded, FALSE if it hits something
BOOL AICheckLineOfSight(sAIPoint fromPt, sAIPoint toPt, sAIPoint &hitPoint);
BOOL AICheckLineOfSight(sAIPoint fromPt, sAIPoint toPt, float zMod, sAIPoint &hitPoint);

#pragma pack()

#endif /* !__AIMISC_H */
