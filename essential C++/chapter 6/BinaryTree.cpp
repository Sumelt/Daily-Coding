/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;

template<typename valType>
class BTnode;
template<typename elemType> 
class BinaryTree;

/*-------------------class BinaryTree---------------------------------*/
template<typename elemType> 
class BinaryTree{
	public:
		//friend class BTnode<elemType>;
		BinaryTree();
		BinaryTree( const BinaryTree& );
		~BinaryTree();
		BinaryTree& operator=( const BinaryTree& );
		void insert( const elemType& );
		void remove( const elemType& );
		void remove_root();
			
		bool empty() { return _root == 0;}
		void clear();
		
	private:
		BTnode<elemType> *_root;
		void copy( BTnode<elemType> *tar, BTnode<elemType> *src );
		void clear( BTnode<elemType>* );
		
};

template<typename elemType> 
inline  BinaryTree<elemType>::
	BinaryTree() : _root(0){}


template<typename elemType> 
inline  BinaryTree<elemType>::
	BinaryTree( const BinaryTree& rhs)
	{
		copy( _root , rhs._root);
	}


template<typename elemType> 
inline  BinaryTree<elemType>::
	~BinaryTree(){ clear(); }

	
template<typename elemType> 
inline  BinaryTree<elemType>& BinaryTree<elemType>::
	operator=( const BinaryTree& rhs)
	{
		if( this != &rhs )
			{
				clear();
				copy( _root, rhs._root );
			}
		return *this;
	}

template<typename elemType> 
void BinaryTree<elemType>::
	insert( const elemType &elem )
	{
		if( !_root )
			_root = new BTnode<elemType>(elem);
		else _root->insert_val( elem );
	}

template<typename elemType> 
void BinaryTree<elemType>::
	remove(const elemType &elem )
	{
		if( _root )
		{
			if( _root->_val == elem )
				remove_root();
			else _root->remove_value( elem, _root );
		}
			
	}

template<typename elemType> 
void BinaryTree<elemType>::
	remove_root()
	{
		if( !_root ) return ;
		BTnode<elemType> *tmp = _root;
		if( _root->_rchild )
		{
			_root = _root->_rchild;
			if( tmp->_lchild )
			{
				BTnode<elemType> *lc = tmp->_lchild;
				BTnode<elemType> *newlc = _root->_lchild;
				if( !newlc )
					_root->_lchild = lc;
				else lchild_leaf( lc, newlc );
			}
		}
		else _root = _root->_lchild;
		delete tmp;
	}

template<typename elemType>
void BinaryTree<elemType>::
	clear( BTnode<elemType> *pt )
	{
		if( pt )
		{
			clear( pt->_lchild );
			clear( pt->_rchild );
			delete pt;
		}
	}

template<typename elemType> 
void BinaryTree<elemType>::
	clear()
	{
		if( _root ){
			clear( _root ); 
			_root = 0;
		}
	}

/*-----------------class BTnode---------------------------------*/
template<typename valType>
class BTnode{
	
	public:
		friend class BinaryTree<valType>;
		void insert_val( const valType& );
		static void lchild_leaf( BTnode*, BTnode* );
		void remove_val( const valType&, valType*& );
		void preorder( BTnode *pt, ostream &os ) const;
		void inorder( BTnode *pt, ostream &os ) const;
		void postorder( BTnode *pt, ostream &os ) const;
		
	private:
		valType _val;
		int _cnt;
		BTnode *_lchild;
		BTnode *_rchild;
		
};

template<typename valType>
void BTnode<valType>::
	insert_val( const valType &val )
	{
		if( val == _val){
			_cnt++;
			return;
		}
	
		if( val < _val ){
			if( !_lchild )
				_lchild = new BTnode( val );
			else _lchild->insert_val( val );
		}
		else{
			if( !_rchild )
				_rchild = new BTnode( val );
			else _rchild->insert_val( val );
		}
	}

template<typename valType>
void BTnode<valType>::
	lchild_leaf( BTnode *leaf, BTnode *subtree )
	{
		while( subtree->_lchild )
			subtree = subtree->_lchild;
		subtree->_lchild = leaf;
	}

template<typename valType>
void BTnode<valType>::
	remove_val( const valType &val, valType *&prev )
	{
		if( val < _val )
		{
			if( !_lchild )
				return;
			else _lchild->remove_val( val, _lchild );			
		}
		else if( val > _val )
		{
			if( !_rchild )
				return;
			else _lchild->remove_val( val, _rchild );
		}
		else
		{
			if( _rchild )
			{
				prev = _rchild;
				if( _lchild )
					if( !prev->_lchild )
						prev->_lchild = _lchild;
					else BTnode<valType>::_lchild_leaf( _lchild, prev->_lchild );
			}
			else prev = _lchild;
			delete this;
		}
		
	}

template<typename valType>
void BTnode<valType>:: 
	preorder( BTnode *pt, ostream &os ) const
{
	if( pt )
	{
		display_val( pt, os );
		if( pt->_lchild ) preorder( pt->_lchild, os );
		if( pt->_rchild ) preorder( pt->_rchild, os );
	}
}

template<typename valType>
void BTnode<valType>:: 
	inorder( BTnode *pt, ostream &os ) const
{
	if( pt )
	{
		if( pt->_lchild ) preorder( pt->_lchild, os );
		display_val( pt, os );		
		if( pt->_rchild ) preorder( pt->_rchild, os );
	}
}

template<typename valType>
void BTnode<valType>:: 
	postorder( BTnode *pt, ostream &os ) const
{
	if( pt )
	{
		if( pt->_lchild ) preorder( pt->_lchild, os );
		if( pt->_rchild ) preorder( pt->_rchild, os );
		display_val( pt, os );		
	}
}

template<typename valType>
inline void display_val( BTnode<valType> *pt, ostream &os )
{
	os <<pt->_val <<" ";
}

/*-----------------------main-------------------------------*/
int main(int argc, char *argv[])
{
	BinaryTree<string> bt;
	bt.insert("pig");
	bt.insert("eey");
	bt.insert("roo");
	bt.preorder();
	
	return 0;
}




