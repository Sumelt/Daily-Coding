/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include "../random_number.h"
using namespace std;

namespace spaceMaxIndexHeap {
	
}

//下标从0开始存储，泛型 写法 
namespace spaceMinIndexHeap {
template<typename Item>
class minIndexHeap {
private:
	Item *data = nullptr;
	int *indexHeap = nullptr;
	int *reverse = nullptr;
	int capacity;
	int curCount;

	void shiftDown( int index ) {
		Item tempValue = data[ indexHeap[ index ] ];//暂存元素值 
		int tempIndex = indexHeap[ index ];//暂存要调整元素的下标 
		while( 2 * index + 1 < curCount ) {
			int leftIndex = 2 * index + 1;
			if( leftIndex + 1 < curCount && 
				data[ indexHeap[ leftIndex + 1 ] ] < data[ indexHeap[ leftIndex ] ] )
					++leftIndex;
			if( tempValue <= data[ indexHeap[ leftIndex ] ] )
				break;
			else {
				indexHeap[ index ] = indexHeap[ leftIndex ];
				reverse[ indexHeap[ index ] ] = index;
			}				
			index = leftIndex;
		}
		indexHeap[ index ] = tempIndex;//更新
		reverse[ indexHeap[ index ] ] = index;
	}
	
	void shiftUp( int index ) {
		
		Item tempValue = data[ indexHeap[ index ] ];//暂存当前的要调整的元素值
		int tempIndex = indexHeap[ index ];//暂存要调整元素的下标 
		while( index >= 1 && tempValue < data[ indexHeap[ ( index - 1 ) / 2 ] ] ) {//从索引中获得父节点的元素值 
			indexHeap[ index ] = indexHeap[ ( index - 1 ) / 2 ];//父节点的元素值下标 下来
			reverse[ indexHeap[ index ] ] = index;
			index = ( index - 1 ) / 2;
		}
		indexHeap[ index ] = tempIndex;//更新正确的元素下标
		reverse[ indexHeap[ index ] ] = index;
	}	
public:
	minIndexHeap( int size ) {
		capacity = size;
		curCount = 0;	
		data = new int[ size ]();
		indexHeap = new int[ size ]();
		reverse = new int[ size ]();
		fill( reverse, reverse + size, -1 ); //下标为0有意义，contain中不能以0判断 		
	}
	~minIndexHeap() {
		delete []data;
		delete []indexHeap;
		delete []reverse;		
	}
	
	bool isEmpty() {		
		return ( curCount == 0 );
	}
	
	int size() {
		return curCount;
	}	
	
	int popMinIndex() {
	    int minIndex = indexHeap[ 0 ];//保存堆顶元素
	    indexHeap[ 0 ] = indexHeap[ curCount - 1 ];//尾元素成为新堆顶
	    reverse[ indexHeap[ curCount - 1 ] ] = 0;
	    --curCount;
	    shiftDown( 0 );//开始向下调整
	    
	    return minIndex; //还原成用户需要的数组下标，即是从0开始 		
	}
	
	void insert( int index, Item number ) {
		//断言保证容量足够且保证下标不越界 
	    assert( index >= 0 && index < capacity && curCount < capacity );
	    assert( !contain( index ) );
	    
	    ++curCount;
		data[ index ] = number;
		indexHeap[ curCount - 1 ] = index;
		reverse[ indexHeap[ curCount - 1 ] ] = curCount - 1;
		
		shiftUp( curCount - 1 );
		cout << "UP: ";
		for( int i = 0; i < curCount; ++i )
			cout << data[ indexHeap[ i ] ] << ' ';
		cout << endl;
	}
	
	bool contain( int index ) {
		//确保用户指定的下标没有越界
		assert( index >= 0 && index < capacity ); 
		//检查此位置是否存在元素 
		return ( reverse[ index ] != -1 );
	}
	void change( int index, Item number ) {			
			assert( contain( index ) );
			data[ index ] = number;
			shiftDown( reverse[ index ] );			
			shiftUp( reverse[ index ] );

		}
	void test() {
			cout << "test: ";
			for( int i = 0; i < 4; ++i )
				cout << data[ this->popMinIndex() ] << ' ';	
		}			
	};
}


int main(int argc, char *argv[])
{
	using namespace spaceMinIndexHeap;
	int length = 10;
	int *data = Generate_random_numbers( 20, 600, length );
	for( int i = 0; i < length; ++i )
		cout << data[ i ] << ' ';
	cout << endl;
	minIndexHeap<int> minHeap( length );
	for( int i = 0; i < length; ++i )
	 minHeap.insert( i, data[ i ] );
 	
	//minHeap.change( 4, 415 );
	minHeap.test();
	return 0;
}