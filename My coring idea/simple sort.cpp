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

using namespace std;

void simple_sort(int a[],int length)
{
	int temp2,temp;
	int j, k;
	for(int i = 0; i<length; i++)
	{	temp = a[i];
		k  = i;
		for( j = i; j<length; j++)
		{
			if(a[j]<temp)
			{
				temp = a[j];
				k = j;
			}			
		}
		temp2 = a[i];
		a[i] = temp;
		a[k] = temp2;		
	}
 } 

int main(int argc, char *argv[])
{
	int a[10]={3, 1, 2, 8, 7, 5, 9, 4, 0, 6};
	simple_sort(a,10);
	for(int i =0;i<10;i++)
		cout<<a[i]<<' '; 
	return 0;
}




