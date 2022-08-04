/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: x:/prj/tech/libsrc/matrix/RCS/mxmat.h 1.4 1998/09/11 12:16:19 MAT Exp $

#ifndef __MXDMAT_H
#define __MXDMAT_H
#pragma once

// This is the file to include to get the C++ sMxdVectors.

#include <mxmats.h>
#include <mxdmats.h>
#include <mxangs.h>

// Vector Operators

// This needs both types to define the copy constructors
inline sMxdVector::sMxdVector(const sMxVector &v) 
{x=v.x;y=v.y;z=v.z;}

inline sMxdVector &sMxdVector::operator=(const sMxVector &v) 
{x=v.x;y=v.y;z=v.z; return *this; }

// Vector Matrix functions:
// dest = M x v
inline sMxdVector &sMxdVector::Mul(const sMxdMatrix &m,const sMxdVector &v)
{mxd_mat_mul_vec(this,&m,&v); return *this;}
   
// v x= M, this is idiotic, if anyone uses it, I'll kill them        
inline sMxdVector &sMxdVector::MulEq(const sMxdMatrix &m)
{ mxd_mat_muleq_vec(&m,this);return *this;}

// dest = M^t x v, this is for multing by inverse if unit
inline sMxdVector &sMxdVector::TransMul(const sMxdMatrix &m,const sMxdVector &v)
{mxd_mat_tmul_vec(this,&m,&v); return *this;}
// v x= M^t
inline sMxdVector &sMxdVector::TransMulEq(const sMxdMatrix &m)
{ mxd_mat_tmuleq_vec(&m,this);return *this;}

// Vector Transform functions:
// multiply tform by vector
// this = t * v
inline sMxdVector &sMxdVector::Mul(const sMxdTrans &t,const sMxdVector &v)
{mxd_trans_mul_vec(this,&t,&v); return *this;}
   
// inverse multiply tform by vector
// this = t^t * v
inline sMxdVector &sMxdVector::TransMul(const sMxdTrans &t,const sMxdVector &v)
{mxd_trans_tmul_vec(this,&t,&v); return *this;}


// Matrix Operators with AngVecs and RadVecs

inline sMxdMatrix::sMxdMatrix(const sMxAngVec &a) 
{ mxd_ang2mat(this,&a);}
   
inline sMxdMatrix::sMxdMatrix(const sMxRadVec &r) 
{ sMxdVector v(r);mxd_rad2mat(this,&v);}

inline sMxdMatrix &sMxdMatrix::Set(const sMxAngVec &a) 
{ mxd_ang2mat(this,&a); return *this;}
   
inline sMxdMatrix &sMxdMatrix::Set(const sMxRadVec &r) 
{ sMxdVector v(r);mxd_rad2mat(this,&v); return *this;}


// Vector Angle
inline sMxdVector &sMxdVector::RotX(const sMxdVector &v,const sMxAng &a)
{ mxd_rot_x_vec(this,&v,a.a); return *this;}
inline sMxdVector &sMxdVector::RotY(const sMxdVector &v,const sMxAng &a)
{ mxd_rot_y_vec(this,&v,a.a); return *this;}
inline sMxdVector &sMxdVector::RotZ(const sMxdVector &v,const sMxAng &a)
{ mxd_rot_z_vec(this,&v,a.a); return *this;}



// Matrix angle ops
// Creates a matrix rotated about that axis by angle amount
inline sMxdMatrix &sMxdMatrix::RotX(sMxAng a)
{ mxd_mk_rot_x_mat(this,a.a); return *this; }
inline sMxdMatrix &sMxdMatrix::RotY(sMxAng a)
{ mxd_mk_rot_y_mat(this,a.a); return *this; }
inline sMxdMatrix &sMxdMatrix::RotZ(sMxAng a)
{ mxd_mk_rot_z_mat(this,a.a); return *this; }

// rotate matrix about that axis in its own frame by ang
inline sMxdMatrix &sMxdMatrix::RotX(const sMxdMatrix &m,sMxAng a)
{ mxd_rot_x_mat(this,&m,a.a); return *this; }
inline sMxdMatrix &sMxdMatrix::RotY(const sMxdMatrix &m,sMxAng a)
{ mxd_rot_y_mat(this,&m,a.a); return *this; }
inline sMxdMatrix &sMxdMatrix::RotZ(const sMxdMatrix &m,sMxAng a)
{ mxd_rot_z_mat(this,&m,a.a); return *this; }

// Rotate about a vector
inline sMxdMatrix &sMxdMatrix::RotVec(const sMxdVector &v, sMxAng a)
{ mxd_mk_rot_vec_mat(this,&v,a.a); return *this;}

#endif
