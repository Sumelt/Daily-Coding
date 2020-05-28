/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 28/09/18 17:23

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>


using namespace std;

int main(int argc, char *argv[])
{
	map<int,char> mp;
	double res = 1, nub;
	double inx, max = 0;
	char tep[3] = {0};
	mp[0] = 'W';
	mp[1] = 'T';
	mp[2] = 'L';
	
	for(int j =0; j<3; j++){
		for(int i =0; i<3; i++)
		{
			cin>>nub;
			if(max<nub){
				max = nub;
				inx = i;
			} 
		}
		res *= max; 
		tep[j] = mp[inx];
		max = 0;
	}
	for(int i=0; i<3; i++) cout<<tep[i]<<' ';
	res = (res*0.65-1)*2;
	printf("%.2f",res);
	return 0;
}




