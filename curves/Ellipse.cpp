#include "Ellipse.h"
#include <cmath>
#include <stdexcept>

Ellipse::Ellipse( const float xRad, const float yRad ) : xRadius( xRad ), yRadius( yRad )
{
	if( xRad < 0.0f || yRad < 0.0f )
	{
		throw std::invalid_argument( "Radius must be positive" );
	}
}

Vector3f Ellipse::getPoint( const float t )
{
	return { xRadius * std::cos( t ), yRadius * std::sin( t ) };
}
Vector3f Ellipse::getDerivative( const float t )
{
	return { -xRadius * std::sin( t ), yRadius * std::cos( t ) };
}