#pragma once

#ifdef _MSC_VER
#define CURVES_API __declspec( dllexport )
#else
#define CURVES_API
#endif

class CURVES_API Vector3f
{
private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

public:
	Vector3f( float x, float y, float z = 0.0f ) : x( x ), y( y ), z( z )
	{
	}

	float getX() const
	{
		return x;
	}
	float getY() const
	{
		return y;
	}
	float getZ() const
	{
		return z;
	}
};