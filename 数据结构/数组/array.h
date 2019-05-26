#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template <typename T>
class Array{
public:
	Array( int count ) {
		capacity = count;
		array = new T[ capacity ]();
		size = 0;
	}
	Array() {
		capacity = 10;
		array = new T[ capacity ]();
		size = 0;
	}
	~Array() {
		delete []array;
	}
	
	int getSize() {
		return size;
	}
	
	int getLength() {
		return capacity;
	}
	
	bool empty() {
		return size == 0;
	}
	
	void push_back( T element ) {
		push( size, element );
	}
	
	void push_front( T element ) {
		push( 0, element );
	}
	
	void push( int index, T element ) {
		if( size >= capacity )
			resize( capacity );
		assert( index >= 0 && index <= size );
		
		for( int i = size; i > index; --i )
			array[ i ] = array[ i - 1 ];
		array[ index ] = element;
		++size;
	}
	
	T get( int index ) {
		assert( index >= 0 && index < size );
		return array[ index ];
	}
	
	void set( int index, T element ) {
		assert( index >= 0 && index < size );
		array[ index ] = element;
	}
	
	bool contain( T element ) {
		for( int i = 0; i < size; ++i )
			if( array[ i ] == element )
				return true;
		return false;
	}
	
	int find( T element ) {
		for( int i = 0; i < size; ++i )
			if( array[ i ] == element )
				return i;
		return -1;		
	}
	
	int remove( int index ) {
		assert( index >= 0 && index < size );
		T value = array[ index ];
		for( int i = index; i < size; ++i )
			array[ i ] = array[ i + 1 ];
		array[ size - 1 ] = 0;
		--size;
		
		//缩容 
		if( size == ( getLength() / 4 ) )
			resize( capacity / 2 );
		return value;
	}
	
	int remove_front() {
		return remove( 0 );
	}
	
	int remove_back() {
		return remove( size - 1 );
	}
	
	void remove_element( T element ) {
		int index = find( element );
		assert( index >= 0 && index < size );
		remove( index );
	}
	
	void print() {
		cout << "Array: size = " << size << ' ' 
				<< "capacity = " << capacity << endl;
				
		cout << '[';
		for( int i = 0; i < size; ++i ) {
			cout << array[ i ];
			if( i != size - 1 )
				cout << ", ";
		}
		cout << ']'	<< endl;
	}

private:
	int capacity;
	T *array;
	int size;
	
	//扩容 
	void resize( int newCapacity ) {
		int oldCapacity = capacity;
		if( newCapacity > capacity ) {
			T *ptr = new T[ newCapacity ]();
			capacity = newCapacity;
			copy( array, array + oldCapacity, ptr );//拷贝旧元素 
			std::swap( array, ptr );			
		}
		else {
			capacity = newCapacity;
			size = oldCapacity / 4;
		} 
	}
};


#endif