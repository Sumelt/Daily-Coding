#ifndef __LINKLIST__H_
#define __LINKLIST__H_

using namespace std;

template<typename T>
class List {
private:
	class Node {
		friend class List<T>;
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
	Node *dummyHead;
	int size;
		
public:
	List();
	~List();
	int Size();
	bool IsEmpty();
	void InsertFront( T element );
	void InsertBack( T element );
	void Insert( T element, int index );
	T Get( int index );
	T GetBack();
	T GetFront();
	void Set( T element, int index );
	bool Contain( T element );
	int Find( T element );
	void Print();
	T remove( int index );
	T removeFront();
	T removeBack();
		
};

template<typename T>
List<T>::List() {
	dummyHead = new Node();
	size = 0;	
}

template<typename T>
List<T>::~List() {
	Node *cur = dummyHead;
	Node *temp = nullptr;
	while( cur != nullptr ) {
		temp = cur;
		cur = cur->next;
		delete temp;
	}
}

template<typename T>
bool List<T>::IsEmpty() {
	return size == 0;
}

template<typename T>
int List<T>::Size() {
	return size;
}

template<typename T>
void List<T>::InsertFront( T element ) {
	Insert( element, 0 );
}

template<typename T>
void List<T>::InsertBack( T element ) {
	Insert( element, size );
}

template<typename T>
void List<T>::Insert( T element, int index ) {
	assert( index >= 0 && index <= size );
	Node *node = dummyHead;
	for( int i = 0; i < index; ++i )
		node = node->next;
	node->next = new Node( element, node->next );
	++size;
}

template<typename T>
T List<T>::Get( int index ) {
	assert( index >= 0 && index <= size );
	Node *cur =  dummyHead->next;
	
	for( int i = 0; i < index; ++i )
		cur = cur->next;		
	return cur->val;
	
}

template<typename T>
T List<T>::GetFront() {
	return Get( 0 );
}

template<typename T>
T List<T>::GetBack() {
	
	return Get( size - 1 );
}

template<typename T>
void List<T>::Set( T element, int index ) {
	assert( index >= 0 && index < size );
	Node *cur = dummyHead->next;
	for( int i = 0; i < index; ++i )
		cur = cur->next;
	cur->val = element;
}

template<typename T>
int List<T>::Find( T element ) {
	Node *cur = dummyHead->next;
	
	for( int i = 0; i < size; ++i ) {
		if( cur->val == element )
			return i;
		cur = cur->next;
	}
	
	return -1;
}

template<typename T>
bool List<T>::Contain( T element ) {
	return ( Find( element ) != -1 ? true : false );
}

template<typename T>
T List<T>::remove( int index ) {
	assert( index >= 0 && index < size );
	Node *pre = dummyHead;
	Node *after = nullptr;
	
	for( int i = 0; i < index; ++i ) {
		pre = pre->next;
	}
	
	after = pre->next;
	T ret = after->val;	
	pre->next = after->next;
	--size;
	return ret;
}

template<typename T>
T List<T>::removeBack() {
	return remove( size - 1 );
}

template<typename T>
T List<T>::removeFront() {
	return remove( 0 );
}

template<typename T>
void List<T>::Print() {	
	Node *cur = dummyHead->next;	
	for( int i = 0; i < size; ++i ) {
		cout << cur->val << " -> ";
		cur = cur->next;
	}
	cout << "nullptr"	<< endl;	
}


#endif