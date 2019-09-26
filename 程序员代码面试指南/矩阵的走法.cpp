/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
	int find( vector<vector<int>>& grid ) {
		int dp[ grid.size() ][ grid[ 0 ].size() ] = { { 0 } };
		//第一行的元素走法都为1
		for( int col = 0; col < grid[ 0 ].size(); ++col )
			dp[ 0 ][ col ] = 1;
		//第一列的元素走法都为1
		for( int row = 0; row < grid.size(); ++row ) 
			dp[ row ][ 0 ] = 1;
			
		for( int row = 1; row < grid.size(); ++row ) {
			for( int col = 1; col < grid[ 0 ].size(); ++col )
				dp[ row ][ col ] = dp[ row - 1 ][ col ] + dp[ row ][ col - 1 ];
		}
		return dp[ grid.size() - 1 ][ grid[ 0 ].size() - 1 ];
	}

public:
    int pathCount(vector<vector<int>>& grid) {
        if( grid.size() == 0 || grid[ 0 ].size() == 0 )
        	return 0;
       	return find( grid );
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}