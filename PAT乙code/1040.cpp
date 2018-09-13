/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 04/09/18 21:06

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string.h>

#define maxmod 1000000007 

using namespace std;

int main(int argc, char *argv[])
{
	string str;
	cin>>str;
	
	int nump[100000] = {0};
	int numt = 0;
	int ans = 0;
	int i;
	for( i = 0; i<str.length(); i++)
	{
		if(i>0)nump[i] = nump[i-1];	
		if(str[i]=='P')
			nump[i]+=1;		
	}
	
	for( i = str.length()-1; i>=0; i--)
	{
			
		if(str[i]=='T')
			numt+=1;
		if(str[i]=='A') ans = (ans+ nump[i]*numt)%maxmod;
	}
	printf("%d",ans%maxmod);
	return 0;
}




