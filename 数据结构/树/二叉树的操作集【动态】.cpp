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
typedef struct node* Node;

struct node{
	int data;
	int Layer;
	Node L;
	Node R;
	node(int mydata){
		L = NULL;
		R = NULL;
		data = mydata;
	}
};


/**新建一个节点**/
Node NewNode(int data)
{
	Node newnode= new node(data);
	return newnode;
}


/**查找指定值并修改**/
void SearchAlter(Node root, int oldData, int newData)
{
	if(root == NULL) return;
	else
	{
		if(root->data = oldData) root->data = newData;
		SearchAlter(root->L, oldData, newData);
		SearchAlter(root->R, oldData, newData);
	}

} 


/**插入一个新的节点**/
void Insert(Node &root, int newData)
{
	if(!root)
	{
		root = NewNode(newData);
		return;
	}
	if(root->L==NULL)
		Insert(root->L, newData);
	else Insert(root->R, newData);
	
}



/**此建树非完全二叉树，只是不断在右节点不断增加子节点*/
Node CreateTree(int a[], int n)
{
	Node root = NULL;
	for(int i = 0; i<n; i++)
		{
			//if(i!=0)cout<<root->data<<endl;		
			Insert(root, *(a+i));
				
		}
	return root; 
}


/**先序遍历**/
void preorder(Node nodetree)
{
	if(!nodetree) return;
	else{
		printf("%d ", nodetree->data);
		preorder(nodetree->L);		
		preorder(nodetree->R);
	}
}


/**中序遍历**/
void inorder(Node nodetree)
{
	if(!nodetree) return;
	else{		
		inorder(nodetree->L);
		printf("%d ", nodetree->data);
		inorder(nodetree->R);
	}
}


/**后序遍历**/
void postorder(Node nodetree)
{
	if(!nodetree) return;
	else{		
		postorder(nodetree->L);
		postorder(nodetree->R);
		printf("%d ", nodetree->data);
	}
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


int pre[] = {1, 2, 3, 4, 5, 6};
int in[] = {2, 1, 4, 3, 6, 5};
Node LayerCreate(int preL, int preR, int inL, int inR)
{
	if(preL > preR) return 0;
	Node root = NewNode(pre[preL]);
	
	int k;
	for(k = inL; k<=inR; k++)
	{
		if(pre[preL]==in[k])
			break;
	}
	int numLeft = k - inL;
	root->L = LayerCreate(preL+1, preL+numLeft, inL, k-1);
	root->R = LayerCreate(preL+numLeft+1, preR, k+1, inR);
	
	return root;
}

int main(int argc, char *argv[])
{
	int array[] = {1,2,3,4,5,6};
	Node tree = CreateTree(array, (sizeof array /sizeof array[0]) );
	//preorder(tree);
	//Layerorder(tree);
	//Node tree = LayerCreate(0, 5, 0, 5);
	Layerorder(tree);
	cout<<endl;
	postorder(tree);
	return 0;
}


