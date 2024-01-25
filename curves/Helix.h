#ifndef __HELIX_H__
#define __HELIX_H_

#include "Curve.h"

#ifdef _MSC_VER
#define CURVES_API __declspec( dllexport )
#else
#define CURVES_API
#endif

class CURVES_API Helix : public Curve
{
public:
	float radius, step;

public:
	Helix( const float r, const float s );
	Vector3f getPoint( const float t ) override;
	Vector3f getDerivative( const float t ) override;

	float GetRadius() const;
	float GetStep() const;
};

inline float Helix::GetRadius() const
{
	return radius;
}

inline float Helix::GetStep() const
{
	return step;
}

#endif