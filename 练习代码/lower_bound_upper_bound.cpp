/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 30/08/18 16:26

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
	int array[4] = {1,6,7,9};
	//int array2[5] = {3,4,8,7,6};
	cout<<lower_bound(array,array+4,6)-array<<endl;
	cout<<upper_bound(array,array+4,6)-array<<endl;
	return 0;
}



