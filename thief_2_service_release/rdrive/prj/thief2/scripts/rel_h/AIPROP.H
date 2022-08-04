/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/aiprop.h 1.11 1998/03/26 13:51:32 mahk Exp $

#ifndef __AIPROP_H
#define __AIPROP_H

#include <property.h>
#include <wr.h>
////////////////////////////////////////////////////////////
// THE AI PROPERTY
//

//
// The AI property name
//
#define PROP_AI_NAME "AI"

F_DECLARE_INTERFACE(IIntProperty);
F_DECLARE_INTERFACE(IVectorProperty);
F_DECLARE_INTERFACE(IBoolProperty);

//////////////////////////////////////////////////////////////
// AIState
//
// This property is definitely accessed through the back
// door by the AI, and contains the frequently
// queried internal state information (generally stuff
// that designers shouldn't be messing with).

F_DECLARE_INTERFACE(IAIStateProperty);
#undef INTERFACE
#define INTERFACE IAIStateProperty

typedef struct sAIState sAIState;

DECLARE_PROPERTY_INTERFACE(IAIStateProperty)
{
   DECLARE_UNKNOWN_PURE(); 
   DECLARE_PROPERTY_PURE(); 
   DECLARE_PROPERTY_ACCESSORS(sAIState*); 
}; 

#define PROP_AI_STATE_NAME "AIState"
EXTERN  IAIStateProperty* gPropAIState;
EXTERN  void AIStatePropInit();
#define ObjHasAIState(obj) IProperty_IsRelevant(gPropAIState,obj)
EXTERN  sAIState* ObjGetAIState(ObjID obj);
#define ObjSetAIState(obj,hlm) PROPERTY_SET(gPropAIState,obj,hlm)
void SetupAIStateProperty();

//////////////////////////////////////////////////////////////
// AIHLD (high level destination)
//
// This property stores one full sAIHld
// struct as a property.


typedef struct sAIHld sAIHld;
typedef sAIHld AIHLD;

#undef INTERFACE
#define INTERFACE IAIHLDProperty
DECLARE_PROPERTY_INTERFACE(IAIHLDProperty)
{
   DECLARE_UNKNOWN_PURE(); 
   DECLARE_PROPERTY_PURE(); 
   DECLARE_PROPERTY_ACCESSORS(AIHLD*); 
}; 



#define PROP_AI_HLD_NAME "AIHiLevDest"
EXTERN  IAIHLDProperty* gPropAIHLD;
EXTERN  void AIHLDPropInit();
#define ObjHasAIHLD(obj) IProperty_IsRelevant(gPropAIHLD,obj)
EXTERN  sAIHld* ObjGetAIHLD(ObjID obj);
#define ObjSetAIHLD(obj,hlm) PROPERTY_SET(gPropAIHLD,obj,hlm)
void SetupAIHLDProperty();

//////////////////////////////////////////////////////////////
// All the other stinkin' little properties

// AI Team Property
// Good, bad, ugly
#define PROP_AI_TEAM_NAME "AITeam"
EXTERN  IIntProperty* gPropAITeam;
EXTERN  void AITeamPropInit();
#define ObjHasAITeam(obj) IProperty_IsRelevant(gPropAITeam,obj)
EXTERN  int ObjGetAITeam(ObjID obj);
#define ObjSetAITeam(obj,hlm) PROPERTY_SET(gPropAITeam,obj,hlm)

// AI Group Property
// Sort of a sub-team property.  At this writing, AI's had to
// be in the same group to respond to calls for help, but
// behavior is likely to expand or change. (6/12/97)
#define PROP_AI_GROUP_NAME "AIGroup"
EXTERN  IIntProperty* gPropAIGroup;
EXTERN  void AIGroupPropInit();
#define ObjHasAIGroup(obj) IProperty_IsRelevant(gPropAIGroup,obj)
EXTERN  int ObjGetAIGroup(ObjID obj);
#define ObjSetAIGroup(obj,hlm) PROPERTY_SET(gPropAIGroup,obj,hlm)

// AI High Level Mode Property
#define PROP_AI_HIGHLEVELMODE_NAME "AIHighLevelMode"
EXTERN  IIntProperty* gPropAIHighLevelMode;
EXTERN  void AIHighLevelModePropInit();
#define ObjHasAIHighLevelMode(obj) IProperty_IsRelevant(gPropAIHighLevelMode,obj)
EXTERN  int ObjGetAIHighLevelMode(ObjID obj);
#define ObjSetAIHighLevelMode(obj,hlm) PROPERTY_SET(gPropAIHighLevelMode,obj,hlm)

// AI High Level Combat Goal Property
#define PROP_AI_COMBATGOAL_NAME "AICombatGoal"
EXTERN  IIntProperty* gPropAIHighLevelCombatGoal;
EXTERN  void AIHighLevelCombatGoalPropInit();
#define ObjHasAIHighLevelCombatGoal(obj) IProperty_IsRelevant(gPropAIHighLevelCombatGoal,obj)
EXTERN  int ObjGetAIHighLevelCombatGoal(ObjID obj);
#define ObjSetAIHighLevelCombatGoal(obj,hlm) PROPERTY_SET(gPropAIHighLevelCombatGoal,obj,hlm)

// AI Alert Response Rate Property
// How fast do I become alerted? Ie, how fast do I see people?
#define PROP_AI_ALERTRESPONSERATE_NAME "AIResponseRate"
EXTERN  IIntProperty* gPropAIAlertResponseRate;
EXTERN  void AIAlertResponseRatePropInit();
#define ObjHasAIAlertResponseRate(obj) IProperty_IsRelevant(gPropAIAlertResponseRate,obj)
EXTERN  int ObjGetAIAlertResponseRate(ObjID obj);
#define ObjSetAIAlertResponseRate(obj,hlm) PROPERTY_SET(gPropAIAlertResponseRate,obj,hlm)

