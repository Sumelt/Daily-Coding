/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <queue>
#include <algorithm>
#include "../random_number.h"
using namespace std;

namespace heapSortVersion1{
void StackSort( priority_queue<char, vector<char>, 
	greater<char> > *Minstack, char *array ) {
		int i = 0;
		while( !Minstack->empty() ) {
			 array[ i++ ] = Minstack->top();
			 Minstack->pop();
		}
			
	}
}
//堆的类 
namespace heapSortVersion2 {
class maxHeap{
private:
	int *data = nullptr;
	int capacity = 0;
	int curCount = 0;

	void shiftDown( int index ) {
		int tempValue = data[ index ];
		while( 2 * index <= curCount ) {
			int leftIndex = 2 * index;
			if( leftIndex + 1 <= curCount && data[ leftIndex + 1 ] > data[ leftIndex ] )
				++leftIndex;
			if( tempValue >= data[ leftIndex ] )
				break;
			else data[ index ] = data[ leftIndex ];
			index = leftIndex;
		}
		data[ index ] = tempValue;
	}
		
	void shiftUp( int index ) {
		
		int tempValue = data[ index ];//暂存当前的要调整的元素值
		while( index > 1 && tempValue > data[ index / 2 ] ) {//暂存的元素值大于父节点的元素值
			data[ index ] = data[ index / 2 ];//父节点的元素值下来
			index /= 2;//当前节点上移
		}
		data[ index ] = tempValue;//正确的位置
	}

public:
	maxHeap( int length ) {
	
		capacity = length;	
		data = new int[ length + 1 ]();		
	}
	//heapify
	maxHeap( int *array, int length ) {
		
		capacity = length;
		curCount = length;
		data = new int[ length + 1 ]();
		copy( array, array + length, data + 1 );
		
		for( int i = curCount / 2; i >= 1; --i )
			shiftDown( i );
	}
	bool isEmpty() {
		
		return ( curCount == 0 );
	}
	
	int size() {
		return curCount;
	}
	//删除堆顶元素
	int popMax() {
	    int res = data[ 1 ];//保存堆顶元素
	    data[ 1 ] = data[ curCount ];//尾元素成为新堆顶
	    --curCount;
	    shiftDown( 1 );//开始向下调整
	    
	    return res;
	}
	
	void insert( int number ) {
			
	    assert( curCount <= capacity );//断言保证容量足够
	    data[ curCount + 1 ] = number;
	    shiftUp( curCount + 1 );
	    ++curCount;
	}

	~maxHeap() {
		delete []data;
	}
};

//堆元素一个个插入 
void maxHeadSort1( int *array, int length ) {
	maxHeap heap = maxHeap( length );
	
	for( int i = 0; i < length; ++i )
		heap.insert( array[ i ] );
	
	for( int i = length - 1; i >= 0; --i )
		array[ i ] = heap.popMax();
}
//直接把数组调整成最大堆 
void maxHeadSort2( int *array, int length ) {
	maxHeap heap = maxHeap( array, length );
	
	//从小到大排列 
	for( int i = length - 1; i >= 0; --i )
		array[ i ] = heap.popMax();

	}
}

namespace heapSortVersion3 {
//原地堆排序，不开辟额外空间	
void _shiftDown( int *array, int index, int length ) {
	
	int tempValue = array[ index ];
	int leftIndex = index * 2 + 1;
	
	while( leftIndex < length ) {
		//找出左右节点最大的下标
        if( leftIndex + 1 < length && array[ leftIndex + 1 ] > array[ leftIndex ] ) 
			++leftIndex;
		//利用暂存元素和左右节点中最大的进行比较
        if( tempValue >= array[ leftIndex ] ) //暂存节还是最大，则表示此位置是正确的则跳出
			break;
		else array[ index ] = array[ leftIndex ];//否则最大元素上移
		index = leftIndex;//暂存元素下标下移
		leftIndex = index * 2 + 1;//重新更新左节点的下标
	}
	array[ index ] = tempValue;
}

//数组下标从0开始存储 ，返回从小到大的元素序列 
void maxHeapSort( int *array, int length ) {
		for( int i = ( length - 2 ) / 2; i >= 0; --i )
			_shiftDown( array, i, length ); //把数组原地排成最大堆
			
		for( int i = length -  1; i > 0; --i ) {
			swap( array[ 0 ], array[ i ] );//把最大元素放到数组的尾部，形成数组从小到大排列
			_shiftDown( array, 0, i );//重新调整堆顶，向下调整
		}			
	}
}

int main(int argc, char *argv[])
{
	using namespace heapSortVersion3;
	
	int length = 100;
	int *data = Generate_random_numbers( 1, 100, length );
	
	testSort( "heapsort", maxHeapSort, data, length );
	for( int i = 0; i < length; ++i )
		cout << data[ i ] << ends;
	
	delete []data;
	
	return 0;
}