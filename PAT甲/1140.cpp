/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int d, n = 0;
	int now = 1;
	string look, say;
	int j;
	
	cin >>d >>n;	
	look = d+'0';
	while(now!=n)
	{
		//cout<<look<<endl;
		for(int i = 0; i<look.size(); i = j){
			for(j = i; j<look.size()&&look[i]==look[j]; j++);						
			say+=to_string((look[i]-'0')*10+j-i);						
		}
		look = say;
		say.clear();		
		now++;	
	}
	cout<<look;
	return 0;
}

