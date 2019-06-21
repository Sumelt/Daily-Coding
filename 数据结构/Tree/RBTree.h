#ifndef __RBTREE__H_
#define __RBTREE__H_

enum colors = { RED, BLACK };

template <typename Key, typename Value>
class RBTree {
private :
	struct Node {
		Key key;
		Value value;
		Node *left;
		Node *right;
		int color;		
		Node( Key k, Value v ) : 
			left( nullptr ), right( nullptr ), value( v ), key( k ), color( re )
			{}
		Node( Node *node ) : key( node->key ), value( node->value ), 
			left( node->left ), right( node->right ), height( 1 )
			{}
};

public :



};


#endif