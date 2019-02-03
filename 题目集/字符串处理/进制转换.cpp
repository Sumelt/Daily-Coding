/*----------------------------------------------------------------

* @Author: Su

* @Description: A->1 AA->27 27->AA 1->A

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;

string convertToTitle( int num )
{
	string res;
	
	while( num != 0){
		--num;
		int remain = num % 26;
		res = ( char )( 'A' + remain ) + res;
		num /= 26;
	}
	
	return res;
}

int convertToNub( string str )
{
	int res = 0;
	int base = 26;
	for( int i = 0; i < str.length(); ++i )
	{
		res =  ( str[ i ] - 'A' + 1 ) + res * 26;
	}
	return res ;
}

int main(int argc, char *argv[])
{
	cout << convertToTitle( 27 ) << endl;
	cout << convertToNub( "AAA" ) << endl;
	return 0;
}




