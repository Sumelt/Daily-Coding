#ifndef __LOOPQUEUELIST__H_
#define __LOOPQUEUELIST__H_

#include <cassert>
using namespace std;

template<typename T>
class LoopQueueList {
private:
	class Node {
		friend class LoopQueueList<T>;
		T val;
		Node *next;
		public:
			Node( T element, Node* next ) {
				this->val = element;
				this->next = next;
			}
			Node( T element ) {
				this->val = element;
				this->next = nullptr;
			}
			Node() {
				this->val = T();
				this->next = nullptr;
			}		
	};
	Node *head;
	Node *tail;
	int size;

public:
	LoopQueueList() = default;
	~LoopQueueList();
	int Size();
	bool IsEmpty();
	void Push( T element );	
	T Front();
	void Print();	
	void Pop();	
};

template<typename T>
LoopQueueList<T>::~LoopQueueList() {
	Node *cur = head;
	Node *temp = nullptr;
	while( cur != nullptr ) {
		temp = cur;
		cur = cur->next;
		delete temp;
	}
	
}

template<typename T>
int LoopQueueList<T>::Size() {
	return size;
}

template<typename T>
bool LoopQueueList<T>::IsEmpty() {
	return size == 0;
}

template<typename T>
void LoopQueueList<T>::Push( T elemnet ) {
	if( IsEmpty() ) {
		head = new Node( elemnet );
		tail = head;
	}
	else {
		tail->next = new Node( elemnet );
		tail = tail->next;
	} 
	++size;
}

template<typename T>
void LoopQueueList<T>::Pop() {
	assert( !IsEmpty() );
	
	Node *temp = head;
	head = head->next;
	if( !head ) tail = head;
	--size;
	delete temp;
	
}

template<typename T>
T LoopQueueList<T>::Front() {
	assert( !IsEmpty() );
	return head->val;
}

template<typename T>
void LoopQueueList<T>::Print() {
	Node *cur = head;	
	for( int i = 0; i < size; ++i ) {
		cout << cur->val << " -> ";
		cur = cur->next;
	}
	cout << "nullptr"	<< endl;	
}

#endif