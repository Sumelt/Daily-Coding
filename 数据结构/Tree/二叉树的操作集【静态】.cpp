/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

#define maxn 20
using namespace std;
int index = 0;

struct node{
	int data;
	int L;
	int R;
	int layer;
	
}Node[maxn];


void SearchAlter(int inx, int oldData, int newData)
{
	if(inx == -1)
		return;
	else 
		if(Node[inx].data == oldData)
			Node[inx].data = newData;
			
	SearchAlter(Node[inx].L, oldData, newData);
	SearchAlter(Node[inx].R, oldData, newData);
}


void preorder(int inx)
{
	if(inx == -1) return;
	else
	{
		printf("%d ", Node[inx].data);
		preorder(Node[inx].L);
		preorder(Node[inx].R);
	}
}

void inorder(int inx)
{
	if(inx == -1) return;
	else
	{
		inorder(Node[inx].L);
		printf("%d ", Node[inx].data);		
		inorder(Node[inx].R);
	}
}

void postorder(int inx)
{
	if(inx == -1) return;
	else
	{
		postorder(Node[inx].L);
		postorder(Node[inx].R);
		printf("%d ", Node[inx].data);		
	}
}

void layerorder(int inx)
{
	queue<node>que;
	
	que.push(Node[inx]);
	Node[inx].layer = 1;
	
	while(!que.empty())
	{
		node tp = que.front();
		que.pop();
		printf("%d ", tp.data);
		if(tp.L!=-1){
			Node[tp.L].layer = tp.layer+1;
			//printf("%d is %d layer\n", Node[tp.L].data, Node[tp.L].layer);
			que.push(Node[tp.L]);
		}
		if(tp.R!=-1){
			Node[tp.R].layer = tp.layer+1;
			//printf("%d is %d layer\n", Node[tp.R].data, Node[tp.R].layer);
			que.push(Node[tp.R]);
		}
		
	}
}

int NewNode(int data)
{
	Node[index].data = data;
	Node[index].L = -1;
	Node[index].R = -1;
	return index++;
}


void Insert(int &inx, int newData)
{
	if(inx == -1)
	{
		inx = NewNode(newData);
		return;
	}
	else if(Node[inx].L==-1)
		Insert(Node[inx].L, newData);
	else Insert(Node[inx].R, newData);
		
}


int CreateTree(int array[], int n)
{
	int root = -1;
	
	for(int i = 0; i<n; i++)
		Insert(root, *(array+i));
	
	return root;
}

int main(int argc, char *argv[])
{
	int array[] = {1, 2, 3, 4, 5, 6};
	int inx = CreateTree(array, sizeof(array)/sizeof(array[0]));
	//preorder(inx);
//	cout<<endl;
//	inorder(inx);
//	cout<<endl;
//	postorder(inx);
//	cout<<endl;
	layerorder(inx);
	return 0;
}

