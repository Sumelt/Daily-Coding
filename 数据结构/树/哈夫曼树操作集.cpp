/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

int MaxSize = 50; //堆的最大容量 
int MinDate = -1; //堆的哨兵 */

typedef struct TreeNode *HuffmanTree;
typedef struct heap *MinHeap;
typedef int *Heap;

struct TreeNode{
	int weight; //权值
	HuffmanTree lchild, rchild;
	TreeNode(int value) : lchild(NULL), rchild(NULL), weight(value){}

};

struct heap{
	vector< HuffmanTree > heapArray;
	int ArraySize;  //当前堆中的元素个数 
};


void InsertMinHeap( MinHeap &H, HuffmanTree &FT )
{
	int i = ++H->ArraySize;
	for( ; H->heapArray[ i/2 ]->weight > FT->weight; i/=2 )
		H->heapArray[ i ] = H->heapArray[ i/2 ];
	H->heapArray[ i ] = FT;
	
}


void downAdjust( MinHeap &hmin, int i )
{
	int minIndx = i*2;
	for( ; minIndx <= hmin->ArraySize; minIndx = i*2 ) //拿到 I的孩子节点下标 
	{
		if( minIndx+1 <= hmin->ArraySize && 
				hmin->heapArray[ minIndx ]->weight > hmin->heapArray[ minIndx+1 ]->weight )
			{
				minIndx = minIndx + 1; 
			}
		if( hmin->heapArray[ i ]->weight > hmin->heapArray[ minIndx ]->weight )
		{
			swap( hmin->heapArray[ i ], hmin->heapArray[ minIndx ] );
			i =  minIndx; //更新 I
		}
			
		else break;
	}
}


MinHeap BuildMinHeap( Heap array, int n)
{
	MinHeap minHeap = new heap;
	minHeap->heapArray.push_back( new TreeNode( MinDate ) );
	minHeap->ArraySize = n;
	for( int i = 0; i < n; ++i )
		minHeap->heapArray.push_back( new TreeNode( array[ i ] ) );
	for( int i = 1; i <= minHeap->ArraySize; ++i )
	{
		downAdjust( minHeap, i );
	}
		
	return minHeap;
}


HuffmanTree DeleteMinHeapTop( MinHeap &H )
{
	TreeNode *temp = H->heapArray[ 1 ];
	swap( H->heapArray[ 1 ], H->heapArray[ H->ArraySize ] );
	--H->ArraySize;
	downAdjust( H, 1 );

	return temp;
}


HuffmanTree CreatHuffmanTree( Heap array, int n )
{
	int i;
	HuffmanTree FT;
	MinHeap minHeap = BuildMinHeap( array, n ); //构建最小堆 
		
	for( int i = 1; i < n; ++i )
	{
	 	FT = new TreeNode(0);
	 	FT->lchild = DeleteMinHeapTop( minHeap );
	 	FT->rchild = DeleteMinHeapTop( minHeap );
	 	FT->weight = FT->lchild->weight + FT->rchild->weight;
	 	InsertMinHeap( minHeap, FT );
	}
	FT = DeleteMinHeapTop( minHeap );

	return FT;
}


void Print( HuffmanTree &FT )
{
	if( FT == NULL ) return;
	else
	{
		cout << FT->weight << " ";
		Print( FT->lchild );
		Print( FT->rchild );
	}
}


int main(int argc, char *argv[])
{
	int array[] = {3,1,2,5,4};
	HuffmanTree FT = CreatHuffmanTree( array, sizeof( array )/sizeof( *array ) );
	Print( FT );
	return 0;
}

