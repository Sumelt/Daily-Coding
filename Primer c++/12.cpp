/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <memory>
#include <vector>
#include <initializer_list> 
#include <string>
using namespace std;

class p{
	public :
		p( const string &str ) : mystr( str ){
			
		}
	string mystr;	
};

int b( int value )
{
	return value;
}

void Print( int a, int p( int value ) )
{
	cout << p( a );
}




int main(int argc, char *argv[])
{
	//auto ptr = make_shared<int>(42);
	//auto tmp = ptr.get();
	
	//auto ptr = make_shared<int>(42);
	//shared_ptr<int> r( new int(42) );
	
	//cout << ptr << ' ' << *ptr << endl; // 0xa914f0 0
	//delete ptr;
	//cout << *ptr; // 11098592
	p pk( string("HELLO") );
	return 0;
}