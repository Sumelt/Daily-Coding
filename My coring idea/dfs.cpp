/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

const int maxn = 30;
int n, v, maxvalue = 0;
int w[maxn], c[maxn];

void dfs(int index, int sumw, int sumc)
{
	if(index==n){
		
		if(sumw<=v&&sumc>maxvalue)
			maxvalue = sumc;
		return;
	}
	dfs(index+1, sumw, sumc);
	dfs(index+1, sumw+w[index], sumc+c[index]);
	
}

int main(int argc, char *argv[])
{
	scanf("%d%d",&n,&v);
	for(int i =0; i<n; i++)
		scanf("%d",&w[i]);
	for(int i =0; i<n; i++)
		scanf("%d",&c[i]);
	dfs(0, 0, 0);
	printf("%d\n",maxvalue);
	return 0;

}

