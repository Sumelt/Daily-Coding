/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <set>
using namespace std;
int main(int argc, char *argv[])
{
	set <int> array;
	array.insert(2);
	array.insert(6);
	array.insert(3);
	array.insert(4);
	array.erase(array.begin(),array.find(3));
	array.erase(6);
	for(set <int>::iterator it = array.begin();it!=array.end();it++)
		cout <<*it <<' ';
	cout <<endl <<*array.find(3);
	cout <<endl <<array.size();
	
	return 0;
}

