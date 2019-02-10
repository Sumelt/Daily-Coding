/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>

using namespace std;

int RangeCount( const int *numbers, int length, int start, int end )
{
	if( numbers == nullptr ) return 0;
	int count = 0;
	for( int i = 0; i < length; ++i )
	  	if( numbers[ i ] >= start && numbers[ i ] <= end )
	  		++count;
	return count;
}

int getDuplication( const int *numbers, int length ) 
{
	if( numbers == nullptr || length <= 1 )
		return -1;
	int start = 1;
	int end = length - 1;	
	while( end >= start )
	{
		int mid = (( end - start )>>1) + start;
		int count = RangeCount( numbers, length, start, mid );
		if( end == start )
			if( count > 1 ) return start;
			else break;
		if( count > ( mid - start + 1 ))
			end = mid;
		else start = mid + 1;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int array[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	cout << getDuplication( array, sizeof( array )/sizeof( *array ));
	return 0;
}




