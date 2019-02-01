/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <cassert>
#define NDEBUG
using namespace std;

void print(initializer_list<string> mes, ...)
{
	for( auto index : mes )
		cout <<index;
}

void t1( const int mes)
{
	
}
void t2( int mes)
{
	
}

const string &shorterString( const string &s1 = "Hello", 
								const string &s2 = "World" )
{
	return s1.size() <= s2.size() ? s1 : s2;
}

string &shorterString( string &s1, string &s2 )
{
	auto &r = shorterString( const_cast< const string& >( s1 ), 
		const_cast< const string& >( s2 ) );
	return const_cast< string& >( r );
} 

void myDebug()
{
	#ifndef NDEBUG
		cerr << __FILE__ << endl <<
		__LINE__ << endl << __TIME__ << endl << __DATE__;	
	#endif
}

bool lengthcmp( const string&, const string& );
bool (*pf)( const string&, const string& );

int main(int argc, char *argv[])
{
//	print( {"Hello", "Melt"}, 4 );
//	int array[2][2] = {1, 2, 3, 4};
//	decltype(array) myarray;
//	cout <<myarray[0][1];
//	int a = 2;
//	auto &array = const_cast<const int&>(a) ;
////	array = 3;
//	cout <<array;
	//assert(false);
	//myDebug();
	char *p1, *p2;
	char *array[] = {p1, p2};
	char str[] = "Hello";	
	array[0] = str;
	cout << array[0];
	return 0;
}




