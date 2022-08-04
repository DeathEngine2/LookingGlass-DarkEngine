/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/aicbllm.h 1.9 1998/02/02 15:58:23 kate Exp $

#ifndef __AICBLLM_H
#define __AICBLLM_H

#include <mclntapi.h>
#include <motdesc.h> // for death
#include <cbllmtyp.h>

/////////////////////////////////////////////////////////////////////////////
//
// STRUCT: sAIMotionRequest
// 
// This is used by other AI subsystems when they want to request a motion
//

struct sAIMotionRequest
{
   BOOL isInterrupt;
   BOOL noMotion; // if this is TRUE, don't actually request a motion but
                  // can still potentially abort current motions etc
   eManeuverPriority priority;
   sMcMoveParams params;
};

/////////////////////////////////////////////////////////////////////////////
//
// CLASS: cAICerebellum
// 
// This is the part of the AI responsible for mediating between all the
// motion requests and telling the body what it actually wants to do
//

#include <aicrbtyp.h>
#include <objtype.h>
#include <ai.h> // XXX is this only way to get cAI *?
#include <cbllmapi.h>

class cAICerebellum : public ICerebellum
{
public:
   cAICerebellum(ObjID objID, cAI *pAI);
   ~cAICerebellum();

   // returns FALSE if cerebellum is idle, else TRUE
   BOOL DoingManeuver();

   virtual void PlayMotion(const char *name, eManeuverTransitionType trans=kMnvrTrans_Immediate,eManeuverPriority=kMnvrPri_Script);

   virtual void Update(ulong deltaTime);

   void SetMotor(IMotor *pMotor);

   void Die();

   void MotorStateChangeCallback();
   void ManeuverCompletionCallback(IManeuver *pCompleted, IManeuver *pNext);

   const sAIMotionRequest *GetMotionRequest() const { return m_pMotionRequest; }
   BOOL SetMotionRequest(sAIMotionRequest *pRequest);
private:
   cAI *m_pAI;
   IMotionCoordinator *m_pMotionCoord;
   sAIMotionRequest *m_pMotionRequest;
   BOOL m_StartDying;
   BOOL m_IsDying;
   BOOL m_CurrentlyStationary;
   mxs_ang m_DesiredFacing;
   mxs_vector m_DesiredPosition;
   eManeuverPriority m_CurrentMnvrPriority;
};

///////////////////////////////////////////////////////////////////////////////


#endif
