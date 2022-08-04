/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////
// $Header: r:/prj/cam/src/shock/RCS/shkcs.h 1.1 1998/09/21 14:51:59 JON Exp $
//
// Commands associated with cut-scene recording/playback
//

#include <objtype.h>

EXTERN void CameraPositionSpew(void);
EXTERN void ShockCameraAttach(char *pObjName);
EXTERN void SetCameraEditStateRecord(void);
EXTERN void SetCameraEditStateEdit(void);
EXTERN void SetCameraEditStatePlayback(void);
EXTERN void SetCameraEditSpeed(float speed);
EXTERN void MakeScenes(void);
EXTERN void CutSceneStart(ObjID conversationID);
EXTERN void CutSceneEdit(ObjID conversationID);
EXTERN void CutSceneRecord(ObjID conversationID);
EXTERN void CutScenePlayback(ObjID conversationID);

