/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <climits>
using namespace std;

int maximumProfit( int array[], int length )
{
	if( array == nullptr || length == 0 )
		return 0;
		
	int minBeforePrice = array[ 0 ];
	int maxProfit = array[ 1 ] - minBeforePrice;
	
	for( int i = 2; i < length; ++i ) {
		if( array[ i - 1 ] < minBeforePrice )
			minBeforePrice = array[ i - 1 ];
			
		int curProfit = array[ i ] - minBeforePrice;
		
		if( maxProfit < curProfit )
			maxProfit = curProfit;
	}	
}

int main(int argc, char *argv[])
{
	int array[  ] = { 9, 11, 8, 5, 7, 12, 16, 14 };
	cout << maximumProfit( array, 8 );
	return 0;
}