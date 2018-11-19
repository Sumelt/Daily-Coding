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
	else Insert(root->R, newData);
	
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

/**创建二叉搜索树**/
Node CreateTree(int a[], int n)
{
	Node root = NULL;
	for(int i = 0; i<n; i++)
		Insert(root, *(a+i));
	return root; 
}

int main(int argc, char *argv[])
{
	int array[] = {5, 3, 7, 4, 2, 8, 6};
	Layerorder(CreateTree(array, 7));
	return 0;
}

