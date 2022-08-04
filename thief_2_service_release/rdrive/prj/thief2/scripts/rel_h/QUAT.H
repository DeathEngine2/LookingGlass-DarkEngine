/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: x:/prj/tech/libsrc/quat/RCS/quat.h 1.2 1999/03/31 17:22:52 Johan Exp $

#ifndef __QUAT_H
#define __QUAT_H


#include <matrix.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Quaternion structure. Access as (w, x, y, z), (s, v), or el[4].
//
typedef struct quat
{
	union 
	{
		struct
		{
			mxs_real	s;
			mxs_vector	v;
		};
		struct 
		{
			mxs_real w, x, y, z;
		};

		mxs_real el[4];
	};

} quat;

// Get a rotation matrix representation of the quaternion.
EXTERN void quat_to_matrix(mxs_matrix * m, quat * q);

// Given a rotation matrix, create an equivalent quaternion.
EXTERN void quat_from_matrix(quat * q, mxs_matrix * m);

// Given axis and angle, create quaternion.
EXTERN void quat_create(quat * q, mxs_vector * axis, float angle);

// dest = p * q.
// Remember, when concatenating quaternions, p * q means apply q first, then 
// p.
EXTERN void quat_mul(quat * dest, quat * p, quat * q);

// 'Scale' is misleading, this interpolates between an identity quaternion
// and the given quaternion, using the given scale as the interpolation
// parameter.
EXTERN void quat_scale(quat * dest, quat * q, float scale);

// Interpolates between q1 and q2.
EXTERN void quat_slerp_cached_info(quat *dest, quat * q1, quat * q2, float t, mxs_vector *omega_info, bool flip);

// Interpolates between q1 and q2.
EXTERN bool quat_get_slerp_info(mxs_vector *omega_info, quat * q1, quat * q2);

// Interpolates between q1 and q2.
EXTERN void quat_slerp(quat * dest, quat * q1, quat * q2, float t);

// *dst = *src.
EXTERN void quat_copy(quat * dest, quat * src);

EXTERN void quat_identity(quat * q);

// For debug purposes. A quaternion that represents a 3D rotation always
// has unit magnitude.
EXTERN float quat_mag(quat * q);

   
#ifdef __cplusplus
}; // extern "C" {

# include <mxmat.h>

// C++ "class"
// You might notice that there is no "automatic" casting to mx_matrix
// This is intentionaly, use the class function ToMatrix for this.

struct sQuat : public quat
{
public:	// Constructors.
   sQuat() { };
   sQuat(const sMxVector &Axis,const float vAngle)		{ Set(Axis,vAngle); };
   sQuat(const sMxMatrix &Matrix)						{ Set(Matrix); };

public: // Assign functions
   inline void Set(const sMxVector &Axis,const float vAngle)		{ quat_create(this,(sMxVector *)&Axis,vAngle); };
   inline void Set(const sMxMatrix &Matrix)							{ quat_from_matrix(this,(sMxMatrix *)&Matrix); };
   inline void Identity()											{ quat_identity(this); };

public: // Slerp functions.
   inline void Scale(sQuat &Dest,const float vScale) const						{ quat_scale(&Dest,(sQuat *)this,vScale); };
   inline void Slerp(sQuat &Dest,const sQuat &Q2,const float vScale) const		{ quat_slerp(&Dest,(sQuat *)this,(sQuat *)&Q2,vScale); };
   
public: // Convertion
   inline void ToMatrix(sMxMatrix &Matrix) const 	{ quat_to_matrix(&Matrix,(sQuat *)this); };
   inline sMxMatrix ToMatrix() const 				{ sMxMatrix Result; ToMatrix(Result); return Result; };
   
public: // Operators.
   inline sQuat operator *(const sQuat &Left) const 	{ sQuat Result; quat_mul(&Result,(sQuat *)this,(sQuat *)&Left); return Result; };
   inline sQuat &operator =(const sQuat &Left) 			{ quat_copy(this,(sQuat *)&Left); return *this;};
};
   
#endif // _cplusplus

#endif

