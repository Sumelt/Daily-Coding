#ifndef __LOOPQUEUE_H__
#define __LOOPQUEUE_H__

#include <cassert>
template <typename T>
class LoopQueue {
private:
	int front;
	int tail;
	int size;
	int sumCapacity;
	T *array;
	void Resize( int newCapacity );
public:
	LoopQueue();
	LoopQueue( int capacity );
	~LoopQueue();
	bool IsEmpty();
	int Size();
	void Print();
	void Push( T element );
	void Pop();
	T Front();
	bool IsFull();
	int Capacity();
};

template <typename T>
LoopQueue<T>::LoopQueue( int capacity ) {
	sumCapacity = capacity;
	front = tail = size = 0;
	this->array = new T[ capacity + 1 ]();
}

template <typename T>
LoopQueue<T>::LoopQueue() {
	sumCapacity = 10;
	front = tail = size = 0;
	this->array = new T[ sumCapacity + 1 ]();
}

template <typename T>
LoopQueue<T>::~LoopQueue() {
	delete array;
}

template <typename T>
bool LoopQueue<T>::IsEmpty() {
	return size == 0;
}

template <typename T>
int LoopQueue<T>::Size() {
	return size;
}

template <typename T>
void LoopQueue<T>::Push( T element ) {
	if( IsFull() )
		Resize( sumCapacity * 2 );
	array[ tail ] = element;
	tail = ( tail + 1 ) % ( sumCapacity + 1 );
	++size;
} 

template <typename T>
void LoopQueue<T>::Pop() {
	assert( !IsEmpty() ); //保证不空
	
	front = ( front + 1 ) % ( sumCapacity + 1 );
	--size;	  
}

template <typename T>
T LoopQueue<T>::Front() {
	assert( !IsEmpty() ); //保证不空
	return array[ front ];
}

template <typename T>
bool LoopQueue<T>::IsFull() {
	return ( ( tail + 1 ) % sumCapacity ) == front;
}

template <typename T>
int LoopQueue<T>::Capacity() {
	return sumCapacity;
}

template <typename T>
void LoopQueue<T>::Print() {
	cout << "Array: size = " << size << ' ' 
			<< "capacity = " << sumCapacity << endl;
			
	cout << "[ ";
	for( int i = front; i != tail; i = ( i + 1 ) % sumCapacity ) {
		cout << array[ i ];
		if( i != tail - 1 )
			cout << ", ";
	}
	cout << " ]"	<< endl;	
}

template <typename T>
void LoopQueue<T>::Resize( int newCapacity ) {
	T *temp = new T[ newCapacity + 1 ]();	
	copy( array, array + sumCapacity, temp );
	sumCapacity = newCapacity;
	front = 0;
	tail = size;
	std::swap( temp, array );
	delete temp;
}


#endif