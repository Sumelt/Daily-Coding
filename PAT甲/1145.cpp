/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

bool judgePrime(int n)
{
	double j = sqrt(n*1.0);
	
	for(int i = 2; i<=(int)j; i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	int size, count, keyn;
	
	cin >>size >>count >>keyn;
	
	while(!judgePrime(size))
		size++;
	
	vector<int>hash(size, -1);
	int number;	
	for(int i = 0; i<count; i++)
	{
		cin >>number;
		bool flag = false;
		for(int i = 0; i<size; i++)
		{
			int post = (number + i*i)%size;
			if(hash[post]==-1){
				hash[post] = number;
				flag = true;
				break;
			}				
		}
		if(!flag)
			cout <<number <<" cannot be inserted.\n";
	}
	
	int key, Nser = 0;
	for(int i = 0; i<keyn; i++)
	{
		int ser = 0;
		cin >>key;
		for(int j = 0; j<size; j++)
		{
			int post = (key + j*j)%size;
			if(hash[post]==key||hash[post]==-1){
				ser++;
				break;				
			}
			ser++;
			if(j==size-1) ser+=1;
		}		
		Nser+=ser;
	} 
	printf("%.1f", Nser*1.0/keyn);
	return 0;
}

