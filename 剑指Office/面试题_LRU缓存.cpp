/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>
#include <map>
using namespace std;

template<typename V>
struct Node{
	Node* last;
	Node* next;
	V value;
	Node( int val ) {
		value = val;
		last = nullptr;
		next = nullptr;
	}
};

template<typename V>
class DoubleLinkList {
private:
	Node<V> *head;
	Node<V> *tail;
public:
	DoubleLinkList() {
		head = nullptr;
		tail = nullptr;
	}
	
	void addNode( Node<V>* newNode ) {
		if( newNode == nullptr )
			return;
		
		if( this->head == nullptr ) {
			this->head = newNode;
			this->tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->last = tail;
			tail = newNode;	
		}
	}
	void moveNodeToTail( Node<V>* node ) {
		if( head == nullptr )
			return;
		
		if( head == node ) {
			head = head->next;
			head->last = nullptr;
		}
		else {
			node->last->next = node->next;
			node->next->last = node->last;
		}
		node->last = tail;
		node->next = nullptr;
		tail->next = node;
		tail = node;
	}
	
	Node<V>* removeHeadNode() {
		if( head == nullptr )
			return nullptr;
		
		Node<V>* retNode = head;
		if( head == tail ) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = head->next;
			head->last = nullptr;
			retNode->next = nullptr;			
		}
		return retNode;
	}
};

template<typename V>
struct cmp {
	bool operator() ( Node<V> a, Node<V> b ) {
		return a.value < b.value;
	}	
};

template<typename K, typename V>
class Cache {
private:
	map<Node<V>, K, cmp<V>> *nodeToKeyMap;
	map<K, Node<V>> *keyToNodeMap;
	DoubleLinkList<V> *nodeList;
	int capacity;
public:	
	void removeMostUnusedCache() {
		Node<V> *delNode = nodeList->removeHeadNode();
		if( delNode != nullptr ) {
			K delKey = ( *nodeToKeyMap )[ *delNode ];
			nodeToKeyMap->erase( *delNode );
			keyToNodeMap->erase( delKey );			
		}	
	}

public:
	Cache( int size ) {
		nodeToKeyMap = new map<Node<V>, K, cmp<V>>();
		keyToNodeMap = new map<K, Node<V>>();
		nodeList = new DoubleLinkList<V>();
		capacity = size;
	}
	
	V *get( K key ) {
		auto iter = keyToNodeMap->find( key );
		if( iter != keyToNodeMap->end() ) {
			V *ptr = &( iter->second.value );
			nodeList->moveNodeToTail( &( iter->second ) );
			return ptr;
		}
		else return nullptr;
	}
	
	void set( K key, V val ) {
		auto iter = keyToNodeMap->find( key );
		if( iter != keyToNodeMap->end() ) {
			iter->second.value = val;
			nodeList->moveNodeToTail( &( iter->second ) );
		}
		else {
			Node<V> *newNode = new Node<V>( val );
			( *nodeToKeyMap )[ *newNode ] = key;
			( *keyToNodeMap )[ key ] = *newNode;
			nodeList->addNode( newNode );
			if( keyToNodeMap->size() > capacity )
				removeMostUnusedCache();
		}
	}
	
};

int main(int argc, char *argv[])
{
	Cache<int, int>mycache( 3 );
	mycache.set( 1, 3 );
	return 0;
}