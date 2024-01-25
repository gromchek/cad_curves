#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Curve.h"

#ifdef _MSC_VER
#define CURVES_API __declspec( dllexport )
#else
#define CURVES_API
#endif

class CURVES_API Circle : public Curve
{
public:
	float radius = 0.0f;

public:
	explicit Circle( const float r );
	Vector3f getPoint( const float t ) override;
	Vector3f getDerivative( const float t ) override;

	float GetRadius() const;
};

inline float Circle::GetRadius() const
{
	return radius;
}

#endif