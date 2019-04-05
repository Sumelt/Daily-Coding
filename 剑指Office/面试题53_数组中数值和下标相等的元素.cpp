/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

int getValueSameAsIndex( int array[], int length )
{
	int midIndex = length >> 1;
	int startIndex = 0;
	int endIndex = length - 1;
	while( startIndex < endIndex ) {
		if( midIndex == array[ midIndex ] )	
			return midIndex;
		else if( array[ midIndex ] > midIndex )//它的右边所有的值都大于下标
			endIndex = midIndex - 1;//则在前部分找
		else startIndex = midIndex + 1;//它的左边所有的值都小于下标，则在后半部分找
		midIndex = (endIndex + startIndex) >> 1;//重新获得中间下标
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int array[] = { -3, -1, 1, 3, 5 };
	cout << getValueSameAsIndex( array, 5 );
	return 0;
}