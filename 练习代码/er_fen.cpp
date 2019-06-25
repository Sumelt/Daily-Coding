/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 03/09/18 13:49

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string.h>

using namespace std;


int judge(int array[],int left, int right, int x)
{
	int min ;
	while(left<right)
	{
		min = (left+right)/2;
		if(min>=x) right = min;
		else left = min+1;
	}
	
	return left;
}

int main(int argc, char *argv[])
{
	int n,aim;
	cout<<"input number count :";	
	cin>>n;
	int array[n];
	
	cout<<endl<<"input number :";
	for(int i = 0; i<n; i++)
		scanf("%d",array+i);
		
	cout<<endl<<"input you aim number :";
		cin>>aim;
	
	cout<<judge(array,0,n,aim);
	
	return 0;
}




