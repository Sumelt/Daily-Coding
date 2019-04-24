/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <cassert>
#include "../random_number.h"
using namespace std;

namespace maxIndexHeapSpace{
class maxIndexHeap{
private:
	int *data = nullptr;
	int *indexAry = nullptr;

	int capacity = 0;
	int curCount = 0;
	void shiftDown( int index ) {
		int tempValue = data[ indexAry[ index ] ];//暂存元素值 
		int tempIndex = indexAry[ index ];//暂存要调整元素的下标 
		while( 2 * index <= curCount ) {
			int leftIndex = 2 * index;
			if( leftIndex + 1 <= curCount && 
				data[ indexAry[ leftIndex + 1 ] ] > data[ indexAry[ leftIndex ] ] )
					++leftIndex;
			if( tempValue >= data[ indexAry[ leftIndex ] ] )
				break;
			else
				indexAry[ index ] = indexAry[ leftIndex ];
			index = leftIndex;
		}
		indexAry[ index ] = tempIndex;//更新 		
	}
		
	void shiftUp( int index ) {
		
		int tempValue = data[ indexAry[ index ] ];//暂存当前的要调整的元素值
		int tempIndex = indexAry[ index ];//暂存要调整元素的下标 
		while( index > 1 && tempValue > data[ indexAry[ index / 2 ] ] ) {//从索引中获得父节点的元素值 
			indexAry[ index ] = indexAry[ index / 2 ];//父节点的元素值下标 下来		
			index /= 2;
		}
		indexAry[ index ] = tempIndex;//更新正确的元素下标
	}
public:
	maxIndexHeap( int length ) {
	
		capacity = length;	
		data = new int[ length + 1 ]();
		indexAry = new int[ length + 1 ]();
	}
	//heapify
	maxIndexHeap( int *array, int length ) {
		
		capacity = length;
		curCount = length;
		data = new int[ length + 1 ]();
		indexAry = new int[ length + 1 ]();
		
		for( int i = 1; i <= length; ++i )
			indexAry[ i ] = i;
					
		copy( array, array + length, data + 1 );//拷贝用户数组元素 
		
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
	int popMaxIndex() {
	    int maxIndex = indexAry[ 1 ];//保存堆顶元素
	    indexAry[ 1 ] = indexAry[ curCount ];//尾元素成为新堆顶
	    --curCount;
	    shiftDown( 1 );//开始向下调整
	    
	    return maxIndex - 1; //还原成用户需要的数组下标，即是从0开始 
	}
	//往指定的下标插入元素 
	void insert( int index, int number ) {
			
	    assert( index + 1 > 0 && index + 1 <= capacity&& curCount <= capacity );//断言保证容量足够且保证下标不越界 
	    assert( !contain( index ) );
	    
	    ++index;//用户传入的是从0开始的元素，而我们实现的是元素从1开始存储 
		data[ index ] = number;//保存元素 
	    indexAry[ curCount + 1 ] = index;//索引数组保存元素的下标 
	    
	    shiftUp( curCount + 1 ); //调整索引 
	    ++curCount;
	}
	
	bool contain( int index ) {
		
		assert( index + 1 > 0 && index + 1 <= capacity );//确保用户指定的下标没有越界 
		//return ( reverse[ index + 1 ] != 0 );//检查此位置是否存在元素 
	}

	~maxIndexHeap() {
			delete []data;
			delete []indexAry;
		}
	};
	
//测试索引堆产生的从大到小排列 
	void sort( int *ary, int size ){
		using namespace maxIndexHeapSpace;
		maxIndexHeap object = maxIndexHeap( ary, size );
		
		for( int i = 0; i < size; ++i )
			cout << ary[ object.popMaxIndex() ] << ends;
			
	}		
}

//增加了修改元素的函数 ，其余功能都一样 
namespace maxIndexHeapSpace2 {
	class maxIndexHeap{
private:
	int *data = nullptr;
	int *indexAry = nullptr;
	int *reverse = nullptr;

