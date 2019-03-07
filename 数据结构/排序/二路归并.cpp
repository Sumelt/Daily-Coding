/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

//递归
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

void MerSort( int *array, int L, int N )
{
	int *tempArray = new int[ N ]; //临时空间
	_sort( array, tempArray, L,  N - 1 );
}

//非递归

void NRMerSort( int *array, int N ) 
{
	int *tempArray = new int[ N ]; //临时空间
	for( int length = 1; length <= N; length *= 2 )
	{
		int index = 0; 
		for( int i = 1; i <= N /(2 * length); ++i, index += 2 * length )
			_Merge( array, tempArray, index, index + length - 1, i + 2 * length - 1 );
			
		if( index + length < N )
			_Merge( array, tempArray, index, index + length, N - 1 );
		else 
			for( int k = index; k < N; ++k ) tempArray[ k ] = array[ k ];
	}
	if( N % 2 != 0 ) //说明是奇数，偶数不用处理 
		_Merge( array, tempArray, 0, N - 2, N - 1 );
		
		
	delete tempArray;
}

int main(int argc, char *argv[])
{
	int array[]	= {	8, 4, 5, 2, 6, 7, 1 };
	int sumN = sizeof( array )/ sizeof( *array );	
	MerSort( array, 0, sumN );
	//NRMerSort( array, sumN );
	auto bg = begin( array );
	auto ed = end( array );
	while( bg != ed ) 
		cout << *bg++ << ' ';
		
	return 0;
}
