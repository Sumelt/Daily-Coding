/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n; const int MAXV = 1000;
bool vis[MAXV] = {false};
vector<int>ary[MAXV];

int DFS(int i, int dept)
{
	vis[i] = true;
	
	for(int j = 0; j<ary[j].size(); j++)
	{
		int v = ary[i][j]; //获得该行的列的值 ，该列下次又作为行，不断递归寻找最深的 度 
		if(vis[v]==false)
			DFS(j, dept+1);
	}	
}

void DFSTrave()
{
	for(int i = 0; i<n; i++)
		if(!vis[i])  //该点还没访问
			DFS(i, 1); 
}

int main(int argc, char *argv[])
{
	n = 3;
	return 0;
}




