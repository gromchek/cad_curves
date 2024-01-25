#ifndef __CURVE_H__
#define __CURVE_H__

#include "Vec3d.h"

#ifdef _MSC_VER
#define CURVES_API __declspec( dllexport )
#else
#define CURVES_API
#endif

class CURVES_API Curve
{
public:
	virtual ~Curve()
	{
	}
	virtual Vector3f getPoint( const float t ) = 0;
	virtual Vector3f getDerivative( const float t ) = 0;
};

#endif