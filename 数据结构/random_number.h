#ifndef __RANDOM_NUMBER_H__
#define __RANDOM_NUMBER_H__

#include <iostream>
#include <random>
#include <ctime>
using namespace std;

template <typename T = int>
T *Generate_random_numbers( int startRange, int endRange, int sumCount = 10 );

template <typename T = int>
T *Generate_random_numbers( int startRange, int endRange, int sumCount )
{
	T *array = new T[ sumCount ]();
	
	default_random_engine e;
	uniform_int_distribution<T> u( startRange, endRange );
	
	for( int i = 0; i < sumCount; ++i )
		array[ i ]  = u( e );
		
	return array;
	
}
#endif