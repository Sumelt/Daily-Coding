/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include "../random_number.h"
using namespace std;

namespace Binary_search {
template <typename T>
int Binarysearch( T *ary, int size, T target) {
		
		int leftIndex = 0, rightIndex = size - 1;
		while( leftIndex <= rightIndex ) {
			
			int midIndex = leftIndex + ( ( rightIndex - leftIndex ) >> 1 );
			if( target == ary[ midIndex ] )
				return midIndex;
			if( target > ary[ midIndex ] )
				leftIndex = midIndex + 1;
			else rightIndex = midIndex - 1;
		}
		return -1;
	}
template<typename T>
int floor( T *ary, int size, T target) {
	int leftIndex = 0, rightIndex = size - 1;
	while( leftIndex < rightIndex ) {
		
		int midIndex = leftIndex + ( ( rightIndex - leftIndex ) >> 1 );
		if( target <= ary[ midIndex ] )
			leftIndex = midIndex;
		else rightIndex = midIndex - 1;
	}
		
	return  leftIndex;	
}

template<typename T>
int ceil( T *ary, int size, T target) {
		int leftIndex = 0, rightIndex = size - 1;
		while( leftIndex <= rightIndex ) {
			
			int midIndex = leftIndex + ( ( rightIndex - leftIndex ) >> 1 );
			if( ary[ midIndex ] >= target )
				rightIndex = midIndex;
			else leftIndex = midIndex + 1;
		}
		if( rightIndex - 1 < size && ary[ rightIndex - 1 ] == target )
			return rightIndex - 1;
		
		return  rightIndex;		
	}
}


int main(int argc, char *argv[])
{
	int length = 20;
	int *ary = Generate_random_numbers( 20, 90, length );
	sort( ary, ary + length );	
	for( int i = 0; i < length; ++i )
		cout << ary[ i ] << ends;
	
	cout << endl << Binary_search::floor( ary, length, 23 );

	
	return 0;
}