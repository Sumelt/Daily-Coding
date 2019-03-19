/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

int getKeyIndex( int *array, int leftIndex, int rightIndex )
{
	//主元选择左边第一个则从右边开始找，否则则相反
    int KeyIndex = leftIndex; //获得主元的下标
	int KeyValue = array[ KeyIndex ];//获得主元的元素值
	
	while( leftIndex < rightIndex ) {
		//寻找不符合右边元素大于主元的元素
        while( leftIndex < rightIndex && array[ rightIndex ] >= KeyValue )//右边先开始找，顺序不能乱
			--rightIndex;
        //寻找不符合左边元素小于主元的元素
		while( leftIndex < rightIndex && array[ leftIndex ] <= KeyValue )
			++leftIndex;
		//它们存在区间元素	
		if( leftIndex < rightIndex )
			swap( array[ leftIndex ], array[ rightIndex ] );		
	}
	swap( array[ leftIndex ], array[ KeyIndex ] );//leftIndex特别重要，它是主元的正确位置
	return leftIndex;
}

void qSort( int *array, int leftIndex, int rightIndex )
{
	if( leftIndex >= rightIndex ) return; //当区间元素为1时直接返回
	int midIndex = getKeyIndex( array, leftIndex, rightIndex );
	qSort( array, leftIndex, midIndex - 1 );//再次递归左边
	qSort( array, midIndex + 1, rightIndex );//再次递归右边
}

int main(int argc, char *argv[])
{
	int array[] = { 1, 6 };
	int length = sizeof( array )/sizeof( *array );
			
	qSort( array, 0, length - 1 );
	
	auto start = begin( array );
	auto last = end( array );
	while( start != last )
		cout << *start++ << " ";
				
	return 0;
}
