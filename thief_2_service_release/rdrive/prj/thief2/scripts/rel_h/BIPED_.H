/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Source: r:/prj/cam/src/RCS/biped_.h $
// $Author: kate $
// $Date: 1997/09/29 10:31:25 $
// $Revision: 1.8 $
//
// Biped internals

#ifndef __BIPED__H
#define __BIPED__H

#define MAX_BIPEDS 40

EXTERN Biped *bipeds[];
EXTERN ObjID bip_obj_ids[];
EXTERN int* obj_bip_ids;

#define BIP_TO_OBJ(bipid) (bip_obj_ids[bipid])
#define OBJ_TO_BIP(objid) (obj_bip_ids[objid])

#define BIPED_ACTIVE(bipid) (BIP_TO_OBJ(biped)!=OBJ_NULL)
#define OBJ_HAS_BIPED(objid) (BIP_TO_OBJ(OBJ_TO_BIP(objid))==objid)

// XXX this should be temporary.
// XXX TO DO: figure out why other version makes such uneven motions
#define BIPED_BUTT_HEIGHT(ab) (3.375*(ab)->motScale) 

#if 0
// distance from butt to toes
#define BIPED_BUTT_HEIGHT(ab) ((ab)->joints[BUTT].z- \
   (((ab)->joints[LTOE].z<(ab)->joints[RTOE].z)?(ab)->joints[LTOE].z: \
   (ab)->joints[RTOE].z))
#endif

EXTERN void BipedInit(Biped *ab, ObjID objID);
EXTERN BOOL BipedCalcBoundingData(Biped *ab);


#endif // __BIPED__H



