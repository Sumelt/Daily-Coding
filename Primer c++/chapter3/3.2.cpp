/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <string> 
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	string str( "Hello World!" );
//	for( decltype( str.size() )inx = 0; inx<str.size(); inx++ )
//		if( ispunct( str[inx] ) )
//			str.erase( str.begin()+inx );
//	cout <<str <<endl;
	//vector<string> vec(10); cout<<vec.size()<<endl;
	//vector<string> vec2{10}; cout<<vec2.size()<<endl;
	while(cin>>str)
		cout<<str<<endl;
	return 0;
}




