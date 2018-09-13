/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 09/09/18 21:06

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	bool array[100000] ={0};
	int N;
	int count = 0;
	unsigned res;
	scanf("%d",&N);
	for (int i = 1; i<=N; i++)
	{
		res = i/2 + i/3 + i/5;
		if(!array[res])
		{
			count++;
			array[res] = true;
		 } 
	}
	cout<<count;
	return 0;
}




