#ifndef __MAPLINKLIST__H_
#define __MAPLINKLIST__H_
#include <exception>      // std::exception
template<typename K, typename V>
class MapLinkList {
private:
	class Node {
		friend class MapLinkList<K, V>;
		K key;
		V val;
		Node *next;
		public:
			Node( K key, V val, Node* next ) {
				this->key= key;
				this->val = val;
				this->next = next;
			}
			Node( K key, V val ) {
				this->key= key;
				this->val = val;
				this->next = nullptr;
			}
			Node() {
				this->key = K();
				this->val= V();
				this->next = nullptr;
			}
		};
		
	Node* getNode( K key );
		
	Node *dummyHead;
	int size;
	
public:
	MapLinkList();
	~MapLinkList();
	void add( K key, V val );
	void remove( K key );
	bool isEmpty();
	bool contain( K key );
	int getSize();
	V get( K key );
	void set( K key, V val );
};

template<typename K, typename V>
MapLinkList<K, V>::MapLinkList() {
	dummyHead = new Node();
	size = 0;		
}

template<typename K, typename V>
MapLinkList<K, V>::~MapLinkList() {
	Node *cur = dummyHead;
	Node *temp = nullptr;
	while( cur != nullptr ) {
		temp = cur;
		cur = cur->next;
		delete temp;
	}	
}

template<typename K, typename V>
int MapLinkList<K, V>::getSize() {
	return size;
}

template<typename K, typename V>
bool MapLinkList<K, V>::isEmpty() {
	return size == 0;
}

template<typename K, typename V>
typename MapLinkList<K, V>::Node* MapLinkList<K, V>::getNode( K key ) {
	Node *cur = dummyHead->next;
	
	while( cur != nullptr ) {
		if( cur->key == key )
			return cur;
		cur = cur->next;
	}
	return nullptr;
}

template<typename K, typename V>
bool MapLinkList<K, V>::contain( K key ) {
	return ( getNode( key )	!= nullptr ? true : false );
}

template<typename K, typename V>
V MapLinkList<K, V>::get( K key ) {
	Node *node = getNode( key );
	return ( node != nullptr ? node->val : 0  );
}
 
template<typename K, typename V>
void MapLinkList<K, V>::remove( K key ) {
	Node *pre = dummyHead;
	
	while( pre->next != nullptr && pre->next->key != key )
		pre = pre->next;
	if( pre->next != nullptr && pre->next->key == key ) {
		Node *delNode = pre->next;
		pre->next = delNode->next;
		delete delNode;
		--size;
	}	
}


template<typename K, typename V>
void MapLinkList<K, V>::add( K key, V val ) {
	Node *node = getNode( key );
	if( !node ) {
		dummyHead->next = new Node( key, val, dummyHead->next );
		++size;		
	}
	else{
		node->val += 1;
	} 
}

template<typename K, typename V>
void MapLinkList<K, V>::set( K key, V val ) {
	Node *node = getNode( key );
	if( node )
		node->val = val;
	else throw ( std::exception() );
}




#endif