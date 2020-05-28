/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:01/09/18 16:32

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
	map<char,int>pro;
	map<char,int>ned;
	int number = 0;
	bool flag = false;
	string strpro,strned;
 	set<char>setstr;
	set<char>setstrpro;
	 
	cin>>strpro;
	cin>>strned;
	
	for(int i =0;i<strpro.length();i++)
	{
		pro[strpro[i]]+=1;
		setstrpro.insert(strpro[i]);
	}
		
	for(int i =0;i<strned.length();i++)
		{
			ned[strned[i]]+=1;
			setstr.insert(strned[i]);
		}
	for(set<char>::iterator it = setstr.begin();it!=setstr.end();it++)
	{
		if(pro[*it]==0||ned[*it]>pro[*it])
			{
				number += ned[*it] - pro[*it];
				flag = true; //no 
			}
		else
				pro[*it]-=ned[*it];
	}
	
	if(!flag)
	{
		for(set<char>::iterator it =setstrpro.begin();it!=setstrpro.end();it++)
			number+=pro[*it];
		cout<<"yes"<<' '<<number;
	 }
	 else
	 	cout<<"no"<<' '<<number;
	return 0;
}




