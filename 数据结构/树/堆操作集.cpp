/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>

using namespace std;
struct heap;
using Heap = struct heap*;
const int MaxSize = 50; //堆的最大容量 
const int MaxDate = 1000; //堆的哨兵 

struct heap{
	int *heapArray;
	int ArraySize;  //当前堆中的元素个数 
	heap( ){
		heapArray = new int[ MaxSize+1 ];
		ArraySize = 0;
		heapArray[ 0 ] = MaxDate;
	}
};


//堆调整
void downAdjust( heap *&hx, int indx) 
{
	int maxChildIndx = indx * 2; //存左孩子下标 
	/*while( maxChildIndx <= hx->ArraySize ) //存在左孩子 
	{
		if( maxChildIndx + 1 <= hx->ArraySize &&  //存在右孩子 且右孩子的权值大于左孩子权值 
			( hx->heapArray[ maxChildIndx+1 ] > hx->heapArray[ maxChildIndx ]) )
		{
			maxChildIndx = maxChildIndx + 1;
		} 
		if(  hx->heapArray[ indx ] < hx->heapArray[ maxChildIndx ] ) //该点的权值比它最大孩子的权值还小 
		{
			swap( hx->heapArray[ indx ], hx->heapArray[ maxChildIndx ] );//交换权值 权值较大上去 
			indx = maxChildIndx; //拿到下标 判断该位置合不合适 
			maxChildIndx = indx * 2;
		}
		else break; //找到合适的点 
			 
	}*/
	
	for( ; maxChildIndx <= hx->ArraySize; maxChildIndx = indx * 2 )
	{
		if( maxChildIndx + 1 <= hx->ArraySize &&  //存在右孩子 且右孩子的权值大于左孩子权值 
			( hx->heapArray[ maxChildIndx+1 ] > hx->heapArray[ maxChildIndx ]) )
		{
			maxChildIndx = maxChildIndx + 1;
		}
		if(  hx->heapArray[ indx ] < hx->heapArray[ maxChildIndx ] ) //该点的权值比它最大孩子的权值还小 
		{
			swap( hx->heapArray[ indx ], hx->heapArray[ maxChildIndx ] );//交换权值 权值较大上去 
			indx = maxChildIndx; //拿到下标 判断该位置合不合适 

		}
		else break;
	}
	
}

// 插入 (暂不判断是否满)
void insert( heap *&hx, int value )
{
	//hx->heapArray[ ++hx->ArraySize ] = value;
	int i = ++hx->ArraySize;
	for( ; hx->heapArray[ i/2 ] < value; i/=2 )  //向上调整 
		hx->heapArray[ i ] = hx->heapArray[ i/2 ];
	hx->heapArray[ i ] = value;
}

//堆删除
void deleteTop( heap *&hx )
{
	hx->heapArray[ 1 ] = hx->heapArray[ --hx->ArraySize ];
	downAdjust( hx, 1 ); //向下调整 
}

//堆创建
Heap CreateMaxHeap( int array[], int N )
{
	heap *h = new heap;
	for( int i = 0; i < N; ++i )
	{
		h->heapArray[ i+1 ] = array[ i ];
		++h->ArraySize;
	}

	for( int i = N/2; i >= 1; --i )
		downAdjust( h, i);

	return h;
		
}

int main()
{
	int array[] = {5, 1, 8, 0, 3, 6};
	heap *hp = CreateMaxHeap(array, sizeof( array )/sizeof( *array ));	
	//deleteTop( hp );
	insert( hp, 7 );
	for( int i = 1; i <= hp->ArraySize; ++i ) 
	{
		cout << hp->heapArray[ i ];
	}
	
	return 0;
}