/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 05/09/18 12:29

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string.h>

using namespace std;

#define max 100

int a[max], n;
void insertsort(int a[], int n)
{
	for(int i = 1; i<n; i++)
	{
		int temp = a[i], j = i;
		while(j>0&&temp <a[j-1])
		{
			a[j] = a[j-1];
			j--;
		}
		a[j] = temp;
		temp;
	}
}

int main(int argc, char *argv[])
{
	int a[10]={3, 1, 2, 8, 7, 5, 9, 4, 0, 6};
	insertsort(a,10);
	for(int i =0;i<10;i++)
		cout<<a[i]<<' ';
	return 0;
}




