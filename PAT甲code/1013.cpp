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
int eqCity, numCity, block = 0;

void DFS(int u)
{
	vis[u] = true;	
	for(int j = 1; j<=numCity; j++){
		if(j==eqCity) continue;
		else {
				if(!vis[j]&&G[u][j]>0)
					DFS(j);				
		}
	}	
}

int main(int argc, char *argv[])
{
	int numHigh, checkCity;
	int city1, city2, count = 0;
	
	//cin>>numCity >>numHigh >>checkCity;
	scanf("%d %d %d",&numCity, &numHigh, &checkCity);
	
	for(int i = 0; i<numHigh; i++)
	{
		//cin>>city1 >>city2;
		scanf("%d %d", &city1, &city2);
		G[city1][city2] = city2;
		G[city2][city1] = city1;
	}
	
	for(int i = 0; i<checkCity; i++)
	{
		cin>>eqCity;
		for(int j = 1; j<=numCity; j++){
			if(eqCity==j||vis[j]) continue;
			else{
				block++;
				DFS(j);
			}						
		}
		printf("%d\n", block-1);
		block = 0;					
		fill(vis, vis+numCity+1, 0);
	}	
	return 0;
}
