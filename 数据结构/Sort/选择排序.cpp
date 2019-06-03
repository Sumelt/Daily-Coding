/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

int findMinValue( char *array, int i, int N )
{
	int MinIndex = i;
	char MinVlaue = array[ MinIndex ];
	int k = i + 1;//在目标位置之后找 
	if( k < N ) //存在最小值 
	{	
		for( ; k < N; ++k )
			if( array[ k ] < MinVlaue )
			{
				MinIndex = k;
				MinVlaue = array[ k ];
			}		
	}
		
	return MinIndex;
}


void SelectSort( char *array, int N )
{
	for( int i = 0; i < N; ++i)
	{
		int minIndex = findMinValue( array, i, N ); //可用最小堆优化 
		swap( array[ i ], array[ minIndex ] );
	} 
}

int main(int argc, char *argv[])
{
	char array[] = {'2','5','9','1','3','8','6','0','7','4'};
	SelectSort( array, sizeof( array )/ sizeof( *array ) );
	
	auto start = begin( array );
	auto last = end( array );
	while( start != last )
		cout << *start++ << ' ';
		
	return 0;
}