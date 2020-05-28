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
	int n, j, count = 0 , inx = 0;
	char temp;
	string str;
	char out[100000];
	scanf("%d",&n);
	getchar();
	getline(cin,str);
	for(int i =0; i<str.length(); i++)
	{
		if(str[i]==' ')
			str.erase(str.begin()+i);		
	}
	for(int i =0; i<n; i++)
	{
		temp = str[i];
		for( j = 0; j<n; j++)
		{			
			if(str[j]<=temp&&j<=i);
			else if(str[j]>temp&&j>i&&j<n);
			else break;
		}
		if(j==n)
		{
			count++;
			out[inx++] = str[i];
		}
	}
	cout<<count<<endl;
	for(int i = 0; i<count; i++)
	{
		cout<<out[i];
		if(i<count-1)
			cout<<' ';
		
	}
		
	return 0;
}




