#ifndef __CURVE_H__
#define __CURVE_H__

#include "Vec3d.h"
#include <vector>
#include <memory>

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

CURVES_API std::vector<std::shared_ptr<Curve>> MakeCurvesContainer(unsigned int count);

#endif