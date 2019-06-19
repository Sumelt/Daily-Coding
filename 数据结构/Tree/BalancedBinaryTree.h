#ifndef __BALANCEBINARYTREE__H_ 
#define __BALANCEBINARYTREE__H_

#include <forward_list> 
using namespace std;

template <typename Key, typename Value>
class AVLTree{
private :
	struct Node{
		Key key;
		Value value;
		Node *left;
		Node *right;
		int height; //高度			
		Node( Key k, Value v ) : 
			left( nullptr ), right( nullptr ), value( v ), key( k ), height( 1 )
			{}
		Node( Node *node ) : key( node->key ), value( node->value ), 
			left( node->left ), right( node->right ), height( 1 )
			{}
};
	Node *root;
	int count; //节点个数 	
	bool contain( Node *root, Key key );
	bool isBlanced( Node *root );	
	void destory( Node *root );
	void inOrder( forward_list<Key>* list, Node* root );
	int getBalanceFactor( Node*root );
	Value *search( Node *root, Key key );
	Node* insert( Node *root, Key key, Value value );
	Node* rightRotate( Node *root );
	Node* leftRotate( Node *root );
	
		
public :
	AVLTree();
	~AVLTree();
	bool isEmpty();
	bool isBSTree();
	bool isBlanced();
	bool contain( Key key );	
	int size();
	int getHeight( Node* root );
	Value *search( Key key );
	void insert( Key key, Value value );
	
};

template <typename Key, typename Value>
AVLTree<Key, Value>::AVLTree() {
	root = nullptr;	
	count = 0;
}

template <typename Key, typename Value>
AVLTree<Key, Value>::~AVLTree() {
	destory( root );
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::destory( Node *root ) {
	if( root != nullptr ) {
		destory( root->left );
		destory( root->right );
		delete root;
		--count;
	}		
}

template <typename Key, typename Value>
bool AVLTree<Key, Value>::isEmpty() {
	return count == 0;
}

template <typename Key, typename Value>
int AVLTree<Key, Value>::size() {
	return count;
}

template <typename Key, typename Value>
bool AVLTree<Key, Value>::contain( Key key ) {
	return contain( root, key );
}

template <typename Key, typename Value>
bool AVLTree<Key, Value>::contain( Node *root, Key key ) {
	if( root == nullptr )
		return false;
	if( root->key == key )
		return true;
	else if( key > root->key )
		return contain( root->right, key );
	else return contain( root->left, key );	
}

template <typename Key, typename Value>
Value* AVLTree<Key, Value>::search( Key key ) {
	return search( root, key );
}

template <typename Key, typename Value>
Value* AVLTree<Key, Value>::search( Node *root, Key key ) {
	if( root == nullptr )
		return nullptr;
	if( root->key == key )
		return &( root->value );
	else if( key > root->key )
		return search( root->right, key );
	else 
		return search( root->left, key );
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::insert( Key key, Value value ) {
	root = insert( root, key, value );//递归插入 
}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Node* 
AVLTree<Key, Value>::insert( Node *root, Key key, Value value ) {
	if( root == nullptr ) {
		count += 1;
		return new Node( key, value );
	}
	if( root->key == key )//已经插入，则更新 
		root->value = value;
	else if( key > root->key )
		root->right = insert( root->right, key, value );
	else 
		root->left = insert( root->left, key, value );
	
	int balanceFactor = getBalanceFactor( root );
	
	//右旋 
	if( balanceFactor > 1 && getBalanceFactor( root->left ) > 0 )
		return rightRotate( root );
	
	//左旋	
	if( balanceFactor < -1 && getBalanceFactor( root->right ) < 0 )
		return leftRotate( root );		

	//LR
	if( balanceFactor > 1 && getBalanceFactor( root->left ) < 0 ) {
		root->left = leftRotate( root->left );
		return rightRotate( root );				
	}					

	//RL
	if( balanceFactor < -1 && getBalanceFactor( root->right ) > 0 ) {
		root->right = rightRotate( root->right );
		return leftRotate( root );	
	}
	
	return root;
}

template <typename Key, typename Value>
int AVLTree<Key, Value>::getBalanceFactor( Node* root )  {
	if( root == nullptr ) 
		return 0;
	else 
		return getHeight( root->left ) - getHeight( root->right );
} 

template <typename Key, typename Value>
int AVLTree<Key, Value>::getHeight( Node* root ) {
	if( root == nullptr )
		return 0;
	else return root->height;
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::inOrder( forward_list<Key>* list, Node* root ) {
	if( root == nullptr )
		return;
	inOrder( list, root->left );
	list->push_front( root->key );
	inOrder( list, root->right );
} 

template <typename Key, typename Value>
bool AVLTree<Key, Value>::isBSTree() {
	forward_list<Key>list;
	inOrder( &list, root );
	for( auto iter = list.begin(); iter != list.end(); ++iter ) {
		auto str = *iter++;
		if( str < *iter )
			return false;		
	}

	return true;
} 

template <typename Key, typename Value>
bool AVLTree<Key, Value>::isBlanced() {
	return isBlanced( root );
} 

template <typename Key, typename Value>
bool AVLTree<Key, Value>::isBlanced( Node *root ) {
	if( root == nullptr ) 
		return true;
	
	int balanceFactor = getBalanceFactor( root );
	if( balanceFactor > 1 )
		return false;
	return isBlanced( root->left ) && isBlanced( root->right );
} 

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Node* 
AVLTree<Key, Value>::rightRotate( Node* root ) {
	
	Node* rootLeft = root->left;
	Node* node = rootLeft->right;
	
	rootLeft->right = root;//成为新的根节点 
	root->left = node;
	
	//先更新原先的root高度
	root->height = 1 + 
		max( getHeight( root->left ), getHeight( root->right ) ); 
	//后更新新的rootleft
	rootLeft->height = 1 + 
		max( getHeight( rootLeft->left ), getHeight( rootLeft->right ) );

	return rootLeft;//返回新的根节点 
} 

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Node* 
AVLTree<Key, Value>::leftRotate( Node* root ) {
	Node* rootRight = root->right;
	Node* node = rootRight->left;
	
	rootRight->left = root;
	root->right = node;
	
	root->height = 1 + 
		max( getHeight( root->left ), getHeight( root->right ) );
	
	rootRight->height = 1 + 
		max( getHeight( rootRight->left ), getHeight( rootRight->right ) );
	
	return rootRight;	
}

#endif