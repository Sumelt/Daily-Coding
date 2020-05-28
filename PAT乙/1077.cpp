/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 14/09/18 10:55

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	int soc;
	double res = 0;
	int maxsoc, n;	
	scanf("%d%d",&n, &maxsoc);
	vector<int>ary[n];
	
	for(int i =0; i<n; i++)
	{
		for(int j =0; j<n; j++)
		{
			cin>>soc;
			if(soc<=maxsoc&&soc>=0)
				ary[i].push_back(soc);
		}
	}
	for(int i = 0; i<n; i++)
		sort(ary[i].begin()+1,ary[i].end());
	
	for(int i =0; i<n;i++)
	{	
		for(int j = 2; j <ary[i].size()-1; j++)
			res+=ary[i][j];
		res = res*1.0/(ary[i].size()-3);
		res = (res + ary[i][0])/2;
		//cout<<round(res)<<endl;
		printf("%d\n",(int)(res+0.5));
		res = 0;
	}
		
	
	
	return 0;
}




