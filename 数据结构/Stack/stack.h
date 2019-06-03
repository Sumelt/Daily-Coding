#ifndef __STACK_H__
#define __STACK_H__

#include "../Array/array.h"

template <typename T>
class Stack {
private:
	Array<T> *array;
public:
	Stack( int capacity );
	Stack();
	~Stack();
	
	T top();
	int getSize();
	void push( T element );
	void pop();
	bool isEmpty();
	void print();
};

template <typename T>
Stack<T>::Stack( int capacity ) {
	array = new Array<T>( capacity );
}

template <typename T>
Stack<T>::Stack() {
	array = new Array<T>();
}

template <typename T>
Stack<T>::~Stack() {
	delete array;
}

template <typename T>
int Stack<T>::getSize() {
	return array->getSize();
}

template <typename T>
bool Stack<T>::isEmpty() {
	return array->isEmpty();
}

template <typename T>
void Stack<T>::push( T element ) {
	array->push_back( element );
}

template <typename T>
void Stack<T>::pop( ) {
	array->remove_back();
}

template <typename T>
T Stack<T>::top( ) {
	array->get_back();
}

template <typename T>
void Stack<T>::print( ) {
	array->print();
}

#endif //__STACK_H__