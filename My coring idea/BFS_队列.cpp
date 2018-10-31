/*----------------------------------------------------------------

* @Author: Su

* @Description: 广度搜索遍历 

* @Creath Date: 
----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int MAXV = 1000;
bool vis[MAXV][MAXV] = {{false}};
int array[MAXV][MAXV] = {{-1}};
int m, n;
int deX[2] = {-1, 1};
int deY[2] = {-1, 1};

typedef struct node{
	int x;
	int y;
	node(int myx, int myy){
		x = myx;
		y = myy;
	}
}Node;

bool judge(int x, int y)
{
	if(x>=0&&x<m&&y>=0&&y<n){
		if(vis[x][y]==false&&array[x][y]==1)
			return true;
	}		
	return false;
}

void BFS(Node node)
{
	queue<Node> que;

	que.push(node);
	while(!que.empty())
	{
		Node tp = que.front();
		que.pop();
		vis[tp.x][tp.y] = true;
		
		for(int i =0; i<2; i++){
			if(judge(tp.x+deX[i],tp.y))
				que.push(Node(tp.x+deX[i], tp.y));			
		}
		for(int i =0; i<2; i++){
			if(judge(tp.x, tp.y+deY[i]))
				que.push(Node(tp.x, tp.y+deY[i]));				
		}
	}
	
}


int main(int argc, char *argv[])
{
	int count = 0;
	scanf("%d%d", &m, &n);
	
	for(int i = 0; i<m; i++)
		for(int j = 0; j<n; j++)
			scanf("%d", &array[i][j]);
	
	for(int i = 0; i<m; i++)
		for(int j = 0; j<n; j++){
			if(array[i][j]!=0&&vis[i][j]==false){
				count++;
				BFS(Node(i, j));
			}
				
		}
	cout<<count;
	return 0;
}

/*
测试案例 
6 7
0 1 1 1 0 0 1
0 0 1 0 0 0 0
0 0 0 0 1 0 0
0 0 0 1 1 1 0
1 1 1 0 1 0 0
1 1 1 1 0 0 0

1块的个数为4
 
*/ 

