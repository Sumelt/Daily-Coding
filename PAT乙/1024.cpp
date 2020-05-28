/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <math.h>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	string str;
	int count = 0;
	int zcount = 0;
	bool resig = true;
	bool tensig = true;
	cin>>str;
	if(str[0]!='+') resig = false;
	for(int i = 3; str[i]!='E'; i++)
		count++;
	if(str[3+count+1]!='+') tensig = false;
	string temp;
	temp.insert(temp.begin(), str.begin()+(count+5), str.end());
	zcount = atoi(temp.c_str());
	if(!resig) cout<<'-';
	
	if(tensig)
	{
		cout<<str[1];
		if(zcount>=count)
		{
			for(int i =0; i<count; i++)
				cout<<str[3+i];
			for(int j =0; j<zcount-count; j++)
				printf("0");
		}
		else
		{
			for(int i =0; i<count; i++){
				cout<<str[3+i];
				if(i==zcount-1)
					printf(".");
			}				
		}		
	}
	else{
		for(int j =0; j<=zcount; j++)
		{
			if(j==1)
				printf(".");
			else printf("0");
		}
		cout<<str[1];
		for(int i =0; i<count; i++)
			cout<<str[3+i];
	}
	return 0;
}




