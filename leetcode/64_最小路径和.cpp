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

class Solution {
private:
	int find( vector<vector<int>>& grid ) {
		int dp[ grid.size() ][ grid[ 0 ].size() ] = { { 0 } };
		
		//第一行
		dp[ 0 ][ 0 ] = grid[ 0 ][ 0 ];
		for( int col = 1; col < grid[ 0 ].size(); ++col )
			dp[ 0 ][ col ] = dp[ 0 ][ col - 1 ] + grid[ 0 ][ col ];
		//第一列
		for( int row = 1; row < grid.size(); ++row )
			dp[ row ][ 0 ] = dp[ row - 1 ][ 0 ] + grid[ row ][ 0 ];
			
		for( int row = 1; row < grid.size(); ++row ) {
			for( int col = 1; col < grid[ 0 ].size(); ++col )
				dp[ row ][ col ] = \
					min( dp[ row - 1 ][ col ], dp[ row ][ col - 1 ] ) + grid[ row ][ col ];
		}
		return dp[ grid.size() - 1 ][ grid[ 0 ].size() - 1 ];
	}
	
	int findWithSpaceCompress( vector<vector<int>>& grid ) {
		int rows = grid.size(), cols = grid[ 0 ].size();
		int less = min( rows, cols );
		int more = max( rows, cols );
		bool standard = rows >= cols ? true : false;//判断是更新行还是列 
		
		int dp[ less ] = { 0 };
		dp[ 0 ] = grid[ 0 ][ 0 ];
		
		//计算第一列或者是第一行 
		for( int i = 1; i < less; ++i ) 
			dp[ i ] = dp[ i - 1 ] + ( standard ? grid[ 0 ][ i ] : grid[ i ][ 0 ] );
		
		for( int i = 1; i < more; ++i ) {
			dp[ 0 ] = dp[ 0 ] + ( standard ? grid[ i ][ 0 ] : grid[ 0 ][ i ] );
			for( int k = 1; k < less; ++k ) 
				dp[ k ] = ( standard ? grid[ i ][ k ] : grid[ k ][ i ] ) + 
					min( dp[ k ], dp[ k - 1 ] );
		} 
		return dp[ less - 1 ];
	} 
public:
    int minPathSum(vector<vector<int>>& grid) {
        if( grid.size() == 0 || grid[ 0 ].size() == 0 )
        	return 0;
       	return find( grid );
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}