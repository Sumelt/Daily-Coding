/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include "..\random_number.h"
using namespace std;


namespace qSortVersion1{
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
	
	void _qsort( int *array, int leftIndex, int rightIndex )
	{
		if( leftIndex >= rightIndex ) return; //当区间元素为1时直接返回
		int midIndex = getKeyIndex( array, leftIndex, rightIndex );
		_qsort( array, leftIndex, midIndex - 1 );//再次递归左边
		_qsort( array, midIndex + 1, rightIndex );//再次递归右边
	}
	void qSort( int *array, int length ){
	
		_qsort( array, 0, length - 1 );
		
	}		
}

//一路快排 
namespace qSortVersion2{
	
	int _parttion( int *array, int beginIndex, int endIndex ) {
		
		int keyValue = array[ beginIndex ];
		int lastLessKeyIndex = beginIndex;//从主元的位置开始
		int curIndex = beginIndex + 1;
        
		for( curIndex; curIndex <= endIndex; ++curIndex )
			if( array[ curIndex ] < keyValue )//小于主元则移动到左边
				swap( array[ curIndex ], array[ ++lastLessKeyIndex ] );
        
		swap( array[ beginIndex ], array[ lastLessKeyIndex ] );//主元正确归位
		
		return lastLessKeyIndex;//返回主元下标
	}
	
	void _qsort( int *array, int beginIndex, int endIndex ) {
		
		if( beginIndex >= endIndex ) //递归边界
			return;
		int keyIndex = _parttion( array, beginIndex, endIndex );
		_qsort( array, beginIndex, keyIndex );
		_qsort( array, keyIndex + 1, endIndex );
		
	}
	
	void qSort( int *array, int length ){
	
		_qsort( array, 0, length - 1 );
		
	}
}

//随机主元快排
namespace qSortVersion3{
	int _parttion( int *array, int beginIndex, int endIndex ) {
		
		int randomIndex = ( rand() % ( endIndex - beginIndex + 1 ) ) + beginIndex;
		swap( array[ beginIndex ], array[ randomIndex ] );//优化二：采用随机主元 
		
		int keyValue = array[ beginIndex ];
		int lastLessKeyIndex = beginIndex;
		int curIndex = beginIndex + 1;
		for( curIndex; curIndex <= endIndex; ++curIndex )
			if( array[ curIndex ] < keyValue )
				swap( array[ curIndex ], array[ ++lastLessKeyIndex ] );
		swap( array[ beginIndex ], array[ lastLessKeyIndex ] );
		
		return lastLessKeyIndex;
	}
	
	void _qsort( int *array, int beginIndex, int endIndex ) {
		
		if( beginIndex >= endIndex ) //优化一：此处还可以在数据量较小的情况下转为插入排序 
			return;
		int keyIndex = _parttion( array, beginIndex, endIndex );
		_qsort( array, beginIndex, keyIndex );
		_qsort( array, keyIndex + 1, endIndex );
		
	}
	
	void qSort( int *array, int length ){		
		srand( time( nullptr ) );//随机数种子 
		_qsort( array, 0, length - 1 );
		
	}
}

//随机主元+二路快排 
namespace qSortVersion4{
	int _parttion( int *array, int beginIndex, int endIndex ) {
		
		int randomIndex = ( rand() % ( endIndex - beginIndex + 1 ) ) + beginIndex;
		swap( array[ beginIndex ], array[ randomIndex ] );//优化二：采用随机主元 
		
		int keyValue = array[ beginIndex ];
		int curLeftIndex = beginIndex + 1;
		int curRightIndex = endIndex;
		
		while( true ) {
			//这里的边界条件极其重要，元素值不能等于keyValue
			while( curLeftIndex <= curRightIndex && array[ curLeftIndex ] < keyValue )
				++curLeftIndex;
			while( curRightIndex >= curLeftIndex && array[ curRightIndex ] > keyValue )
				--curRightIndex;
				
			if( curLeftIndex > curRightIndex )
				break;
			else 
				swap( array[ curLeftIndex++ ], array[ curRightIndex-- ] );
            	//两元素相等也进行交换		
		}
		swap( array[ curRightIndex ], array[ beginIndex ] );
		return curRightIndex;
	}
	void _qsort( int *array, int beginIndex, int endIndex ) {
		
		if( beginIndex >= endIndex ) //优化一：此处还可以在数据量较小的情况下转为插入排序 
			return;
		int keyIndex = _parttion( array, beginIndex, endIndex );
		_qsort( array, beginIndex, keyIndex );
		_qsort( array, keyIndex + 1, endIndex );
		
	}
	void qSort( int *array, int length ){		
		srand( time( nullptr ) );//随机数种子 
		_qsort( array, 0, length - 1 );
		
	}
}

//三路快排 
namespace qSortVersion5 {
	void _qsort( int *array, int beginIndex, int endIndex ) {
		
		if( beginIndex >= endIndex )
			return;
		int randomIndex = ( rand() % ( endIndex - beginIndex + 1 ) ) + beginIndex;
		swap( array[ beginIndex ], array[ randomIndex ] );//优化二：采用随机主元
		
		int keyValue = array[ beginIndex ];
		int lessThenKeyEndIndex = beginIndex;//小于主元的区间的最后一个元素下标
		int bigThenKeyBeginIndex = endIndex;//大于主元的区间的第一个元素的下标
		int curIndex = beginIndex + 1;//当前访问元素的下标
		
		while( curIndex	<= bigThenKeyBeginIndex ) {
			if( array[ curIndex ] == keyValue )//等于主元
				++curIndex;
			else if( array[ curIndex ] < keyValue ) //小于主元
				swap( array[ ++lessThenKeyEndIndex ], array[ curIndex++ ] );
			else//大于主元
				swap( array[ curIndex ], array[ bigThenKeyBeginIndex-- ] );
		}
		swap( array[ beginIndex ], array[ lessThenKeyEndIndex ] );//主元正确归位
		_qsort( array, beginIndex, lessThenKeyEndIndex - 1 );//对主元左区间递归
		_qsort( array, bigThenKeyBeginIndex + 1, endIndex );//对主元右区间递归
	}	
	void qSort( int *array, int length ){		
		srand( time( nullptr ) );//随机数种子 
		_qsort( array, 0, length - 1 );
		
	}	
}

int main(int argc, char *argv[])
{
	int length = 600000;
	int *ary = Generate_random_numbers( 0, 50, length );
	testSort( "qsort", qSortVersion5::qSort, ary, length );
	
	delete []ary;
	
	return 0;
}
