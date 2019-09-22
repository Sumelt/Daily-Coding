/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>
using namespace std;

class Mystring {
private:
	int length;
	char *str;
	void init( const char *s )  {		
		length = strlen( s );
		str = new char[ length + 1 ];
		strcpy( str, s );
		str[ length ] = '\0';		
	}
public:
	Mystring( const char * s ) {
		length = 0; str = nullptr;
		init( s );
	}
	
	Mystring( const Mystring& objString ) {
		cout << "call copy constucting function" << endl;
		length = objString.length;
		str = new char[ length + 1 ];
		strcpy( str, objString.str );
		str[ length ] = '\0';
	}
	Mystring& operator=( const Mystring& objString ) {
		cout << "call operator = function" << endl; 
		if( &objString == this )
			return *this;
		
		Mystring objTemp = objString;
		length = objTemp.length;
		swap( str, objTemp.str );
		
		return *this;
	}
	///----------------------
	Mystring( Mystring&& objString ) {
		cout << "call r_copy constucting function" << endl;
		
		length = objString.length;
		str = objString.str;//直接赋值即可 
		objString.length = 0;
		objString.str = nullptr;
	}
	
	Mystring& operator=	( Mystring&& objString ) {
		cout << "call r_operator = function" << endl; 
		if( &objString == this )
			return *this;
			
		length = objString.length;
		str = objString.str;//直接赋值即可 
		objString.length = 0;
		objString.str = nullptr;
		
		return *this;
	}
	
	void cot() {
		while( *str != '\0' )
			cout << *str++;
		cout << endl;
	}
};

int main(int argc, char *argv[])
{
	//Mystring objOne( "hello" );
	//objOne = Mystring( "world" );//抽走临时对象的资源 
	//objOne.cot();
	const int &a = 1;
	return 0;
}