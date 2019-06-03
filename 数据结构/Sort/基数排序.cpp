/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include "../random_number.h"
using namespace std;

namespace space{
template <typename T>
T retMax( T *arr, int length ) {
	T maxValue = arr[ 0 ];
	
	for( int i = 1; i < length; ++i )
		if( maxValue < arr[ i ] )
			maxValue = arr[ i ];
	return maxValue;
	
}

template <typename T>
void radixSort( T *arr, int length ) {
		vector<T>bucke[ 10 ];
		int maxValue = retMax( arr, length );
		int exp = 1;
		while( maxValue > 0 ) {
			
			for( int i = 0; i < length; ++i )
				bucke[ ( arr[ i ] / exp ) %10 ].push_back( arr[ i ] );
			
			exp *= 10;
			maxValue /= 10;
			
			for( int buckeIndex = 0, elemIndex = 0, index = 0; 
					buckeIndex < 10; ++buckeIndex ) {
				for( int elemIndex = 0; elemIndex < bucke[ buckeIndex ].size(); ++elemIndex )
					arr[ index++ ] = bucke[ buckeIndex ][ elemIndex ];
				bucke[ buckeIndex ].clear();
			}
		}
	}	
}




int main(int argc, char *argv[])
{
	int length = 100;
	int *data = Generate_random_numbers( 1, 10000, length );
	
	
	testSort( "space::radixSort", space::radixSort, data, length );

	delete []data;
	
	return 0;
}