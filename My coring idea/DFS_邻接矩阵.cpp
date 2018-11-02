/*----------------------------------------------------------------

* @Author: Su

* @Description: ö�����е㣬�ҵ�һ��·�� 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>

using namespace std;
const int MAXV = 1000;
const int INF = 1000000000;

int n, G[MAXV][MAXV] = {(0)};
bool vis[MAXV] = {false};

void DFS(int i, int deep)
{
	vis[i] = true;
	
	for(int j = 0; j<n; j++)
	{
		if(vis[j]==false&&G[i][j]!=INF)  //������һ���ڵ� 
			{
				printf("both of them: %d %d have connect\n",i, j);
				DFS(j, deep+1);
			}			
	}
}

void DFSTrave()
{
	for(int i = 0; i<n; i++)
		if(!vis[i])  //�õ㻹û����
			DFS(i, 1); 
}

int main(int argc, char *argv[])
{
	n = 3;
	G[0][1] = 1;
	G[1][0] = 1;
	G[1][2] = 1; 
	G[2][1] = 1;
	G[0][2] = 1;
	G[2][0] = 1;
	
	DFSTrave();
	return 0;
}




