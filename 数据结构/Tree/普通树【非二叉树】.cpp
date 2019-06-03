/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
#define maxn 100
int index = 0;

struct node{
	
	int data;
	int layer;
	vector <int> child;
	
}Node[maxn];

int NewNode(int data)
{
	Node[index].data = data;
	Node[index].child.clear();
	return index++;
}

void preorder(int inx)
{
	printf("%d ", Node[inx].data);

	for(int i = 0; i<Node[inx].child.size(); i++)
		preorder(Node[inx].child[i]);
}

void layerorder(int inx)
{
	queue<int>que;
	
	que.push(inx);
	Node[inx].layer = 1;
	
	while(!que.empty())
	{
		int tp = que.front();
		que.pop();
		printf("%d ", Node[tp].data);

		for(int i = 0; i<Node[tp].child.size(); i++)
		{
			int kid = Node[tp].child[i];
			Node[kid].layer = Node[tp].layer+1;
			que.push(kid);
		}
	}
}

int main(int argc, char *argv[])
{
	return 0;
}




