/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

int minNumberInRotateArray(vector<int> rotateArray) {
	int prPtr = 0; int lastPtr = rotateArray.size() - 1;
	int midPtr = prPtr;
	int midValue = 0;
	if( rotateArray[ prPtr ] < rotateArray[ lastPtr ] ) 
		return rotateArray[ prPtr ];  //数组是有序的
	midPtr = ( prPtr + lastPtr ) / 2;
	
	while( lastPtr - prPtr != 1 )
	{
		if( rotateArray[ midPtr ] == rotateArray[ prPtr ] &&
			rotateArray[ midPtr ] == rotateArray[ lastPtr ] ) { //前后中间指针的值都相等 
				midValue = rotateArray[ prPtr ];
				for( int i = prPtr + 1; i <= lastPtr; ++i )
					if( rotateArray[ i ] < midValue )
						midValue = rotateArray[ i ];
				break;
			}				
		if( rotateArray[ midPtr ] >= rotateArray[ prPtr ] ) //最小值位于之后 
				prPtr = midPtr;
		else if( rotateArray[ midPtr ] <= rotateArray[ lastPtr ] ) //最小值位于之前 
				lastPtr = midPtr;
		midPtr = ( prPtr + lastPtr ) / 2; //重新计算中间值 
	}
	if( lastPtr - prPtr == 1 )
		midValue = rotateArray[ lastPtr ];
	return midValue;
}

int main(int argc, char *argv[])
{
	cout << minNumberInRotateArray( vector<int>{} );
	return 0; 
}