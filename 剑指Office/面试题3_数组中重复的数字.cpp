/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>

using namespace std;

// time: O(n) space: O(n)
bool duplicate2( int numbers[], int length, int *duplication )
{
	bool flag[ length ] = { 0 };
	if( length <= 1 || numbers == nullptr )
		return false;
		
	for( int i = 0; i < length; ++i )
		if( numbers[ i ] < 0 || numbers[ i ] > length-1 )
			return false;
	for( int i = 0; i < length; ++i )
	{
		if( flag[ numbers[ i ]] )
			//return true;
			cout << numbers[ i ] << endl;
		else flag[ numbers[ i ]] = true;
	}
	return false;
}

// time: O(n) space: O(1)
bool duplicate( int numbers[], int length, int *duplication )
{
	if( length <= 1 || numbers == nullptr )
		return false;
		
	for( int i = 0; i < length; ++i )
		if( numbers[ i ] < 0 || numbers[ i ] > length-1 )
			return false;
	for( int i = 0; i < length; )
	{
		if( numbers[ i ] != i )
			if( numbers[ numbers[ i ]] != numbers[ i ] )
				swap( numbers[ i ], numbers[ numbers[ i ]] );
			else{
				*duplication = numbers[ i ];
				return true;
			}
		else ++i;
		
	}
	return false;
}

int main(int argc, char *argv[])
{
	int array[] = { 2, 3, 1, 0, 2, 5, 3, 5 };
	int duplication = -1;
	cout << "Result : " 
		<< duplicate2( array, sizeof( array )/sizeof( *array ), &duplication );

	return 0;
}




