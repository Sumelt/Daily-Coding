/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 14/09/18 16:29

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string>
#include <cstring>

using namespace std;

map<int,char>inmp(map<int,char>mp)
{
	mp[0] = '1';
	mp[1] = '0';
	mp[2] = 'X';
	mp[3] = '9';
	mp[4] = '8';
	mp[5] = '7';
	mp[6] = '6';
	mp[7] = '5';
	mp[8] = '4';
	mp[9] = '3';
	mp[10] = '2';
	return mp;
}

int main(int argc, char *argv[])
{
	
	
	map<int,char>mp;
	mp = inmp(mp);
	int count;
	int b[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	
	cin>>count;
		
	char array[count][18];
	memset(array,0,sizeof(array));
	
	bool flag[count];
	fill(flag,flag+count,1);	
	unsigned res[count] = {0};
	
	for(int j =0; j<count; j++)
	{
		for(int i =0; i<18; i++)
		{
			cin>>array[j][i];
			if(i<17)
			{
				if(array[j][i]<'0'||array[j][i]>'9')
					{
						flag[j] = false;
						//cout<<"test"<<array[j][i]<<'-';
					}
				else
					res[j]+=((array[j][i]-'0')*b[i]);
			}
			
		}
		if(flag[j])
		{
			res[j] = res[j]%11;
			if(mp[res[j]]!=array[j][17])
				flag[j] = false;
		}
	}
	bool ltfg = true;
	for(int i =0; i<count; i++)
	{
		
		if(!flag[i])
		{
			ltfg = false;
			for(int j =0; j<18; j++)
				cout<<array[i][j];
			cout<<endl;
		}
	}
	if(ltfg) cout<<"All passed"<<endl;
	return 0;
}
