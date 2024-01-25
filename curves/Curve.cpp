#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include <random>

std::vector<std::shared_ptr<Curve>> MakeCurvesContainer(unsigned int count)
{
    std::vector<std::shared_ptr<Curve>> curves;
	curves.reserve( count );


	std::random_device rd;
	std::mt19937 gen( rd() );
	std::uniform_real_distribution<float> dist( 5.0f, 50.0f );
	std::uniform_int_distribution<int> type( 0, 2 );

	for( int i = 0; i < count; ++i )
	{
		switch( type( gen ) )
		{
		case 0:
		{
			auto r = dist( gen );
			auto p = std::make_shared<Circle>( r );
			curves.push_back( p );
		}
		break;
		case 1:
		{
			auto rx = dist( gen );
			auto ry = dist( gen );
			curves.push_back( std::make_shared<Ellipse>( rx, ry ) );
		}
		break;
		case 2:
		{
			auto r = dist( gen );
			auto s = dist( gen );
			curves.push_back( std::make_shared<Helix>( r, s ) );
		}
		break;
		}
	}

    return curves;
}