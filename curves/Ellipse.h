#ifndef __ELLIPSE_H__
#define __ELLIPSE_H__

#include "Curve.h"

#ifdef _MSC_VER
#define CURVES_API __declspec( dllexport )
#else
#define CURVES_API
#endif

class CURVES_API Ellipse : public Curve
{
public:
	float xRadius = 0.0f;
	float yRadius = 0.0f;

public:
	Ellipse( const float xRad, const float yRad );
	Vector3f getPoint( const float t ) override;
	Vector3f getDerivative( const float t ) override;

	float GetXRadius() const;
	float GetYRadius() const;
};

inline float Ellipse::GetXRadius() const
{
	return xRadius;
}

inline float Ellipse::GetYRadius() const
{
	return yRadius;
}

#endif