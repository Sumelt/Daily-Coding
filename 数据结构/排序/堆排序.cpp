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

namespace heapSortVersion2 {
class maxHeap{
private:
	int *data = nullptr;
	int sumCount = 0;
	int curCount = 0;
		void shiftDown( int index ) {
		
		int tempValue = data[ index ];//当前节点元素值
		int leftIndex = index * 2;
		int rigthIndex = leftIndex + 1;
        
		while( leftIndex <= curCount ) {//存在左节点
			if( rigthIndex <= curCount ) { //存在右节点
				int maxIndex = maxValueIndex( leftIndex, rigthIndex );//返回左右节点中值最大的下标
				data[ index ] = data[ maxIndex ];//最大元素上移
				index = maxIndex;//当前节点下移
			}
			else if( data[ index ] < data[ leftIndex ] ) {
				data[ index ] = data[ leftIndex ];
				index = leftIndex;
			}
			else break;//找到合适的位置
            //更新当前节点后也要同步更新左右子节点
			leftIndex = index * 2;
			rigthIndex = leftIndex + 1;				
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
	int maxValueIndex( int leftIndex, int rigthIndex ) {
		
		return data[ leftIndex ] > data[ rigthIndex ] ? leftIndex : rigthIndex;
	}

public:
	maxHeap( int length ) {
	
		sumCount = length;	
		data = new int[ length + 1 ]();		
	}
	//heapify
	maxHeap( int *array, int length ) {
		
		sumCount = length;
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
	int popMax() {
		
		int res = data[ 1 ];
		data[ 1 ] = data[ curCount ];
		--curCount;
		shiftDown( 1 );
		return res;
	}
	
	void insert( int number ) {
		
		assert( curCount <= sumCount );
		data[ ++curCount ] = number;
		shiftUp( curCount );		
	}

	~maxHeap() {
		delete []data;
	}
 };

void maxHeadSort1( int *array, int length ) {
	maxHeap heap = maxHeap( length );
	
	for( int i = 0; i < length; ++i )
		heap.insert( array[ i ] );
	
	for( int i = length - 1; i >= 0; --i )
		array[ i ] = heap.popMax();
}

void maxHeadSort2( int *array, int length ) {
	maxHeap heap = maxHeap( array, length );
	
	for( int i = 0; i < length; ++i )
		array[ i ] = heap.popMax();
	}

}
	

int main(int argc, char *argv[])
{
	using namespace heapSortVersion2;
	
	int length = 20;
	int *data = Generate_random_numbers( 1, 100, length );
	maxHeadSort1( data, length );
	
	for( int i = 0; i < length; ++i )
		cout << data[ i ] << ends;
	
	delete []data;
	
	return 0;
}