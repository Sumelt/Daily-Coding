/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 03/09/18 20:08

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string.h>

using namespace std;
#define max 100

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

void sortmeg(int a[],int left, int right)
{
	int min = (left+right)/2;
	if(left<right)
	{
		sortmeg(a,left,min);
		sortmeg(a,min+1,right);
		merge(a, left, min, min+1, right);
	}
}


int main(int argc, char *argv[])
{
	
	return 0;
}