// AI Call For Help Property
// Should I call for help when I become fully alerted?
#define PROP_AI_CALLFORHELP_NAME "AICallForHelp"
EXTERN  IBoolProperty* gPropAICallForHelp;
EXTERN  void AICallForHelpPropInit();
#define ObjHasAICallForHelp(obj) IProperty_IsRelevant(gPropAICallForHelp,obj)
EXTERN  BOOL ObjGetAICallForHelp(ObjID obj);
#define ObjSetAICallForHelp(obj,hlm) PROPERTY_SET(gPropAICallForHelp,obj,hlm)

// AI Call For Respond to Help Property
// Should I go to people who are calling for help?
#define PROP_AI_RESPONDTOHELPCALL_NAME "AIRspToHelpCall"
EXTERN  IBoolProperty* gPropAIRespondToHelpCall;
EXTERN  void AIRespondToHelpCallPropInit();
#define ObjHasAIResponseToHelpCall(obj) IProperty_IsRelevant(gPropAIRespondToHelpCall,obj)
EXTERN  BOOL ObjGetAIRespondToHelpCall(ObjID obj);
#define ObjSetAIRespondToHelpCall(obj,hlm) PROPERTY_SET(gPropAIRespondToHelpCall,obj,hlm)

// AI Alerted Location Property
// Where should I go when if I become "fully alert"?
#define PROP_AI_ALERTEDLOC_NAME "AIAlertedLoc"
EXTERN  IVectorProperty* gPropAIAlertedLoc;
EXTERN  void AIAlertedLocPropInit();
#define ObjHasAIAlertedLoc(obj) IProperty_IsRelevant(gPropAIAlertedLoc,obj)
EXTERN  Vector* ObjGetAIAlertedLoc(ObjID obj);
#define ObjSetAIAlertedLoc(obj,hlm) PROPERTY_SET(gPropAIAlertedLoc,obj,hlm)

// AI Combat Dist Property
// What is the short-mid-far distances for combat
#define PROP_AI_COMBATDIST_NAME "AICombatDist"
EXTERN  IVectorProperty* gPropAICombatDist;
EXTERN  void AICombatDistPropInit();
#define ObjHasAICombatDist(obj) IProperty_IsRelevant(gPropAICombatDist,obj)
EXTERN  Vector* ObjGetAICombatDist(ObjID obj);
#define ObjSetAICombatDist(obj,hlm) PROPERTY_SET(gPropAICombatDist,obj,hlm)

// AI Combat Style Property
#define PROP_AI_COMBATSTYLE_NAME "AICombatStyle"
EXTERN  IIntProperty* gPropAICombatStyle;
EXTERN  void AICombatStylePropInit();
#define ObjHasAICombatStyle(obj) IProperty_IsRelevant(gPropAICombatStyle,obj)
EXTERN  int ObjGetAICombatStyle(ObjID obj);
#define ObjSetAICombatStyle(obj,hlm) PROPERTY_SET(gPropAICombatStyle,obj,hlm)

// AI Patrolling Property
// Am I currently patrolling?
#define PROP_AI_PATROLLING_NAME "AIPatrolling"
EXTERN  IBoolProperty* gPropAIPatrolling;
EXTERN  void AIPatrollingPropInit();
#define ObjHasAIPatrolling(obj) IProperty_IsRelevant(gPropAIPatrolling,obj)
EXTERN  BOOL ObjGetAIPatrolling(ObjID obj);
#define ObjSetAIPatrolling(obj,hlm) PROPERTY_SET(gPropAIPatrolling,obj,hlm)

// AI Wandering Property
// Am I currently wandering?
#define PROP_AI_WANDERING_NAME "AIWandering"
EXTERN  IBoolProperty* gPropAIWandering;
EXTERN  void AIWanderingPropInit();
#define ObjHasAIWandering(obj) IProperty_IsRelevant(gPropAIWandering,obj)
EXTERN  BOOL ObjGetAIWandering(ObjID obj);
#define ObjSetAIWandering(obj,hlm) PROPERTY_SET(gPropAIWandering,obj,hlm)

// AI Efficiency
// This property tells the AI not to go into efficiency
// mode whenever the player is sufficiently far away.
#define PROP_AI_NO_EFFICIENCY_NAME "AINoEfficiency"
EXTERN  IBoolProperty* gPropAINoEfficiency;
EXTERN  void AINoEfficiencyPropInit();
#define ObjHasAINoEfficiency(obj) IProperty_IsRelevant(gPropAINoEfficiency,obj)
EXTERN  BOOL ObjGetAINoEfficiency(ObjID obj);
#define ObjSetAINoEfficiency(obj,hlm) PROPERTY_SET(gPropAINoEfficiency,obj,hlm)

// AI Efficiency to Sleep Mode
// This property makes the AI go into sleep mode when he "exits" efficiency
// mode, rather than going into non combat mode.
#define PROP_AI_SLEEP_NAME "AISleep"
EXTERN  IBoolProperty* gPropAISleep;
EXTERN  void AISleepPropInit();
#define ObjHasAISleep(obj) IProperty_IsRelevant(gPropAISleep,obj)
EXTERN  BOOL ObjGetAISleep(ObjID obj);
#define ObjSetAISleep(obj,hlm) PROPERTY_SET(gPropAISleep,obj,hlm)

#endif // !__AIPROP_H
