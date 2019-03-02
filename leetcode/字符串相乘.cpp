/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;

string multiply(string num1, string num2) {
	int num1Length = num1.size(), num2Length = num2.size();
	vector<int>array( num1Length + num2Length, 0 );
	forward_list<int>ls;
	string str;
	int j = 0, resIndex = 0;
	for( int i = 0; i < num1Length; ++i )
		for( j = 0, resIndex = i; j < num2Length; ++j, ++resIndex )
			array[ resIndex ] += ( num1[ i ] - '0' ) * ( num2[ j ] - '0' );
	 for( int i = resIndex - 1; i > 0; --i ) {
 		array[ i - 1 ] += array[ i ] / 10;
 		ls.insert_after( ls.before_begin(), array[ i ] % 10  );
 	}
 	ls.insert_after( ls.before_begin(), array[ 0 ] );
	while( !ls.empty() && ls.front() == 0 ) ls.pop_front();
 	if( ls.empty() ) return "0";
 	else {
	 	for( auto start = ls.begin(); start != ls.end(); ++start )
	 		str += to_string( *start );	 		
	 }
 	return str;
}

int main(int argc, char *argv[])
{
	cout << multiply( "9999", "9" );
	return 0;
}