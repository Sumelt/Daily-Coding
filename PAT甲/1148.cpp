/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
const int maxn = 101;

int main(int argc, char *argv[])
{
	int N;
	int ft[maxn];
	int say[maxn] = {0};
	vector<int>lie;
	
	cin>>N;	
	for(int i = 1; i<=N; i++)
		cin>>say[i];	
	for(int i = 1; i<=N; i++)
	{
		for(int j = i+1; j<=N; j++)
		{
			fill(ft, ft+N+1, 1);
			ft[i] = ft[j] = -1;
			for(int k = 1; k<=N; k++)
				if(say[k]*ft[abs(say[k])]<0) lie.push_back(k);
			if(lie.size()==2&&ft[lie[0]]+ft[lie[1]]==0){
				cout<<i<<' '<<j;
				return 0;
			}				
			lie.clear();
		}		
	}
	cout << "No Solution";
	return 0;
}