	int capacity = 0;
	int curCount = 0;
	void shiftDown( int index ) {
		int tempValue = data[ indexAry[ index ] ];//暂存元素值 
		int tempIndex = indexAry[ index ];//暂存要调整元素的下标 
		while( 2 * index <= curCount ) {
			int leftIndex = 2 * index;
			if( leftIndex + 1 <= curCount && 
				data[ indexAry[ leftIndex + 1 ] ] > data[ indexAry[ leftIndex ] ] )
					++leftIndex;
			if( tempValue >= data[ indexAry[ leftIndex ] ] )
				break;
			else {
				indexAry[ index ] = indexAry[ leftIndex ];
				reverse[ indexAry[ index ] ] = index;
			}				
			index = leftIndex;
		}
		indexAry[ index ] = tempIndex;//更新
		reverse[ indexAry[ index ] ] = index;
	}
		
	void shiftUp( int index ) {
		
		int tempValue = data[ indexAry[ index ] ];//暂存当前的要调整的元素值
		int tempIndex = indexAry[ index ];//暂存要调整元素的下标 
		while( index > 1 && tempValue > data[ indexAry[ index / 2 ] ] ) {//从索引中获得父节点的元素值 
			indexAry[ index ] = indexAry[ index / 2 ];//父节点的元素值下标 下来
			reverse[ indexAry[ index ] ] = index;
			index /= 2;
		}
		indexAry[ index ] = tempIndex;//更新正确的元素下标
		reverse[ indexAry[ index ] ] = index;
	}
public:
	maxIndexHeap( int length ) {
	
		capacity = length;	
		data = new int[ length + 1 ]();
		indexAry = new int[ length + 1 ]();
	}
	//heapify
	maxIndexHeap( int *array, int length ) {
		
		capacity = length;
		curCount = length;
		data = new int[ length + 1 ]();
		indexAry = new int[ length + 1 ]();
		reverse = new int[ length + 1 ]();
		
		for( int i = 1; i <= length; ++i ) {
			indexAry[ i ] = i;
			reverse[ i ] = i;
		}
							
		copy( array, array + length, data + 1 );//拷贝用户数组元素 
		
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
	int popMaxIndex() {
	    int maxIndex = indexAry[ 1 ];//保存堆顶元素
	    indexAry[ 1 ] = indexAry[ curCount ];//尾元素成为新堆顶
	    --curCount;
	    shiftDown( 1 );//开始向下调整
	    
	    return maxIndex; //还原成用户需要的数组下标，即是从0开始 
	}
	//往指定的下标插入元素 
	void insert( int index, int number ) {
			
	    assert( index + 1 > 0 && index + 1 <= capacity&& curCount <= capacity );//断言保证容量足够且保证下标不越界 
	    assert( !contain( index ) );
	    
	    ++index;//用户传入的是从0开始的元素，而我们实现的是元素从1开始存储 
		data[ index ] = number;//保存元素 
	    indexAry[ curCount + 1 ] = index;//索引数组保存元素的下标 
	    
	    shiftUp( curCount + 1 ); //调整索引 
	    ++curCount;
	}
	
	bool contain( int index ) {
		
		assert( index + 1 > 0 && index + 1 <= capacity );//确保用户指定的下标没有越界 
		return ( reverse[ index + 1 ] != 0 );//检查此位置是否存在元素 
	}

	void change( int index, int number, int size ) {
			
		assert( contain( index + 1 ) );
		data[ index + 1 ] = number;
		shiftUp( reverse[ index + 1 ] );
		shiftDown( reverse[ index + 1 ] );
		
		for( int i = 1; i <= size; ++i )
			cout << data[ popMaxIndex() ] << ends;
		
	}

	~maxIndexHeap() {
			delete []data;
			delete []indexAry;
			delete []reverse;
		}
	};
	
//测试索引堆产生的从大到小排列 
	void sort( int *ary, int size ){
		using namespace maxIndexHeapSpace;
		maxIndexHeap object = maxIndexHeap( ary, size );
		
		object.change( 40, 500, size );
			
	}
}

int main(int argc, char *argv[])
{
	using namespace maxIndexHeapSpace;
	int length = 10;
	int *data = Generate_random_numbers( 20, 600, length );
	
	sort( data, length );
	
	return 0;
}