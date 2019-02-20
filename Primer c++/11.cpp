/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
	auto p = make_pair( "Hello", 88 );
	map<string, int> mp;
	mp.insert( p );
	return 0;
}




