#include "Helix.h"
#include <cmath>
#include <stdexcept>

Helix::Helix( const float r, const float s ) : radius( r ), step( s )
{
	if( r < 0.0f || s < 0.0f )
	{
		throw std::invalid_argument( "Radius must be positive" );
	}
}

Vector3f Helix::getPoint( const float t )
{
	return { radius * std::cos( t ), radius * std::sin( t ), t * step / float( 2.0f * M_PI ) };
}
Vector3f Helix::getDerivative( const float t )
{
	return { -radius * std::sin( t ), radius * std::cos( t ), step / float( 2.0f * M_PI ) };
}