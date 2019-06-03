/*----------------------------------------------------------------

* @Author: Su

* @Description: 使用圣经作为搜索文本 

* @Creath Date: 

----------------------------------------------------------------*/

#include "../openFile.h"
#include <queue>
using namespace std;

namespace BSTversion2 {
template <typename Key, typename Value>
class BST{
	private:
		struct Node{
			Key key;
			Value value;
			Node *left;
			Node *right;			
			Node( Key _key, Value _value ) : 
				left( nullptr ), right( nullptr ), value( _value ), key( _key )
				{}
			Node( Node *node ) : key( node->key ), value( node->value ), 
				left( node->left ), right( node->right ) 
				{}
		};
		Node *root;
		int count; //节点个数 
		
	public:
		BST() {
			root = nullptr;	
		}
		~BST() {
			destory( root );
		}
		//是否空判断 
		bool isEmpty() {
			return count == 0;
		}
		//插入节点 
		void insert( Key key, Value value ) {
			root = _insert( root, key, value );//非递归插入 
		}
		//返回节点个数 
		int size() {
			return count;
		}
		//是否存在某个key 
		bool contain( Key key ) {
			return contain( root, key );
		}
		//搜索指定key，不存在返回空指针 
		Value *search( Key key ) {
			return search( root, key );
		}
		//递归前序遍历 
		void preOrder() {
			preOrder( root );
		}
		//递归中序遍历 
		void inOrder() {
			inOrder( root );
		}
		//递归后序遍历 
		void postOrder() {
			postOrder( root );
		}
		//层序遍历 
		void leverOder() {
			if( root != nullptr ) {
				queue<Node*>que;
				
				que.push( root );
				Node *node = que.front();
				while( !que.empty() ) {					
					if( node->left != nullptr )
						que.push( node->left );
					if( node->right != nullptr )
						que.push( node->right );
					que.pop();
					cout << node->key << endl;
					node = que.front();
				}
			}
		}
		//移除最小节点 
		void removeMinNode() {
			root = removeMinNode( root );
		}
		//移除最大节点 
		void removeMaxNode() {
			root = removeMaxNode( root );
		}
		//删除任意节点 
		void removeNode( Key key ) {
			root = removeNode( root, key );
		}
		//返回最大节点 
		Node* maxNode() {
			assert( count > 0 );
			return maxNode( root );
		}
		//返回最小节点 
		Node* minNode() {
			assert( count > 0 );
			return minNode( root );
		}
		//返回最后一个小于等于目标值的值
		Key* floor( Key key ) {
			if( count == 0 || key < minNode()->key ) //不存在比树中还要小的目标值 
				return nullptr;
			Node *node = floor( root, key );
			
			return &( node->key );
		}
		//返回第一个大于等于目标值的值
		Key* ceil( Key key ) {
			if( count == 0 || key > maxNode()->key )
				return nullptr;
			Node *node = ceil( root, key );

			return &( node->key );
		}
	private:
		//插入递归写法 
		Node* insert( Node *root, Key key, Value value ) {
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
		//插入非递归写法 
		Node* _insert( Node *root, Key key, Value value ) {
			Node *node = root;
			while( node != nullptr && node->key != key ) {
				if( node->key == key )
					break;
				if( key > node->key && node->right != nullptr)
					node = node->right;
				else if( node->right == nullptr )
					break;
				if( key < node->key && node->left != nullptr)
					node = node->left;
				else if( node->left == nullptr )
					break;
			}
			if( node == nullptr )
				root = new Node( key, value );
			else if( node != nullptr && node->key == key )
				node->value = value;
			else if( node != nullptr && node->left == nullptr )
				node->left = new Node( key, value );
			else
				node->right= new Node( key, value );
			if( node != nullptr && node->key == key );
			else count += 1;
			return root;
		}
		
		bool contain( Node *root, Key key ) {
			if( root == nullptr )
				return false;
			if( root->key == key )
				return true;
			else if( key > root->key )
				return contain( root->right, key );
			else return contain( root->left, key );
		}
		
		Value *search( Node *root, Key key ) {
			if( root == nullptr )
				return nullptr;
			if( root->key == key )
				return &( root->value );
			else if( key > root->key )
				return search( root->right, key );
			else 
				return search( root->left, key );
		}
		
		void preOrder( Node *root ) {
			if( root != nullptr ) {
				cout << root->key << endl;
				preOrder( root->left );
				preOrder( root->right );
			}
				
		}
		void inOrder( Node *root ) {
			if( root != nullptr ) {
				inOrder( root->left );
				cout << root->key << endl;
				inOrder( root->right );
			}
		}
		void postOrder( Node *root ) {
			if( root != nullptr ) {
				postOrder( root->left );
				postOrder( root->right );
				cout << root->key << endl;
			}
		}
		void destory( Node *root ) {
			if( root != nullptr ) {
				destory( root->left );
				destory( root->right );
				delete root;
				--count;
			}		
		}
		//返回最大节点 
		Node* maxNode( Node *node ) {
			if( node->right == nullptr )
				return node;
			return maxNode( node->right );
		}
		//返回最小节点 
		Node* minNode( Node *node ) {
			if( node->left == nullptr )
				return node;
			return minNode( node->left );			
		}
		//移除最小节点
		Node* removeMinNode( Node* node ) {
			if( node->left == nullptr ) {
				Node *rightNode = node->right; //这里很巧妙融合了两种条件空和非空节点 
				delete node;
				--count;
				return rightNode;
			}
			else node->left = removeMinNode( node->left );
			return node;
		}
		//移除最大节点 
		Node* removeMaxNode( Node* node ) {
			if( node->right == nullptr ) {
				Node *leftNode = node->left;
				delete node;
				--count;
				return leftNode;
			}
			else node->right = removeMaxNode( node->right );
			return node;
		}
		//移除任意节点，存在三种情况 
		Node* removeNode( Node* node, Key key ) {
			if( node == nullptr )
				return nullptr;
			if( key > node->key ) {
				node->right = removeNode( node->right, key );
				return node;
			}
			else if( key < node->key ) {
				node->left = removeNode( node->left, key );
				return node;
			}
			if( key == node->key ){
				
				if( node->left == nullptr ) {
					Node *rightNode = node->right;
					delete node;
					--count;
					return rightNode;
				}
				else if( node->right == nullptr ) {
					Node *leftNode = node->left;
					delete node;
					--count;
					return leftNode;
				}
				//左右都有孩子节点 
				else {
					//方法一：采用前驱节点进行替补 
					Node *postInher = new Node( maxNode( node->left ) );//后继节点：右子树中最小的节点 
					postInher->right = node->right;
					postInher->left = removeMaxNode( node->left );//递归删除后继节点(即是删除最小节点) 
					
					//方法二：：采用后继节点进行替补
					//Node *successor = new Node( minNode( node->right ) );
					//successor->left = root->left;
					//successor->right = removeMinNode( root->right );
					delete node;
					return postInher;
				}				
			}
		}
		
		Node* floor( Node *root, Key key ) {
			if( root == nullptr )
				return nullptr;
			
			if( root->key == key ) //存在目标值，直接返回 
				return root;
				
			if( root->key > key ) //比目标值还大，递归左子树，我们要的是最后一个小于等于目标值 
				root = floor( root->left, key );
			
			//进入到 最后一个小于等于目标值的范围 
			else if( root->key < key ) {
				Node *tmp = floor( root->right, key );//尝试递归右子树找出最后一个小于目标的值 
				return ( tmp ? tmp : nullptr );
			}
			
			return root;					
		}
		
		Node *ceil( Node *root, Key key ) {
			if( root == nullptr )
				return nullptr;
			
			if( root->key == key )
				return root;
			if( root->key < key )
				root = ceil( root->right, key );
				
			else if( root->key > key ) {
				Node *tmp = ceil( root->left, key );
				return ( tmp ? tmp : nullptr );
			}
			return root;	
		}		
	};
	
//template <typename Key, typename Value>
//	int BST<Key, Value>::count = 0;
	
void findWord( const string& str ){
		BST<string, int> tree;
		string filePath = "./bible.txt";
		vector<string>words;
		
		opfile::openfile( filePath, words );//打开圣经文本 
		
		for( auto iters = words.begin(); iters != words.end(); ++iters ) {
			int *res = tree.search( *iters );
			if( res == nullptr )
				tree.insert( *iters, 1 );
			else ++( *res );
		}
		cout << "Sum word: " << tree.size() << endl;
		if( tree.contain( str ) )
			cout << str << " appear: " << (*tree.search( str )) << " times" << endl;
		else 
			cout << str << "no appear !!!" << endl;
		//测试函数 
//		auto node = tree.minNode();
//		cout << node->key << endl;
//		tree.removeNode( node->key );
//		cout << tree.contain( node->key ) << endl;
//		cout << "Sum word: " << tree.size() << endl;
		cout << *tree.ceil( str ) ;
	}
}



int main(int argc, char *argv[])
{
	using namespace BSTversion2;
	
	//findWord( "melt" );

	return 0;
}