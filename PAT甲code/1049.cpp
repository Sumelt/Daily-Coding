/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 12/09/18 16:09

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	map<long,vector<long> >mp;
	int n,m;
	int key,value;
	bool flag = true;
	vector <long> array;
	cin>>n>>m;
	
	for(int i = 0; i<n; i++)
	{
		cin>>key>>value;
		mp[key].push_back(value);
	 	mp[value].push_back(key);
	}
	int count;
	long temp;
	for(int i = 0; i<m; i++)
	{
		cin>>count;
		for(int i = 0; i<count; i++)
		{
			cin>>temp;
			array.push_back(temp);
		}			
		for(int j = 0; j< count; j++)
		{
			if(mp[array[j]].size()>0)
				{
					for(int k = 0; k<mp[array[j]].size(); k++)
					{
						for(int l = 0; l<array.size(); l++)
						{
							if(mp[array[j]][k]==array[l])
							{
								cout<<"No\n";
								flag = false;
								break;
							}
								
						}
						if(!flag) break;
					}
				}
			if(!flag) break;
		}
		if(!flag) {
			flag = true;
		}
		else cout<<"Yes\n";
		array.clear();
	}	
	return 0;
}





