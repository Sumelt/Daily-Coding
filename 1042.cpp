/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 01/09/18 17:52

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
	string str;
	char c;
	int max = 0,temp = 0;
	set<char>strset;
	getline(cin,str);
	transform(str.begin(),str.end(),str.begin(),::tolower);

	for(int i = 0; i<str.size(); i++)
		strset.insert(str[i]);
	for(set<char>::iterator it = strset.begin();it!=strset.end();it++)
	{
		if(*it>='a'&&*it<='z')
		{
			temp = count(str.begin(),str.end(),*it);
			if(temp>max)
				{
					max = temp;
					c = *it;
				}
		}
			
	}
	cout<<c<<' '<<max;
	return 0;
}




