/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 30/08/18 11:06

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string.h>

using namespace std;

int mycmp(int a,int b)
{
	if(a<b) return 1;
	else return 0;
}

int main(int argc, char *argv[])
{
	int a[4] = {2,6,1,0};
	vector <int> array;
	array.push_back(2);
	array.push_back(1);
	array.push_back(9);
	cout<<max(a[0],a[2])<<endl;
	cout<<max(a[0],max(a[1],a[2]));
	
	cout<<endl<<min(a[0],a[3]);
	
	swap(a[0],a[3]);
	cout<<endl;
	cout<<a[0]<<" "<<a[3];
	
	reverse(a,a+4);
	cout<<endl;
	for(int i = 0;i<4;i++)
		cout<<a[i]<<" ";
	reverse(array.begin(),array.end());
	cout<<endl;
	for(vector<int>::iterator it = array.begin();it!=array.end();it++)
		cout<<*it<<' ';
		
	do{
		cout<<endl;
		cout<<a[0]<<a[1]<<a[2]<<a[3]<<endl;
	}while(next_permutation(a,a+4));
	cout<<endl;
	fill(a,a+2,0);
	cout<<a[0]<<" "<<a[1];
	sort(a,a+4,mycmp);
	cout<<endl;
	for(int i = 0;i<4;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	sort(a,a+4,mycmp);
	for(int i = 0;i<4;i++)
		cout<<a[i]<<" ";
		cout<<endl;
	int * b = lower_bound(a,a+4,6); //¶þ·Ö²éÕÒ 
	cout<<b-a;
	
	return 0;
}



