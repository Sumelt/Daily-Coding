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

//Merge Sort
#define max 100

void merge(int a[],int L1, int R1, int L2, int R2)
{
	int i = L1, j = L2;
	int temp[max]; int inx = 0;
	while(i<=R1&&j<=R2)
	{
		if(a[i]>a[j])
			temp[inx++] = a[j++];
		else temp[inx++] = a[i++];
	}
	while(i<=R1) temp[inx++] = a[i++];
	while(j<=R2) temp[inx++] = a[j++];
	for(int i = 0; i<inx; i++)
	 	{
	 		a[L1+i] = temp[i];
	 		//cout<<temp[i]<<' ';
		 }
		 //cout<<"******"<<endl;
//	for(int i =0; i<10; i++)		
//		cout<<a[i]<<" ";
//	cout<<endl;
}

void sortmeg(int a[],int left, int right)
{
	
	int min = (left+right)/2;
	//cout<<"min: "<<min<<' '<<"left: "<<left<<' '<<"right: "<<right<<endl;
	if(left<right)
	{
		sortmeg(a,left,min);
		sortmeg(a,min+1,right);
		cout<<left<<' '<<right<< ' '<<min<<endl;
		merge(a, left, min, min+1, right);
	}
}

int main(int argc, char *argv[])
{
	int a[10]={3, 1, 2, 8, 7, 5, 9, 4, 0, 6};
	//for(int i = 0; i<10; i++)
		//scanf("%d",a+i);
	sortmeg(a, 0, 9);
	//for(int i =0; i<10; i++)		
		//cout<<a[i]<<" ";
	//cout<<endl;
	return 0;
}




