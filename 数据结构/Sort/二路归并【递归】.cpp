/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include "../random_number.h" 
using namespace std;

//递归版本1 
namespace MerSortVersion{

void _Merge( int *array, int *tempArray, int Lfirst, int mid, int Rlast )
{
	int Llast = mid;
	int Rfirst = mid + 1;
	int tp = Lfirst; //暂存开始位置，不然最后赋值回去再次有开销 
	
	while( Lfirst <= Llast && Rfirst <= Rlast )
	{
		if( array[ Lfirst ] <= array [ Rfirst ] )
			tempArray[ tp++ ] = array[ Lfirst++ ];
		else tempArray[ tp++ ] = array[ Rfirst++ ];			
	}
	
	while( Lfirst <= Llast ) 
		tempArray[ tp++ ] = array[ Lfirst++ ];
	while( Rfirst <= Rlast ) 
		tempArray[ tp++ ] = array[ Rfirst++ ];
	
	for( int i = 0; i < tp; ++i, --Rlast )  //巧妙赋值,前部分操作都只在对应暂存空间 操作 
		array[ Rlast ] = tempArray[ Rlast ];
}

void _sort( int *array, int *tempArray, int first, int last )//右边 最后的坐标 
{	
	if( first >= last ) return; //递归边界 ，只有一个元素直接返回 

	int mid = ( first + last )/2;
	_sort( array, tempArray, first, mid );
	_sort( array, tempArray, mid + 1, last );
	_Merge( array, tempArray, first, mid, last );
		
}

void MerSort( int *array, int L, int N ){
		int *tempArray = new int[ N ]; //临时空间
		_sort( array, tempArray, L,  N - 1 );
	}	
}

//优化版递归 
namespace optimizationMerSort{
//插入排序
void _insertSort( int *ary, int beginIndex, int endIndex ) {
	
	for( int index = beginIndex; index <= endIndex; ++index ) {
		int tempValue = ary[ index ];
		int tempIndex = index;
		while( tempIndex > 0 && tempValue < ary[ tempIndex - 1 ] ) {
			ary[ tempIndex ] = ary[ tempIndex - 1 ];
			--tempIndex;
		}	
		ary[ tempIndex ] = tempValue;
	}	
}

void _Merge( int *ary, int *aidArray, int LbeginIndex, int midIndex, int RendIndex ) {
	
	int LendIndex = midIndex;
	int RbeginIndex = midIndex + 1;
	int numberSize = RendIndex - LbeginIndex + 1;//要排序元素的个数
	int aidCurIndex = LbeginIndex;//辅助数组空间的下标
	
	//从首元素分别开始归并，也可从尾元素开始
    while( LbeginIndex <= LendIndex && RbeginIndex <= RendIndex ) {
		if( ary[ LbeginIndex ] < ary[ RbeginIndex ] )
			aidArray[ aidCurIndex++ ] = ary[ LbeginIndex++ ];
		else aidArray[ aidCurIndex++ ] = ary[ RbeginIndex++ ];
	}
	
	while( LbeginIndex <= LendIndex )
		aidArray[ aidCurIndex++ ] = ary[ LbeginIndex++ ];
	while( RbeginIndex <= RendIndex )
		aidArray[ aidCurIndex++ ] = ary[ RbeginIndex++ ];
		
	//辅助空间元素导回原始数组实现元素排列
    --aidCurIndex;
	for( int i = 0; i < numberSize; ++i, --aidCurIndex )
		ary[ aidCurIndex ] = aidArray[ aidCurIndex ];
		
}

void _sort( int *ary, int *aidArray, int beginIndex, int endIndex ){
	
	//优化一：待排元素个数小于给定的阈值转为插入排序 
	if( endIndex - beginIndex + 1 < 20 ) {
		_insertSort( ary, beginIndex, endIndex );
		return;
	}
	int midIndex = ( beginIndex + endIndex ) >> 1;
	
	_sort( ary, aidArray, beginIndex, midIndex );
	_sort( ary, aidArray, midIndex + 1, endIndex );
	
	//优化二：两序列是基本有序的不进行归并 
	if( ary[ midIndex ] > ary[ midIndex + 1 ] )
		_Merge( ary, aidArray, beginIndex, midIndex, endIndex );
}
//公有的归并函数接口	
void MerSort( int *ary, int length ) {
		int *aidArray = new int[ length ]();
		_sort( ary, aidArray, 0, length - 1 );
	}
}

int main(int argc, char *argv[])
{
	int length = 100;
	auto ary = Generate_random_numbers<>( 1, 50, length );
	
	optimizationMerSort::MerSort( ary, length );
	
	for( int index = 0; index < length; ++index )
		cout << ary[ index ] << ends;
	
	delete []ary;
		
		
	return 0;
}
