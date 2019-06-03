/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <queue>
using namespace std;

struct node {
	
	int v, height; //利用高度来求得平衡因子 
	int Layer = 0;
	node *lchild, *rchild;
};

node* newNode( int v )
{
	node *Node = new node;
	Node->v = v;
	Node->height = 1;
	Node->lchild = Node->rchild = NULL;
	return Node;	
}

int getHeight( node* root )
{
	if( root == NULL ) return 0;
	return root->height;
}

int getBalanceFactor( node* root )
{
	return getHeight( root->lchild ) - getHeight( root->rchild );
	
}

void updateHeight( node* root )
{
	root->height = max( getHeight( root->lchild ), getHeight( root->rchild ) )+1;
}

void search( node* root, int x )
{
	if( root == NULL ){
		cout << "search faile!\n";
		return;
	} 
	if( root->v == x )
		cout << root->v;
	else if( root->v > x )
		search( root->lchild, x );
	else search( root->rchild, x );
}

void R( node* &root )
{
	node *temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	root = temp;
}

void L( node* &root )
{
	node *temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	root = temp;
	
}

void insert( node* &root, int v )
{
	if( root == NULL ){  //空节点说明找到插入点 
		root = newNode( v );
		return;
	}
	if( v < root->v )
	{
		insert( root->lchild, v );
		updateHeight( root );
		if( getBalanceFactor( root ) == 2 )
		{
			if( getBalanceFactor( root->lchild ) == 1 ) //LL
				R( root );
			else if( getBalanceFactor( root->lchild ) == -1 ) //LR
			{
				L( root->lchild );
				R( root );
			}
		}
	}
	else
	{
		insert( root->rchild, v );
		updateHeight( root );
		if( getBalanceFactor( root ) == -2 )
		{
			if( getBalanceFactor( root->rchild ) == -1 ) //RR
				L( root );
			else if( getBalanceFactor( root->rchild ) == 1 ) //RL
			{
				R( root->rchild );
				L( root );
			}
		}
	}
}

node* Creat( int data[], int n )
{
	node* root = NULL;
	for( int i = 0; i< n; i++ )
		insert( root, data[ i ] );
	return root;
}

void Free( node* &root )
{
	if( root == NULL ) return;
	else if( root->rchild ) Free( root->rchild );
	else Free( root->lchild );
}

/**层序遍历**/
using Node = node*;

void Layerorder(Node nodetree)
{
	queue<Node>que;

	nodetree->Layer = 1;
	que.push(nodetree);
	while(!que.empty())
	{
		Node tp = que.front();
		que.pop();
		printf("%d is %d\n", tp->v, tp->Layer);
		if(tp->lchild){
			tp->lchild->Layer = tp->Layer+1;
			que.push(tp->lchild);
		}
		if(tp->rchild){
			tp->rchild->Layer = tp->Layer+1;
			que.push(tp->rchild);
		}

	}
}

int main(int argc, char *argv[])
{
	int array[] = {7, 5, 4, 1};
	node *root = Creat( array, sizeof( array ) / sizeof( *array ) );
	Layerorder( root );
	return 0;
}

