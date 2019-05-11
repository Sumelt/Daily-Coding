/*
 *对最小生成树中提供底层数据结构支撑 
 */

#ifndef __MINHEAP_H__
#define __MINHEAP_H__

#include <iostream>
#include <cassert>

template<typename Item>
class MinIndexHeap {
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
	MinIndexHeap( int size ) {
		capacity = size;
		curCount = 0;	
		data = new Item[ size ]();
		indexHeap = new int[ size ]();
		reverse = new int[ size ]();
		fill( reverse, reverse + size, -1 ); //下标为0有意义，contain中不能以0判断 
	}
	~MinIndexHeap() {
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
	    
	    return minIndex ; //还原成用户需要的数组下标，即是从0开始 
	
	}

	Item popMinItem() {
	    int minIndex = indexHeap[ 0 ];//保存堆顶元素
	    indexHeap[ 0 ] = indexHeap[ curCount - 1 ];//尾元素成为新堆顶
	    reverse[ indexHeap[ curCount - 1 ] ] = 0;
	    --curCount;
	    shiftDown( 0 );//开始向下调整
	    
	    return data[ minIndex ]; 	
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
	}

	void insert( Item number ) {
		//断言保证容量足够且保证下标不越界 
	    assert( curCount < capacity );
	    
	    data[ curCount ] = number;
	    indexHeap[ curCount ] = curCount;
	    reverse[ indexHeap[ curCount ] ] = curCount;
	    
		shiftUp( curCount );	    
	    ++curCount;
	}
	
	bool contain( int index ) {
		//确保用户指定的下标没有越界
		assert( index >= 0 && index < capacity ); 
		//检查此位置是否存在元素，包含返回真，不包含返回假 
		//cout << "reverse[ index ] " << reverse[ index ] << endl;
		return ( reverse[ index ] != -1 );
	}
	void change( int index, Item number ) {
			//cout << "change: " << index << endl;
			//cout << "contain( index ) " << contain( index ) << endl;
			assert( contain( index ) );
			data[ index ] = number;
			shiftUp( reverse[ index ] );			
			shiftDown( reverse[ index ] );			

		}
	void test() {
			cout << "test: ";
			for( int i = 0; i < 4; ++i )
				cout << data[ this->popMinIndex() ] << ' ';	
		}
	};
#endif