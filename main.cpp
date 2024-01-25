#include <iostream>
#include <random>
#include <vector>
#include <cmath>
#include <algorithm>
#include <memory>

#include "curves/Circle.h"
#include "curves/Ellipse.h"
#include "curves/Helix.h"

#include <mutex>
#include <thread>

std::mutex radMutex;

void sumUp( double &sum, const std::vector<std::shared_ptr<Circle>> &circles, unsigned int beg, unsigned int end )
{
	double tmpSum = 0.0;
	for( auto i = beg; i < end + 1; i++ )
	{
		tmpSum += circles[i]->GetRadius();
	}
	std::lock_guard<std::mutex> lockGuard( radMutex );
	sum += tmpSum;
}

int main()
{
	const int SHAPES_COUNT = 1024;
	std::vector<std::shared_ptr<Curve>> curves;
	curves.reserve( SHAPES_COUNT );


	std::random_device rd;
	std::mt19937 gen( rd() );
	std::uniform_real_distribution<float> dist( 5.0f, 50.0f );
	std::uniform_int_distribution<int> type( 0, 2 );

	for( int i = 0; i < SHAPES_COUNT; ++i )
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

	const auto pi4 = M_PI / 4.0f;
	for( const auto &curve : curves )
	{
		const auto &point = curve->getPoint( pi4 );
		const auto &vec = curve->getDerivative( pi4 );
		std::cout << "Point: " << point.getX() << ", " << point.getY() << ", Derivative: " << vec.getX() << ", "
				  << vec.getY() << ", " << vec.getZ() << "\n";
	}


	std::vector<std::shared_ptr<Circle>> circles;
	circles.reserve( SHAPES_COUNT / 3 );
	for( const auto &curve : curves )
	{
		auto p = std::dynamic_pointer_cast<Circle>( curve );
		if( p )
		{
			circles.push_back( p );
		}
	}

	std::sort( circles.begin(), circles.end(),
			   []( std::shared_ptr<Circle> a, std::shared_ptr<Circle> b ) { return a->GetRadius() < b->GetRadius(); } );


	double sum = 0.0;
	const int MAX_THREADS_COUNT = 4;
	const int partSize = circles.size() / MAX_THREADS_COUNT;
	const int remainder = circles.size() % MAX_THREADS_COUNT;
	for( int i = 0; i < MAX_THREADS_COUNT; i++ )
	{
		int begin = i * partSize;
		int end = begin + partSize - 1;

		if( i == ( MAX_THREADS_COUNT - 1 ) )
		{
			end += remainder;
		}

		std::thread t( sumUp, std::ref( sum ), std::cref( circles ), begin, end );
		t.join();
	}

	std::cout << "Sum of circles radius: " << sum << "\n";

	return 0;
}