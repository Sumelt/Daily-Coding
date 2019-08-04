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

//构建双向链表的节点
template<typename V>
struct Node{
	Node* last;//前指针
	Node* next;//后指针
	V value;
	Node( int val ) {
		value = val;
		last = nullptr;
		next = nullptr;
	}
};

//双向链表类
template<typename V>
class DoubleLinkList {
private:
	Node<V> *head;//头指针
	Node<V> *tail;//尾指针
public:
	DoubleLinkList() {
		head = nullptr;
		tail = nullptr;
	}
	
	//加入一个节点，加入的位置是尾部，表示是当前活跃的节点
    void addNode( Node<V>* newNode ) {
		if( newNode == nullptr )
			return;
		
		//如果链表头为空，则头位置便是合适的位置
        if( this->head == nullptr ) {
			this->head = newNode;
			this->tail = newNode;
		}
        //插入链表尾部
		else {
			tail->next = newNode;
			newNode->last = tail;
			tail = newNode;	
		}
	}
    //把某个节点移动到尾部，表示为当前活跃的节点
	void moveNodeToTail( Node<V>* node ) {
		if( head == nullptr )
			return;
		//只有头节点
		if( head == node ) {
			head->last = nullptr;			
			head = head->next;
		}
        //目标节点前后维护
		else {
			node->last->next = node->next;
			if( node->next != nullptr )
				node->next->last = node->last;
		}
        //移动到链表尾部
		node->last = tail;
		node->next = nullptr;
		tail->next = node;
		tail = node;
	}
	//删除头节点，即是替换调一个页面
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

//对于节点到键的映射map，提供的存储函数
template<typename V>
struct cmp {
	bool operator() ( Node<V> a, Node<V> b ) {
		return a.value < b.value;
	}	
};

//缓存
template<typename K, typename V>
class Cache {
private:
	map<Node<V>, K, cmp<V>> *nodeToKeyMap;//节点到键的map
	map<K, Node<V>&> *keyToNodeMap;//键到节点的map
	DoubleLinkList<V> *nodeList;//双向链表
	int capacity;//缓存的容量
private:	
	//剔除不常用的页面
    void removeMostUnusedCache() {
		Node<V> *delNode = nodeList->removeHeadNode();//返回要删除的头节点指针
		if( delNode != nullptr ) {
			K delKey = ( *nodeToKeyMap )[ *delNode ];//得到键
			nodeToKeyMap->erase( *delNode );//在节点到key的map中删除元素
			keyToNodeMap->erase( delKey );//在key到节点的map中删除元素
		}	
	}

public:
	//构造器
    Cache( int size ) {
		nodeToKeyMap = new map<Node<V>, K, cmp<V>>();
		keyToNodeMap = new map<K, Node<V>&>();
		nodeList = new DoubleLinkList<V>();
		capacity = size;
	}
	//依据键获取值，表示活跃
	V *get( K key ) {
		auto iter = keyToNodeMap->find( key );//依据key找到node
		//成功找到
        if( iter != keyToNodeMap->end() ) {
			V *ptr = &( iter->second.value );
			nodeList->moveNodeToTail( &( iter->second ) );
			return ptr;
		}
		else return nullptr;
	}
	//设置
	void set( K key, V val ) {
		auto iter = keyToNodeMap->find( key );
		//已存在，则插入
        if( iter != keyToNodeMap->end() ) {
			iter->second.value = val;
			nodeList->moveNodeToTail( &( iter->second ) );
		}
        //不存在，则新建节点
		else {
			Node<V> *newNode = new Node<V>( val );//新建节点
			
            //nodeToKeyMap插入的是节点的副本
			nodeToKeyMap->insert( pair<Node<V>, K>( *newNode, key ) );
            //keyToNodeMap中插入的是节点的引用
			keyToNodeMap->insert( pair<K, Node<V>&>( key, *newNode ) );
			nodeList->addNode( newNode );
			
			//缓存容量不足，则移除头节点
            if( keyToNodeMap->size() > capacity )
				removeMostUnusedCache();
		}
	}	
};

int main(int argc, char *argv[])
{
	Cache<int, int>mycache( 3 );
	mycache.set( 1, 3 );
	mycache.set( 4, 2 );
	mycache.set( 5, 6 );
	mycache.set( 7, 8 );
	int *value = mycache.get( 7 );
	if( value != nullptr )
		cout << *value;
	else cout << "lost";
	return 0;
}