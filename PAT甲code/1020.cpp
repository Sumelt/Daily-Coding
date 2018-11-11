/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef struct node* Node;
int post[30];
int in[30];

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

Node NewNode(int data)
{
	Node newnode= new node(data);
	return newnode;
}

Node LayerCreate(int preL, int preR, int inL, int inR)
{
	if(preL > preR) return 0;
	Node root = NewNode(post[preR]);
	
	int k;
	for(k = inL; k<=inR; k++)
	{
		if(post[preR]==in[k])
			break;
	}
	int numLeft = k - inL;
	root->L = LayerCreate(preL, preL+numLeft-1, inL, k-1);
	root->R = LayerCreate(preL+numLeft, preR-1, k+1, inR);
	
	return root;
}

void Layerorder(Node nodetree)
{
	queue<Node>que;

	nodetree->Layer = 1;
	que.push(nodetree);
	while(!que.empty())
	{
		Node tp = que.front();
		que.pop();
		//printf("%d is %d\n", tp->data, tp->Layer);
		if(tp->Layer==1)
			printf("%d", tp->data);
		else printf(" %d", tp->data);
		
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

int main(int argc, char *argv[])
{
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i<n; i++)
		scanf("%d", &post[i]);	
	for(int i = 0; i<n; i++)
		scanf("%d", &in[i]);
	Node tree = LayerCreate(0, n-1, 0, n-1);
	Layerorder(tree);
	
	return 0;
}




