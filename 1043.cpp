/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 01/09/18 18:38

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
	string str;
	int mymax = 0;
	cin>>str;
	int array[6];
	array[0] = count(str.begin(),str.end(),'P');
	array[1] = count(str.begin(),str.end(),'A');
	array[2] = count(str.begin(),str.end(),'T');
	array[3] = count(str.begin(),str.end(),'e');
	array[4] = count(str.begin(),str.end(),'s');
	array[5] = count(str.begin(),str.end(),'t');
	for(int i =0; i<6; i++)
		mymax = max(array[i],mymax);
	while(mymax-->0)
	{
		if(array[0]>0) {
			cout<<'P';array[0]--;
		}
		if(array[1]>0) {
			cout<<'A';array[1]--;
		}
		if(array[2]>0) {
			cout<<'T';array[2]--;
		}
		if(array[3]>0) {
			cout<<'e';array[3]--;
		}
		if(array[4]>0) {
			cout<<'s';array[4]--;
		}
		if(array[5]>0) {
			cout<<'t';array[5]--;
		}
	}
	return 0;
}




