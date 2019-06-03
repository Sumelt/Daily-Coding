#ifndef __QUEUE__H_
#define __QUEUE__H_

#include "../Array/array.h"

template <typename T>
class Queue
{
private:
	Array<T> *que;
public:
	Queue();
	Queue( int );
	~Queue();
	void push( T element );
	T front();
	int getSize();
	bool isEmpty();
	void pop();
	void print();

};

template <typename T>
Queue<T>::Queue() {
	que = new Array<T>();
}

template <typename T>
Queue<T>::Queue( int capacity ) {
	que = new Array<T>[ capacity ]();
}

template <typename T>
Queue<T>::~Queue() {
	delete que;
}

template <typename T>
void Queue<T>::push( T element ) {
	que->push_back( element );
}

template <typename T>
T Queue<T>::front() {
	return que->get( 0 );
}

template <typename T>
int Queue<T>::getSize() {
	return que->getSize();
}

template <typename T>
bool Queue<T>::isEmpty() {
	return que->isEmpty();
}

template <typename T>
void Queue<T>::pop() {
	que->remove_front();
}

template <typename T>
void Queue<T>::print() {
	que->print();
}

#endif //__QUEUE__H_