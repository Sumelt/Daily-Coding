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
	int sumIndex;
	int sumRow;
	int sumCol;
	bool *visted;
	bool find( char* matrix, char* str, int strIndex, int row, int col ) {
		if( str[ strIndex ] == '\0' )
			return true;
			
		int curIndex = row * sumCol + col;
		bool res = false;
		
		if( curIndex <= sumIndex && curIndex >= 0 && 
			!visted[ curIndex ] && matrix[ curIndex ] == str[ strIndex ] )
	 	{			
			visted[ curIndex ] = true;
			res = find( matrix, str, strIndex + 1, row + 1, col ) ||
					find( matrix, str, strIndex + 1, row - 1, col ) ||
					find( matrix, str, strIndex + 1, row, col - 1 ) ||
					find( matrix, str, strIndex + 1, row, col + 1 );				
				
			if( !res ) {
				visted[ curIndex ] = false;
				return false;
			}			
		}
		return res;
	}
public:
    bool hasPath(char* matrix, int rows, int cols, char* str) {
    	if( matrix == nullptr || str == nullptr || rows < 1 || cols < 1 )
    		return false;
   		sumIndex = rows * cols - 1;
   		sumCol = cols;
   		sumRow = rows;
   		
   		visted = new bool[ sumIndex + 1 ]();
   		for( int r = 0; r < sumRow; ++r ) {
   			for( int c = 0; c < sumCol; ++c ) {
				if( !visted[ r * sumCol + c ] && find( matrix, str, 0, r, c ) )
					return true;
   			}		   
   		}
		return false;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}