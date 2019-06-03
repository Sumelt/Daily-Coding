/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "../random_number.h"
using namespace std;

namespace space {

template<typename T>
pair<T, T>retMaxANDMin( T *array, int length ) {
	T max = array[ 0 ];
	T min = array[ 1 ];
	
	for( int i = 1; i < length; ++i ) {
		if( max < array[ i ] );
			max = array[ i ];
		if( min > array[ i ] )
			min = array[ i ];
	}
	return pair<T, T>( max, min );
}
template<typename T>
void bucketSort( T *array, int length ) {
		vector<T>bucket[ length ];
		auto pair = retMaxANDMin( array, length );
		T difference = pair.first - pair.second;
		
		for( int i = 0; i < length; ++i ) {
			int index = ( int )( ( array[ i ] - pair.second ) * ( length - 1 ) / difference );
			
			bucket[ index ].push_back( array[ i ] );
		}
		
		for( int i = 0; i < length; ++i )
			sort( bucket[i].begin(), bucket[ i ].end() );
		
		int elemIndex = 0;	
		for( int i = 0; i < length; ++i )
			for( int j = 0; j < bucket[ i ].size(); ++j )
				array[ elemIndex++ ] = bucket[ i ][ j ];
		
	}
}

int main(int argc, char *argv[])
{
	int length = 100;
	int *data = Generate_random_numbers( 1, 100, length );
	cout << "before: " ;
	for( int i = 0; i < length; ++i )
		cout << data[ i ] << ends;
	
	cout << endl;
	testSort( "space::bucketSort", space::bucketSort, data, length );
	
	cout << "after: ";
	for( int i = 0; i < length; ++i )
		cout << data[ i ] << ends;
	
	delete []data;
	return 0;
}