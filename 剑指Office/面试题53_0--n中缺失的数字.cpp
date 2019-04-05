/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

int getLostNumber( int array[], int startIndex, int endIndex )
{
	if( startIndex > endIndex )
		return -1;
	int midIndex = ( startIndex + endIndex ) >> 1;
	
	if( midIndex != array[ midIndex ] ) {
		if( ( midIndex > 0 && midIndex - 1 == array[ midIndex - 1 ] || 
			midIndex == 0 ) )
		return midIndex;
		else endIndex = midIndex - 1;//第一个不相等的元素在前部分
	}
	else {
		startIndex = midIndex + 1;//相等则不断在后部分找
	}
	return getLostNumber( array, startIndex, endIndex );	
}

int main(int argc, char *argv[])
{
	int arry[  ] = { 0, 1, 2, 3, 4, 5, 6, 8, 9, 10 };
	cout << getLostNumber( arry, 0, 9 );
	return 0;
}