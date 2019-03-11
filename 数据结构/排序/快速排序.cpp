/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

int getIndex( int *array, int leftIndex, int rightIndex )
{
	int keyValue = array[ rightIndex-- ];
	int keyIndex = rightIndex;
	
	while( leftIndex < rightIndex )
	{
		while( leftIndex < rightIndex && array[ leftIndex ] <= keyValue ) //寻找不符合左边元素值小于主元的位置 
			++leftIndex;
		while( rightIndex > leftIndex && array[ leftIndex ] >= keyValue ) //寻找不符合右边元素值大于主元的位置 
			--rightIndex;
		if( leftIndex < rightIndex ) //它们之间存在元素 
			swap( array[ leftIndex ], array[ rightIndex ] ); //直接交换 
		else break;//它们处于同一位置 
	}
	swap( array[ leftIndex ], array[ keyIndex ] );//把主元正确归位 
	
	return leftIndex;//返回主元的下标
}

void qSort( int *array, int leftIndex, int rightIndex )
{
	if( leftIndex >= rightIndex ) return;
	
	int keyIndex = getIndex( array, leftIndex, rightIndex ); //获得主元的下标 
	qSort( array, leftIndex, keyIndex - 1 );
	qSort( array, keyIndex + 1, rightIndex );
	
}

int main(int argc, char *argv[])
{
	int array[] = { 6, 2, 1, 5,3,0 };
	int length = sizeof( array )/sizeof( *array );
			
	qSort( array, 0, length - 1 );
	
	auto start = begin( array );
	auto last = end( array );
	while( start != last )
		cout << *start++ << " ";
				
	return 0;
}