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
	int temp;
	int inarray[100000];
	int out[100000];
	
	scanf("%d",&n);
	
	for(int i = 0; i<n; i++)
		scanf("%d",&inarray[i]);
	
	for(int i =0; i<n; i++)
	{
		temp = inarray[i];
		for( j = 0; j<n; j++)
		{			
			if(inarray[j]<=temp&&j<=i);
			else if(inarray[j]>temp&&j>i&&j<n);
			else break;
		}
		if(j==n)
		{
			count++;
			out[inx++] = inarray[i];
		}
	}
	cout<<count<<endl;
	sort(out,out+count);
	for(int i = 0; i<count; i++)
	{
		printf("%d",out[i]);
		if(i<count-1)
			putchar(' ');		
	}
	cout<<endl;	
	return 0;
}




