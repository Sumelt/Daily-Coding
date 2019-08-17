/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
//#include<bits/stdc++.h>
#include <vector>
#include <cassert>
using namespace std;

class Base {
private:

public:

};

vector<vector<int>>res;
void function( int head, int sum, vector<int>ary, vector<int> value ) {
	if( sum < 0 || ary.size() == 0 && sum != 0 )
		return;
	if( sum == 0 ) {
		value.push_back( head );
		res.push_back( value );
		return;
	}
		
	value.push_back( head );
	
	for( int index = 0; index < ary.size(); ++index ) {
		if( ary[ index ] > sum ) break;
		else 
			function( ary[ index ], sum - ary[ index ],
				vector<int>( ary.begin() + index + 1, ary.end() ), value );
	}	
}

int main(int argc, char *argv[])
{
	int n, m;
	vector<int>array;
	
	cin >> n >> m;
	
	for( int i = 1; i <= n; ++i )
		array.push_back( i );
		
	for( int index = 0; index < n; ++index ) {
		if( array[ index ] > m ) break;
		else function( array[ index ], m - array[ index ], 
			vector<int>( array.begin() + index + 1, array.end() ), vector<int>() );
	}
	
	for( auto vec : res ) {
		for( int i = 0; i < vec.size(); ++i )
			if( i != vec.size() - 1 )
				cout << vec[ i ] << ' ';
			else cout << vec[ i ];
		cout << endl;
	}
	
	return 0;
}