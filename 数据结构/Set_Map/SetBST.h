#ifndef __SETBST__H_
#define __SETBST__H_

#include "../Find/BinarySearchTree.h"
using namespace BSTversion2;

template <typename Key, typename Value>
class SetBST : public BST<Key, Value>{
private :
	BST<Key, Value> *bst;
public :
	SetBST();
	~SetBST();
	void add( Key element );
	void remove( Key element );
	bool contain( Key element );
	int size();
	bool isEmpty();
};

template <typename Key, typename Value>
SetBST<Key, Value>::SetBST() {
	bst = new BST<Key, Value>();
}

template <typename Key, typename Value>
SetBST<Key, Value>::~SetBST() {
	bst->~BST();
	cout << "delete ok" << endl;
}

template <typename Key, typename Value>
void SetBST<Key, Value>::add( Key element ) {
	int *res = bst->search( element );
	if( res == nullptr )
		bst->insert( element, 1 );
	else ++( *res );	
}

template <typename Key, typename Value>
void SetBST<Key, Value>::remove( Key element ) {
	bst->removeNode( element );
}

template <typename Key, typename Value>
bool SetBST<Key, Value>::contain( Key element ) {
	return bst->contain( element );
	
}

template <typename Key, typename Value>
bool SetBST<Key, Value>::isEmpty() {
	return bst->isEmpty();
}

template <typename Key, typename Value>
int SetBST<Key, Value>::size() {
	return bst->size();
}

#endif