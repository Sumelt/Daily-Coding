/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int a[5] = {1,2,3,4,5};
	memset(a, -1, sizeof(a)) ;
	for(int i = 0; i<5; i++)
		cout<<*(a+i);
	return 0;
}




