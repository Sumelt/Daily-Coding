#ifndef __RBTREE__H_
#define __RBTREE__H_

enum colors{ BLACK, RED };

template <typename Key, typename Value>
class RBTree {
private :
	struct Node {
		Key key;
		Value value;
		Node *left;
		Node *right;
		int color;	//颜色标注	
		Node( Key k, Value v ) : 
			left( nullptr ), right( nullptr ), value( v ), key( k ), color( RED )
			{}
		Node( Node *node ) : key( node->key ), value( node->value ), 
			left( node->left ), right( node->right ), color( RED )
			{}
	};
	
	Node* insert( Node *root, Key key, Value value );
	void destory( Node *root );
	Node* leftRotate( Node *root );
	Node* rightRotate( Node *root );
	Node* removeNode( Node *node, Key key );
	bool contain( Node *root, Key key );
	void flipColors( Node *node );

public :
	Node *root;
	int count; //节点个数 	
	RBTree();
	~RBTree();	
	void insert( Key key, Value value );
	int size();
	bool contain( Key key );
	bool isRed( Node* root );

};

template <typename Key, typename Value>
RBTree<Key, Value>::RBTree() {
	root = nullptr;	
	count = 0;
}

template <typename Key, typename Value>
RBTree<Key, Value>::~RBTree	() {
	destory( root );
}

template <typename Key, typename Value>
void RBTree<Key, Value>::destory( Node *root ) {
	if( root != nullptr ) {
		destory( root->left );
		destory( root->right );
		delete root;
		--count;
	}		
}

template <typename Key, typename Value>
bool RBTree<Key, Value>::contain( Key key ) {
	return contain( root, key );
}

template <typename Key, typename Value>
bool RBTree<Key, Value>::contain( Node *root, Key key ) {
	if( root == nullptr )
		return false;
	if( root->key == key )
		return true;
	else if( key > root->key )
		return contain( root->right, key );
	else return contain( root->left, key );	
}

template <typename Key, typename Value>
bool RBTree<Key, Value>::isRed( Node *root ) {
	if( root == nullptr )
		return false;
	return ( root->color == RED ? true : false );
}


template <typename Key, typename Value>
int RBTree<Key, Value>::size() {
	return count;
}


template <typename Key, typename Value>
void RBTree	<Key, Value>::insert( Key key, Value value ) {
	root = insert( root, key, value );//递归插入
	root->color = BLACK; //保持根节点为黑色 
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::Node*
RBTree<Key, Value>::insert( Node *root, Key key, Value value ) {
	if( root == nullptr ) {
		count += 1;
		return new Node( key, value );
	}
	if( root->key == key )
		root->value = value;
	else if( key > root->key )
		root->right = insert( root->right, key, value );
	else 
		root->left = insert( root->left, key, value );
		
	return root;
}


template <typename Key, typename Value>
typename RBTree<Key, Value>::Node* 
RBTree<Key, Value>::leftRotate( Node* root ) {
	Node* rightNode = root->right;
	Node* node = rightNode->left;
	
	rightNode->left = root;
	root->right = node;

	rightNode->color = root->color;
	root->color = RED;
	
	return rightNode;	
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::Node* 
RBTree<Key, Value>::rightRotate( Node *root ) {

	Node *leftNode = root->left;
	Node *node = leftNode->right;
	
	leftNode->right = root;
	root->left = node;
	
	leftNode->color = root->color;
	root->color = RED;
	
	return leftNode;

} 


template <typename Key, typename Value>
void RBTree	<Key, Value>::flipColors( Node *node ) {
	node->color = RED;
	node->left->color = BLACK;
	node->right->color = BLACK;
} 


#endif