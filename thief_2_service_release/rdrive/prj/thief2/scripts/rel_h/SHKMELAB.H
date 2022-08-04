/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

////////////////////////////////////////////////
// $Header: r:/prj/cam/src/shock/RCS/shkmelab.h 1.1 1998/08/17 16:50:09 JON Exp $

#ifndef __SHKMELAB_H
#define __SHKMELAB_H

#include <plyablty.h>

class cPlayerMeleeAbility : public cPlayerAbility
{
public:
   cPlayerMeleeAbility(const sPlayerAbilityDesc *pDesc=NULL);
   virtual ~cPlayerMeleeAbility() {}

   virtual int GetNextSkillID(int skillID, ePlayerInput input, tPlayerActionType actType);

   virtual void SetupSkill(int skillID);

   virtual BOOL GetSoundSchemaName(int skillID,Label *pName);

   ///////

   void SetWeaponType(int wtype) { m_WeaponType=wtype; }
   int  GetWeaponType() const { return m_WeaponType; }

private:
   int m_WeaponType;
};

extern cPlayerMeleeAbility g_meleeAbility;

#endif // __SHKMELAB_H