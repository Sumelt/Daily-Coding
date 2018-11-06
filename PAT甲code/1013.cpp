/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int maxn = 1000;
int G[maxn][maxn] = {0};
bool vis[maxn] = {0};
bool vison[maxn] = {0};
int eqCity, numCity, dept = 0;

void DFS(int u)
{
	vis[u] = true;
	
	for(int j = 1; j<=numCity; j++){
		if(j==eqCity) continue;
		else {
				if(!vis[j]&&G[u][j]>0){
				vison[u] = true;
				vison[j] = true;
				dept++;
				DFS(j);
			}				
		}
	}
	
}

void DFSTravel()
{
	for(int i = 1; i<=numCity; i++)
	{
		if(i==eqCity) continue;
		else{
			if(!vis[i])
				DFS(i);
		}
	}	
}

int main(int argc, char *argv[])
{
	int numHigh, checkCity;
	int city1, city2, count = 0;
	
	cin>>numCity >>numHigh >>checkCity;
	
	for(int i = 0; i<numHigh; i++)
	{
		cin>>city1 >>city2;
		G[city1][city2] = city2;
		G[city2][city1] = city1;
	}
	
	for(int i = 0; i<checkCity; i++)
	{
		cin>>eqCity;
		DFSTravel();
			
		for(int j = 1; j<=numCity; j++)
			if(vison[j]==false) count++;
			
		fill(vison, vison+numCity+1, 0);
		if(count==numCity) cout<<count-2<<endl;
		else if(count>1&&dept>0) cout<<count-1<<endl;
		else if(count>1&&dept==0) cout<<count-2<<endl;
		else cout<<0<<endl;
		count = 0;
	}
	
	return 0;
}




