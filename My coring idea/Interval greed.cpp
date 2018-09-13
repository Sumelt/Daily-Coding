/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string.h>

using namespace std;
#define max 100

struct interval{
	int x;  //zuo
	int y;  //you
}inval[max];

int cmp(struct interval a, struct interval b)
{
	if(a.x!=b.x) return a.x>b.x;
	else return a.y < b.y;
}

int main(int argc, char *argv[])
{
	int n;
	while(scanf("%d",&n)&&n!=0)
	{
		for(int i = 0; i<n; i++)
			scanf("%d%d",&inval[i].x,&inval[i].y);
	
		sort(inval,inval+n,cmp);
		int ans = 1, lastx = inval[0].x;
		for(int i = 1; i<n; i++)
		{
			if(inval[i].y<= lastx)
			{
				lastx = inval[i].x;
				ans++;
			}
				
		}
		printf("%d\n",ans);
	}
	return 0;
}




