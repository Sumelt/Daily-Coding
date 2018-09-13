/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 09/09/18 21:31

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int mypow;
	int x,y;
	int jia,yi;
	int temp = 0;
	double bin;
	bool flag = false;
	
	cin>>mypow>>x>>y;
	for(int i = 10; i<100; i++)
	{
		jia = i;
		yi = jia%10*10+jia/10;
		bin = yi*1.0/y;
		if(abs(jia-yi)==x*bin)
		{
			flag = true;
			temp = i;
		}
	}
	if(flag)
	{
		jia = temp;
		yi = jia%10*10+jia/10;
		bin = yi*1.0/y;
		cout<<jia<<' ';
		
		if(mypow<jia) cout<<"Cong";
		else if(mypow==jia) cout<<"Ping";
		else cout<<"Gai";
		cout<<' ';
		
		if(mypow<yi) cout<<"Cong";
		else if(mypow==yi) cout<<"Ping";
		else cout<<"Gai";
		cout<<' ';
		
		if(mypow<bin) cout<<"Cong";
		else if(mypow==bin) cout<<"Ping";
		else cout<<"Gai";
		
	}
	else cout<<"No Solution";
	return 0;
}




