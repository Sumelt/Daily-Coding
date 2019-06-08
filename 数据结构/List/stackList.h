#ifndef __STACKLIST__H_ 
#define __STACKLIST__H_

#include "./linkList.h"

template <typename T>
class StackList {
private:
	List<T>	*list;

public:
	StackList();
	~StackList();
	T Top();
	int Size();
	void Push( T element );
	void Pop();
	bool IsEmpty();
	void Print();	
};

template <typename T>
StackList<T>::StackList() {
	this->list = new List<T>();
}

template <typename T>
StackList<T>::~StackList() {
	this->list->~List();
	delete list;
}

template <typename T>
T StackList<T>::Top() {
	return this->list->Get( 0 );
}

template <typename T>
int StackList<T>::Size() {
	return this->list->Size();
}

template <typename T>
void StackList<T>::Push( T element ) {
	this->list->InsertFront( element );
}

template <typename T>
void StackList<T>::Pop() {
	this->list->removeFront();
}

template <typename T>
bool StackList<T>::IsEmpty() {
	return this->list->IsEmpty();
}

template <typename T>
void StackList<T>::Print() {
	cout << "top: ";
	this->list->Print();
}

#endif