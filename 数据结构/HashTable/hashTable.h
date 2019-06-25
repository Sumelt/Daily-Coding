#ifndef __HASHTABLE__H_
#define __HASHTABLE__H_

#include <map>

template<typename K, typename V>
class HashTable {

private:
	int capacity[ 50 ] = { 53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593,\
		49157, 98317, 196613, 393241, 786433, 1572869, 3145739, 6291469,\
			12582917, 25165843, 50331653, 100663319, 201326611, 402653189,\
				805306457, 1610612741 };
			
	std::map<K, V> *hashtable;//每一个元素都是红黑树，自然解决哈希冲突 
	int M; //取余
	int size;
	static int upperTol;
	static int lowerTol;
	int indexCapacity = 0;
	int hashCode( K key );
	void resize( int sz );

public:
//	HashTable( int size );
	HashTable();
	~HashTable();
	void Push( K key, V value );
	int Size();
	void Remove( K key );
	bool Contain( K key );
	V Get( K key );
	void Set( K key, V value );
		
};

template<typename K, typename V>
int HashTable<K, V>::upperTol = 10;

template<typename K, typename V>
int HashTable<K, V>::lowerTol = 2;

//template<typename K, typename V>
//HashTable<K, V>::HashTable( int m ) {
//	this->M = m;
//	size = 0;
//	hashtable = new std::map<K, V>[ M ]();	
//} 

template<typename K, typename V>
HashTable<K, V>::HashTable() {
	this->M = capacity[ indexCapacity ];
	size = 0;
	hashtable = new std::map<K, V>[ M ]();
}


template<typename K, typename V>
HashTable<K, V>::~HashTable() {
	delete []hashtable;
} 

template<typename K, typename V>
HashTable<K, V>::hashCode( K key ) {

	std::hash<K>hashObject;
	return ( hashObject( key ) & 0x7fffffff ) % M;
} 

template<typename K, typename V>
HashTable<K, V>::Size() {
	return size;
}

template<typename K, typename V>
void HashTable<K, V>::Push( K key, V value ) {
	int code = hashCode( key );
	if( hashtable[ code ].find( key ) == hashtable[ code ].end() ) {
		hashtable[ code ][ key ] = value;
		++size;	
		if( size >= upperTol * M && 
				indexCapacity + 1 < ( sizeof( capacity )/ *capacity ) )//扩容 
			resize( capacity[ ++indexCapacity ] );
	}
	else hashtable[ code ][ key ] = value;
}

template<typename K, typename V>
void HashTable<K, V>::Remove( K key ) {
	int code = hashCode( key );
	
	if( hashtable[ code ].find( key ) != hashtable[ code ].end ) {
		hashtable[ code ].erase( key );
		--size;
		if( size < lowerTol * M && indexCapacity - 1 >= 0 )//缩容 
			resize( capacity[ --indexCapacity ] );
	}
	else return;
}

template<typename K, typename V>
bool HashTable<K, V>::Contain( K key ) {
	int code = hashCode( key );
	return ( hashtable[ code ].find( key ) != hashtable[ code ].end() ? 
		true : false );
}

template<typename K, typename V>
void HashTable<K, V>::Set( K key, V value ) {
	int code = hashCode( key );
	if( !Contain( key ) )
		throw std::exception();
	else hashtable[ code ][ key ] = value;
}

template<typename K, typename V>
V HashTable<K, V>::Get( K key ) {
	int code = hashCode( key );
	if( !Contain( key ) )
		throw std::exception();
	return hashtable[ code ][ key ];
}

template<typename K, typename V>
void HashTable<K, V>::resize( int sz ) {

	int oldM = M;
	this->M = sz;
	std::map<K, V>*newHashTable = new std::map<K, V>[ sz ]();

	for( int i = 0; i < oldM; ++i ) {
		std::map<K, V>mp = hashtable[ i ];
		for( auto iter = mp.begin(); iter != mp.end(); ++iter )
			newHashTable[ hashCode( iter->first ) ][ iter->first ] = iter->second;
	}
	swap( this->hashtable, newHashTable );
}

#endif