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

using namespace std;

int main(int argc, char *argv[])
{
	int n, current = 0;
	int array[100];
	int time[2] = {6, 4};
	int cost = 0;
	cin>>n;
	
	for(int i = 0; i<n; i++)
		cin>>array[i];
	
	for(int i = 0; i<n; i++)
	{
		if(array[i]-current>=0){
			cost += (array[i]-current)*time[0]+5;
			current = array[i];
		}
		else{
			cost += abs(array[i]-current)*time[1]+5;
			current = array[i];
		}	
	}
	cout<<cost;
	
	return 0;
}




