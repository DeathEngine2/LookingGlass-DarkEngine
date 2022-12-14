/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/RCS/meshapi.h 1.2 1998/01/20 23:25:05 kate Exp $

#ifndef __MESHAPI_H
#define __MESHAPI_H

#include <qt.h>
#include <matrixs.h>
#include <mms.h>

class IMesh
{
public:
// renderer functions
//
   virtual void MeshJointPosCallback(const int jointID, mxs_trans *pTrans)=0;
   virtual void MeshStretchyJointCallback(const int jointID, mxs_trans *pTrans, quat *pRot)=0;

// shape functions
//
   virtual float GetRadius()=0;
   virtual void GetWorldBBox(mxs_vector *pBMin, mxs_vector *pBMax)=0;
private:

};

#endif
