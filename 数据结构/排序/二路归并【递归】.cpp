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


int main(int argc, char *argv[])
{
	int array[]	= {	8, 9, 4, 5, 2, 6, 7, 1 };
	int sumN = sizeof( array )/ sizeof( *array );	
	MerSort( array, 0, sumN );
	//NRMerSort( array, sumN );
	auto bg = begin( array );
	auto ed = end( array );
	while( bg != ed ) 
		cout << *bg++ << ' ';
		
	return 0;
}
