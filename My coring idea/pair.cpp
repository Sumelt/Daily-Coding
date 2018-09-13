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
#include <utility>

using namespace std;

int main(int argc, char *argv[])
{
//	pair<string ,int> p;
//	p.first = "hello";
//	p.second = 425;
//	
//	pair<int,int>p2(480,500);
//	
//	pair<string,string>("go","it");
//	make_pair("haha","test");
//	
//	cout<<p.first<<' '<<p.second;
	
	map<string, int>mp;
	mp.insert(make_pair("myworld", 800));
	mp.insert(pair<string, int>("SU", 520));

	for(map<string, int>::iterator it = mp.begin(); it!=mp.end(); it++)
		cout<<it->first<<' '<<it->second;
		
	return 0;
}




