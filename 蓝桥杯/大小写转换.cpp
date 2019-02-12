/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	string str, res;
	cin >> str;
	for( string::iterator it = str.begin(); it != str.end(); ++it )
		if( *it >= 65 && *it <= 90 )
			res += tolower( *it );
		else res += toupper( *it );
	for( string::iterator it = res.begin(); it != res.end(); ++it )
		cout << *it;
	return 0;
}




