/*----------------------------------------------------------------

* @Author: Su

* @Description:  求到达终点的最小步数 

* @Creath Date: consume 2 hours with coding and debug
my coding speed get slow now, beacuse i spend litter time on it.
But i that like it, and i will pass cet4 in December


----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXV = 1000;
bool vis[MAXV][MAXV] = {{false}};
char ary[MAXV][MAXV];
int m, n;
int deX[2] = {-1, 1};
int deY[2] = {-1, 1};

typedef struct node{
	int x;
	int y;
	int layer; 
	node(int myx, int myy, int mydept){
		x = myx;
		y = myy;
		layer = mydept;
	}
	node(){}
}Node;

bool judge(int x, int y)
{
	if(x>=0&&x<m&&y>=0&&y<n){
		if(vis[x][y]==false&&(ary[x][y]=='.'||ary[x][y]=='T')) //I can not think ary[x][y]=='T' is important conditon
			return true;
	}		
	return false;
}

int BFS(Node node)
{
	int dept = 0;
	bool flag = false;
	queue<Node>que;
	que.push(node);
	
	while(!que.empty())
	{
		Node tp;
		tp = que.front();
		if(ary[tp.x][tp.y]=='T'){
			
			printf("%d %d\n",tp.x, tp.y);
			return tp.layer;
		}
			
		que.pop();
		vis[tp.x][tp.y] = true;
		
		for(int i = 0; i<2; i++)
			if(judge(tp.x+deX[i], tp.y)){
				que.push(Node(tp.x+deX[i], tp.y, tp.layer+1));  //use last layer to add 1 that is perfect
			}
		for(int j = 0; j<2; j++)
			if(judge(tp.x, tp.y+deY[j])){
				que.push(Node(tp.x, tp.y+deY[j], tp.layer+1));	
			}
	}
		
}

int main(int argc, char *argv[])
{
	int count = 0;
	Node start;
	Node end;
	
	scanf("%d%d", &m, &n);
	cin.get();
	
	for(int i = 0; i<m; i++){		
		for(int j = 0; j<n; j++){
			scanf("%c",&ary[i][j]);
			
			if(ary[i][j]=='S'){
				start.x = i;
				start.y = j;
				start.layer = 0;
			}				
			else if(ary[i][j]=='T'){
				end.x = i;
				end.y = j;
			}		
		}
		cin.get();			
	}
	count = BFS(start);
	cout <<count;
	return 0;
}

/*
Test Example:
5 5
.....
.*.*.
.*S*.
.***.
...T*

Result :
4 3
11

*/