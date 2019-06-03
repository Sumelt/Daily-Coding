
/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include "../random_number.h" 
using namespace std;

//非递归
namespace NRMerSort {
void _Merge( int *array, int *tempArray, int Lfirst, int mid, int Rlast )
{
	int Llast = mid - 1;
	int Rfirst = mid;
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

void NRMerSort( int *array, int N ) {
	int *tempArray = new int[ N ]; //临时空间
	int i = 0;
	for( int length = 1; length < N; length *= 2 ) //length 为一个序列的长度 
	{ 
		for( i = 0; i < N  - (2 * length); i += 2*length ) // i 为能取得的下标 ，不是循环的次数 
		{
			cout << "i " << i  << " length " << length <<endl;
			_Merge( array, tempArray, i, i + length, i + 2 * length - 1 );			
		}
			
		if( i + length < N ) //还剩下两个区间可以合并，一个区间长度满足length，另一个区间不满足 
		{
			cout << "other " << endl;
			cout << "i " << i  << " length " << length <<endl;
			_Merge( array, tempArray, i, i + length, N - 1 );
		}
			
		else; //还剩一个区间，但该区间长度不满足一个length 
	}
	
		delete tempArray;
   }	
}

namespace bottonUpMergeSort{
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
void bottonUpMergeSort( int *ary, int length ) {		
	int *aidArray = new int[ length ]();
    //第一层for循环是从每个序列元素个数为1开始两两归并，然后下一次是元素个数为2的序列两两归并，一直到整个序列
    //第二层for循环是两个序列归并之后，再到下两个序列归并
	for( int sequenceSize = 1; sequenceSize <= length; sequenceSize += sequenceSize ) {
	
        //条件：fstSeqBegIndex + sequenceSize < length 保证至少存在两个序列
        for( int fstSeqBegIndex = 0; fstSeqBegIndex + sequenceSize < length; 
			fstSeqBegIndex += sequenceSize + sequenceSize )//移动到下两个序列

//序列【fstSeqBegIndex，fstSeqBegIndex + sequenceSize - 1】
//和序列【fstSeqBegIndex + sequenceSize, fstSeqBegIndex + sequenceSize*2 - 1 】归并
		_Merge( ary, aidArray, fstSeqBegIndex, fstSeqBegIndex + sequenceSize - 1,  
               min( fstSeqBegIndex + sequenceSize + sequenceSize - 1 , length - 1 ) );	//这里有三种情况
//全部满足两两归并（这时整个序列被分割成多份）
//前一部分满足两两归并，最后只剩下一个序列（此序列不做任何归并而是进行下一次的第一层for序列个数叠加；这时整个序列还是被分割成多份）
//前一部分满足序列个数，后一部分不满足序列个数（这时整个序列只被分成两部分），它们两两归并即可
		}
	}
}

/*
1 2 3 4 5 6 7 8 9 10
序列个数为1时归并：1 | 2 -- 3 | 4 -- 5 | 6 -- 7 | 8 -- 9 | 10 
序列个数为2时归并：1 2 | 3 4 -- 5 6 | 7 8 -- 9 10 | xx
序列个数为4时归并：1 2 3 4 | 5 6 7 8 -- 9 10 xx
序列个数为8时归并：1 2 3 4 5 6 7 8 | 9 10
*/  

int main(int argc, char *argv[])
{
	int length = 13;
	auto ary = Generate_random_numbers<>( 1, 50, length );
	
//	for( int index = 0; index < length; ++index )
//		cout << ary[ index ] << ends;
//	cout << endl;	

	bottonUpMergeSort::bottonUpMergeSort( ary, length );
	
	for( int index = 0; index < length; ++index )
		cout << ary[ index ] << ends;
	
	delete []ary;	
		
	return 0;
}
