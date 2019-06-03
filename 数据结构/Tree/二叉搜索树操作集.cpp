/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

namespace BSTversion {
typedef struct node* Node;
	
struct node{
	int data;
	int Layer;
	Node L;
	Node R;
	Node Fnode; //记录该节点的父节点 
	node(int mydata){
		L = NULL;
		R = NULL;
		Fnode = NULL;
		data = mydata;
	}
};

/**新建一个节点**/
Node NewNode(int data)
{
	Node newnode= new node(data);
	return newnode;
}

/**插入一个新的节点**/
void Insert(Node &root, int newData)
{
	if(!root)
	{
		root = NewNode(newData);
		return;
	}
	if(root->data >newData)
		Insert(root->L, newData);
	else if(root->data <newData) 
		Insert(root->R, newData);
	else return; //已经存在相同节点， 
	
}

/**创建二叉搜索树**/
Node CreateTree(int a[], int n)
{
	Node root = NULL;
	for(int i = 0; i<n; i++)
		Insert(root, *(a+i));
	return root; 
}

/**层序遍历**/
void Layerorder(Node nodetree)
{
	queue<Node>que;

	nodetree->Layer = 1;
	que.push(nodetree);
	while(!que.empty())
	{
		Node tp = que.front();
		que.pop();
		printf("%d is %d\n", tp->data, tp->Layer);
		if(tp->L){
			tp->L->Layer = tp->Layer+1;
			que.push(tp->L);
		}
		if(tp->R){
			tp->R->Layer = tp->Layer+1;
			que.push(tp->R);
		}

	}
}

node* findMax( node* root )
{
	node *temp = NULL;
	while( root->R != NULL)
	{
		temp = root;
		root = root->R;
		root->Fnode = temp;
	}
		
	return root;
}

node* findMin( node* root )
{
	node *temp = NULL;
	while( root->L != NULL )
	{
		temp = root;
		root = root->L;
		root->Fnode = temp;
	}
 		
	return root;
}

void deleteNode( node* &root, int x ) {
		if( root == NULL )return;
		if( root->data == x )
		{
			if( root->R == NULL && root->L == NULL )
				root = NULL;
			else if( root->L )
			{
				node* pre = findMax( root->L );
				root->data = pre->data;
				//deleteNode( root->L, pre->data );
				if( pre->L )
					pre->Fnode->R = pre->L; //该节点只有左子树 
				root->L = NULL; //把该节点的左节点指向NULL	
				delete pre; //该节点是叶节点或者是有左节点 
				 
			}
			else
			{
				node* next = findMin( root->R );
				root->data = next->data;
				//deleteNode( root->R, next->data );
				if( next->R )
					next->Fnode->L = next->R; //该节点只有右子树
				root->R = NULL; 
				delete next; //该节点是叶节点或者是有右节点 
							
			}
		}
		else if( root->data > x )
			deleteNode( root->L, x );
		else deleteNode( root->R, x );
	}
	
}



int main(int argc, char *argv[])
{
	
	return 0;
}

