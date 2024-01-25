#include "Circle.h"
#include <cmath>
#include <stdexcept>

Circle::Circle( const float r ) : radius( r )
{
	if( r < 0.0f )
	{
		throw std::invalid_argument( "Radius must be positive" );
	}
}

Vector3f Circle::getPoint( const float t )
{
	return { radius * std::cos( t ), radius * std::sin( t ) };
}
Vector3f Circle::getDerivative( const float t )
{
	return { -radius * std::sin( t ), radius * std::cos( t ) };
}