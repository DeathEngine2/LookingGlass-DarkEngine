/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/mskltype.h 1.4 1997/12/18 14:18:02 kate Exp $

#ifndef __MSKLTYPE_H
#define __MSKLTYPE_H

#ifdef __cplusplus

// forward declarations of mskill data

//typedef struct sMSkill sMSkill;
typedef class cMSkill cMSkill;

typedef char *tMSkillIdentifier;
typedef cMSkill *tMSkillHandle;

#endif // cplusplus


typedef struct sMSkillDesc sMSkillDesc;
typedef struct sMSkillPhysDesc sMSkillPhysDesc;
typedef struct sMGaitSkillData sMGaitSkillData;

#endif
