/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;
typedef struct node* Node;

struct node{
	int data;
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
/**此处创建的二叉树非完全二叉树*/
Node CreateTree(int a[], int n)
{
	Node root = NULL;
	for(int i = 0; i<n; i++)
		Insert(root, *(a+i));
	return root; 
}

void preorder(Node nodetree)
{
	if(!nodetree) return;
	else{
		printf("%d ", nodetree->data);
		preorder(nodetree->L);		
		preorder(nodetree->R);
	}
}

void inorder(Node nodetree)
{
	if(!nodetree) return;
	else{		
		inorder(nodetree->L);
		printf("%d ", nodetree->data);
		inorder(nodetree->R);
	}
}

void postorder(Node nodetree)
{
	if(!nodetree) return;
	else{		
		postorder(nodetree->L);
		postorder(nodetree->R);
		printf("%d ", nodetree->data);
	}
}

int main(int argc, char *argv[])
{
	int array[] = {1,2,3,4,5,6};
	Node tree = CreateTree(array, (sizeof array /sizeof array[0]) );
	preorder(tree);

	return 0;
}




