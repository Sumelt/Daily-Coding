/*----------------------------------------------------------------

* @Author: Su

* @Description: 04/09/18 19:50

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string.h>

using namespace std;

int part(int a[], int left, int right)
{
	int temp= a[left];
	while(left<right)
	{
		while(right>left&&a[right]>=temp) right--;
			a[left] = a[right];
		while(left<right&&a[left]<=temp) left++;
			a[right] = a[left];
		
	}	
	if(left==right)
		a[left] = temp;
	return left;
}

void qsort(int a[], int left, int right)
{
	if(left<right)
	{
		int flag = part(a,left,right);
		qsort(a,left,flag-1);
		qsort(a,flag+1,right);
	}
	
	
}

int main(int argc, char *argv[])
{
	int a[10]={3, 1, 2, 8, 7, 5, 9, 4, 0, 6};
	qsort(a,0,9);
	for(int i =0;i<10;i++)
		cout<<a[i]<<' ';
	return 0;
}




