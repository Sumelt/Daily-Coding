/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

//剑指类似思路 
/* 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if( matrix.size() == 0 )
        	return false;
       	for( int row = matrix.size() - 1; row >= 0; --row ) {
	    	for( int col = 0; col < matrix[ row ].size(); ++col ) {
				if( matrix[ row ][ col ] == target )
					return true;
				if( matrix[ row ][ col ] > target ) break;//第一个数比目标数还大则换行 
			} 
    	}
        return false;  		      
    }
};
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if( matrix.size() == 0 || matrix[ 0 ].size() == 0 )
        	return false;
		
		int startIndex = 0;
		int endIndex = matrix.size() - 1;		
		
		while( startIndex <= endIndex ) {
			int midIndex = ( endIndex + startIndex ) >> 1;
			int colIndex = matrix[ midIndex ].size() - 1;//获取该行的最后一个数

			if( colIndex >= 0 && matrix[ midIndex ][ colIndex ] == target )
				return true;
				
			if( matrix[ midIndex ][ colIndex ] < target )
				startIndex = midIndex + 1;
			else if( matrix[ midIndex ][ colIndex ] > target ) {
				while( colIndex >= 0 && matrix[ midIndex ][ colIndex ] != target )
					--colIndex;
				if( colIndex >= 0 && matrix[ midIndex ][ colIndex ] == target )
					return true;
				else endIndex = midIndex - 1;
			}
		}
		return false;
    }
};


int main(int argc, char *argv[])
{
	
	return 0;
}