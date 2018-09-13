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
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	unsigned  a, b;
	unsigned res;
	bool flag = false;
	scanf("%d%d",&a, &b);
	res = a*b;
	string str =  to_string(res);
	 for(string:: iterator it = str.end()-1; it!=str.begin()-1; it--)
	 {
	 	if(*it=='0')
	 	{
	 		if(flag)
	 			cout<<*it;	 		
		}
	 	else
		{
		 	cout<<*it;
			flag = true;
		} 	 	
	 }
	 	
	return 0;
}




