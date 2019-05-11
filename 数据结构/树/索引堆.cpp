/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <cassert>
#include "../random_number.h"
using namespace std;

//数据存储从1开始,这里不是泛型写法注意数据转型 
namespace maxIndexHeapSpace{
class maxIndexHeap{
private:
	int *data = nullptr;
	int *indexHeap = nullptr;

	int capacity = 0;
	int curCount = 0;
	void shiftDown( int index ) {
		int tempValue = data[ indexHeap[ index ] ];//暂存元素值 
		int tempIndex = indexHeap[ index ];//暂存要调整元素的下标 
		while( 2 * index <= curCount ) {
			int leftIndex = 2 * index;
			if( leftIndex + 1 <= curCount && 
				data[ indexHeap[ leftIndex + 1 ] ] > data[ indexHeap[ leftIndex ] ] )
					++leftIndex;
			if( tempValue >= data[ indexHeap[ leftIndex ] ] )
				break;
			else
				indexHeap[ index ] = indexHeap[ leftIndex ];
			index = leftIndex;
		}
		indexHeap[ index ] = tempIndex;//更新 		
	}
		
	void shiftUp( int index ) {
		
		int tempValue = data[ indexHeap[ index ] ];//暂存当前的要调整的元素值
		int tempIndex = indexHeap[ index ];//暂存要调整元素的下标 
		while( index > 1 && tempValue > data[ indexHeap[ index / 2 ] ] ) {//从索引中获得父节点的元素值 
			indexHeap[ index ] = indexHeap[ index / 2 ];//父节点的元素值下标 下来		
			index /= 2;
		}
		indexHeap[ index ] = tempIndex;//更新正确的元素下标
	}
public:
	maxIndexHeap( int length ) {
	
		capacity = length;	
		data = new int[ length + 1 ]();
		indexHeap = new int[ length + 1 ]();
	}
	//heapify
	maxIndexHeap( int *array, int length ) {
		
		capacity = length;
		curCount = length;
		data = new int[ length + 1 ]();
		indexHeap = new int[ length + 1 ]();
		
		for( int i = 1; i <= length; ++i )
			indexHeap[ i ] = i;
					
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
	    int maxIndex = indexHeap[ 1 ];//保存堆顶元素
	    indexHeap[ 1 ] = indexHeap[ curCount ];//尾元素成为新堆顶
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
	    indexHeap[ curCount + 1 ] = index;//索引数组保存元素的下标 
	    
	    shiftUp( curCount + 1 ); //调整索引 
	    ++curCount;
	}
	
	bool contain( int index ) {
		
		assert( index + 1 > 0 && index + 1 < capacity );//确保用户指定的下标没有越界 
		//return ( reverse[ index + 1 ] != 0 );//检查此位置是否存在元素 
	}

