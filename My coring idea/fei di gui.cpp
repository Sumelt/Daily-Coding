/*----------------------------------------------------------------

* @Author: Su

* @Description: 04/09/18 09:46

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string.h>

using namespace std;

/*
void mergesort(int a[])
{
	for(int step = 2; step / 2 <=n; step *=2)
	{
		for(int i = 1; i <=n; i+=step)
		{
			int mid = i + step /2 -1;
			if(mid + 1 <= n)
				merge(a,i,mid,mid+1,min(i+step-1,n));
		}
	}
}
*/
/*
void merge(int a[],int L1, int R1, int L2, int R2)
{
	int i = L1, j = L2;
	int temp[max]; int inx = 0;
	while(i<=L1&&j<=L2)
	{
		if(a[i]>a[j])
			temp[inx++] = a[j++];
		else temp[inx++] = a[i++];
	}
	while(i<=L1) temp[inx++] = a[i++];
	while(j<=L2) temp[inx++] = a[j++];
}
*/
void mergesot(int a[],int n)
{
	int temp;
	for(int step = 2; step / 2 <= n; step*=2 )
		for(int i =1; i<=n; i+=step)
		{
			temp = min(i+step,n+1);
			sort(a+i,a+temp);
		}
			
}

int main(int argc, char *argv[])
{
	int a[6]={4,3,6,2,1,9};
	mergesot(a,6);
	for(int i = 0; i<6; i++)
		cout<<a[i]<<' ';
	return 0;
}




