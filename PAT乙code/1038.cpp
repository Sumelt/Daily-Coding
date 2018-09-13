/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:01/09/18 15:38

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
	unsigned  count;
	int score; 
	map<int,int>mp;
	scanf("%d",&count);
	
	for(int i = 0; i< count; i++)
	{
		scanf("%d",&score);
		mp[score] +=1; 
	}
	scanf("%d",&count);
	
	for(int i = 0; i< count; i++)
	{
		scanf("%d",&score);
		cout<<mp[score];
		if(i<count-1)
		cout<<' ';
	}
	return 0;
}