	~maxIndexHeap() {
			delete []data;
			delete []indexHeap;
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
class maxIndexHeap {
private:
	int *data = nullptr;
	int *indexHeap = nullptr;
	int *reverse = nullptr;

	int capacity = 0;
	int curCount = 0;
	void shiftDown( int index ) {
		int tempValue = data[ indexHeap[ index ] ];//暂存元素值 
		int tempIndex = indexHeap[ index ];//暂存要调整元素的下标 
		while( 2 * index <= curCount ) {
			int leftIndex = 2 * index;
			if( leftIndex + 1 <= curCount && 
				data[ indexHeap[ leftIndex + 1 ] ] > data[ indexHeap[ leftIndex ] ] )
					++leftIndex;
			if( tempValue >= data[ indexHeap[ leftIndex ] ] )
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
		
		int tempValue = data[ indexHeap[ index ] ];//暂存当前的要调整的元素值
		int tempIndex = indexHeap[ index ];//暂存要调整元素的下标 
		while( index > 1 && tempValue > data[ indexHeap[ index / 2 ] ] ) {//从索引中获得父节点的元素值 
			indexHeap[ index ] = indexHeap[ index / 2 ];//父节点的元素值下标 下来
			reverse[ indexHeap[ index ] ] = index;
			index /= 2;
		}
		indexHeap[ index ] = tempIndex;//更新正确的元素下标
		reverse[ indexHeap[ index ] ] = index;
	}
public:
	maxIndexHeap( int length ) {
	
		capacity = length;	
		data = new int[ length + 1 ]();
		indexHeap = new int[ length + 1 ]();
		reverse = new int[ length + 1 ]();
	}
	//heapify
	maxIndexHeap( int *array, int length ) {
		
		capacity = length;
		curCount = length;
		data = new int[ length + 1 ]();
		indexHeap = new int[ length + 1 ]();
		reverse = new int[ length + 1 ]();
		
		for( int i = 1; i <= length; ++i ) {
			indexHeap[ i ] = i;
			reverse[ i ] = i;
		}
		//拷贝用户数组元素作为类操作的数据副本					
		copy( array, array + length, data + 1 );
		
		for( int i = curCount / 2; i >= 1; --i )
			shiftDown( i );
	}
	
	~maxIndexHeap() {
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
	//删除堆顶元素
	int popMaxIndex() {
	    int maxIndex = indexHeap[ 1 ];//保存堆顶元素
	    indexHeap[ 1 ] = indexHeap[ curCount ];//尾元素成为新堆顶
	    reverse[ indexHeap[ curCount ] ] = 1;
	    --curCount;
	    shiftDown( 1 );//开始向下调整
	    
	    return maxIndex; //还原成用户需要的数组下标，即是从0开始 
	}
	//往指定的下标插入元素 
	void insert( int index, int number ) {
			
	    assert( index + 1 > 0 && index + 1 <= capacity&& curCount < capacity );//断言保证容量足够且保证下标不越界 
	    assert( !contain( index ) );
	    
	    ++index;//用户传入的是从0开始的元素，而我们实现的是元素从1开始存储 
		data[ index ] = number;//保存元素 
	    indexHeap[ curCount + 1 ] = index;//索引数组保存元素的下标 
	    reverse[ indexHeap[ curCount + 1 ] ] = curCount + 1;
	    shiftUp( curCount + 1 ); //调整索引 
	    ++curCount;
	}
	
	bool contain( int index ) {		
		assert( index + 1 > 0 && index + 1 <= capacity );//确保用户指定的下标没有越界 
		return ( reverse[ index + 1 ] != 0 );//检查此位置是否存在元素 
	}
	
	 // 将最大索引堆中索引为i的元素修改为newItem	 
	//未优化版本 
    void changeNoOptional( int i, int newItem ){
        i += 1;
        data[i] = newItem;

        // 找到indexes[j] = i, j表示data[i]在堆中的位置
        // 之后shiftUp(j), 再shiftDown(j)
    	for( int j = 1 ; j <= curCount ; j ++ )
	        if( indexHeap[j] == i ) { //需不断迭代找到要调整的下标 
	            shiftUp(j);
	            shiftDown(j);
	            return;
        	}
    }
    //优化版本 
	void change( int index, int number ) {
			
			assert( contain( index + 1 ) );
			data[ index + 1 ] = number;
			shiftUp( reverse[ index + 1 ] );
			shiftDown( reverse[ index + 1 ] );
			
			//测试 
			for( int i = 0; i < 10; ++i )
				cout << data[ this->popMaxIndex() ] << ' ';	
		}	
	};
}

int main(int argc, char *argv[])
{
	using namespace maxIndexHeapSpace2;
	int length = 10;
	int *data = Generate_random_numbers( 20, 600, length );
	for( int i = 0; i < length; ++i )
		cout << data[ i ] << ' ';
	cout << endl;
	maxIndexHeap maxHeap( length );
	for( int i = 0; i < length; ++i )
	 maxHeap.insert( i, data[ i ] );
 	
	maxHeap.change( 4, 460 );
	
	
	return 0;
}