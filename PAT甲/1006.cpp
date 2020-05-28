/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 17/09/18 12:45

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string>

using namespace std;

typedef struct info{
	string id;
	string sgin;
	string sgout;
}infos;

bool incmp(infos a, infos b){
	return (a.sgin < b.sgin);
}

bool outcmp(infos a, infos b){
	return (a.sgout > b.sgout);
}

int main(int argc, char *argv[])
{
	int n;
	string str;
	cin>>n;
	cin.get();
	infos info[n];
	
	for(int i = 0; i<n; i++)
	{
		cin>>info[i].id>>info[i].sgin>>info[i].sgout;
		cin.get();
	}
	sort(info,info+n,incmp);
	str.clear();
	str = info[0].id;
	str+=" ";
	sort(info,info+n,outcmp);
	str+=info[0].id;
	cout<<str;
	return 0;
}




