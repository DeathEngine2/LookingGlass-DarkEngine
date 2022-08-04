/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/RCS/aiext.h 1.26 1998/01/02 10:15:12 TOML Exp $
//
// This file is an external command file for the AI.  If
// you need anything from the AI, or to make it do
// anything, you should go through this interface,
// NOT ai.h.  Thank you, the management.
//
// @TBD (toml 09-28-97): COM-ize
//

#ifndef __AIEXT_H
#define __AIEXT_H

#include <aitype.h>
#include <schtype.h>
#include <cbllmtyp.h>

#ifdef __cplusplus

class cAI;
extern void AIGetAILocation(cAI *pAI, mxs_vector *v);
extern void  AINotifyAboutSound(cAI *pAI, sSchemaMsg *pMsg, int volume);     // when an AI might hear a sound, call this

extern "C" {

#endif // ifdef cplusplus

EXTERN BOOL ObjIsAI(ObjID);

#include <dbasemsg.h>
#include <dispbase.h>
#include <limits.h>

typedef enum
{
   kAIMsg_GoToLocation                   = 1,
   kAIMsg_StartPatrolling                = 2,
   kAIMsg_StopPatrolling                 = 3,
   kAIMsg_AttackObj                      = 4,
   kAIMsg_DefendObj                      = 5,
   kAIMsg_FollowObj                      = 6,
   kAIMsg_FrobObj                        = 7,
   kAIMsg_FleeObj                        = 8,
   kAIMsg_FleeEverything                 = 9,
   kAIMsg_StopFleeing                    = 10,
   kAIMsg_MakeAlert                      = 11,
   kAIMsg_ClearAllGoals                  = 12,
   AIMessageTypeIntMax=0xffffffff // force it use an int
} AIMessageType;

typedef struct AIObjAndLink
{
   ObjID   obj;
   LinkID  link;
} ObjAndLink;

typedef struct AIObjAndPriority
{
   ObjID            obj;
   eAIPriority  priority;
} AIObjAndPriority;

typedef struct AIObjAndPriorityAndAccuracy
{
   ObjID            obj;
   eAIPriority  priority;
   float            accuracy;
} AIObjAndPriorityAndAccuracy;

typedef struct AIFrobMsg
{
   ObjID            obj;
   eAIPriority  priority;
   float            accuracy;
   int              frobCommand;
} AIFrobMsg;

typedef struct AILocAndPriority
{
   mxs_vector       loc;
   eAIPriority  priority;
} AILocAndPriority;

typedef struct AIMessage
{
   ObjID           target;                        // the guy who's gonna get the msg
   AIMessageType   type;                          // what type of message is it?
   union                                          // what's the data?
   {
      AILocAndPriority            gotoLocation;   // kAIMsg_GoToLocation
      AIObjAndPriority            attack;         // kAIMsg_AttackObj
      AIObjAndPriority            defend;         // kAIMsg_DefendObj
      AIObjAndPriorityAndAccuracy follow;         // kAIMsg_FollowObj
      AIFrobMsg                   frob;           // kAIMsg_FrobObj
      AIObjAndPriority            flee;           // kAIMsg_FleeObj
      BOOL                        fleeEverything; // kAIMsg_FleeEverything
   };
} AIMessage;

#if 0
extern void  AISendMessage(AIMessage *message);
#endif

#if 0
extern void  AIClearAllGoals(ObjID objWithAI);
extern void  AISendToLocation(ObjID objWithAI, sAIPoint location, eAIPriority priority);
#endif
extern void  AIStartPatrolling(ObjID objWithAI);
#if 0
extern void  AIStopPatrolling(ObjID objWithAI);
extern void  AIAttackObj(ObjID objWithAI, ObjID obj, eAIPriority priority);
extern void  AIDefendObj(ObjID objWithAI, ObjID obj, eAIPriority priority);
extern void  AIFollowObj(ObjID objWithAI, ObjID obj, eAIPriority priority, float accuracy);
extern void  AIFrobObj(ObjID objWithAI, ObjID obj, eAIPriority priority, float accuracy, int frobCommand);
extern void  AIFleeObj(ObjID objWithAI, ObjID obj, eAIPriority priority);
extern void  AIFleeEverything(ObjID objWithAI, BOOL forever);
extern void  AIStopFleeing(ObjID objWithAI);
#endif
#if 0
extern void  AIMakeAlert(ObjID objWithAI);
#endif
extern int   AIGetMoveMode(ObjID objWithAI);

#if 0
extern void  AINotifyAboutObjDeath(ObjID id);                           // call this function whenever an object dies.
#endif
#if 0
extern void  AINotifyAboutDamage(ObjID objWithAI, ObjID damager);       // when an AI takes damage, call this
#endif
extern void  AINotifyAboutNewFastMovingObject(ObjID firer, ObjID fmo);  // when a new projectile is created, call this
#if 0
extern void  AINotifyAboutSwordSwing(ObjID swinger);
extern void  AINotifyAboutMotionFinish(ObjID ai, ulong appFlags);
#endif
extern void  AIPlayMotionName(ObjID obj, char *name);

extern void  AICreatePatrolLink(ObjID fromObj, ObjID toObj);
extern void  AIDeletePatrolLink(ObjID fromObj, ObjID toObj);

// Create/Delete an AI
extern tAIID  AICreateNewAI(eAITeamType team, BOOL isPlayer, ObjID obj);
#if 0
extern void  AIDeleteAI(tAIID id);
extern void  AIDeleteAllAIs();
#endif

#ifdef __cplusplus
#include <motrtype.h>
extern void AISetMotor(ObjID obj, IMotor *pMotor);

extern ICerebellum *AIGetCerebellum(ObjID obj);
#endif

// Init, Shutdown
extern void AIInit();
#if 0
extern void AIReset();
extern void AIRecalculateCells();
#endif
extern void AIShutDown();

// Loop oriented stuff
extern void AIDatabaseNotify(DispatchData* msg);
#if 0
extern void AIRead(tAIReadWriteFunc pfnReadWrite);
extern void AIWrite(tAIReadWriteFunc pfnReadWrite);
#endif
extern void AICycle(int deltaTime);

// Force set the AI's obj's location
extern void AIUpdateAILocation(ObjID objAI, sAIPoint pt);

#ifdef __cplusplus
}
#endif // ifdef cplusplus

///////////////////////////////////////////////////////////////////////////////

#endif /* !__AIEXT_H */
