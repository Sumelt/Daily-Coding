/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if( array.size() == 0 )
        	return false;
       	for( int row = array.size() - 1; row >= 0; --row ) {
	    	for( int col = 0; col < array[ row ].size(); ++col ) {
				if( array[ row ][ col ] == target )
					return true;
				if( array[ row ][ col ] > target ) break;//第一个数比目标数还大则换行 
			} 
    	}
        return false;	
    }
};


class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if( array.size() == 0 )
        	return false;
       	int row = 0;
		for( int col = array[ 0 ].size() - 1; col >= 0; --col ) {
			for( ; row < array.size(); ++row ) {
				if( array[ row ][ col ] == target )
					return true;
				if( array[ row ][ col ] > target ) break; //换列 
			}
		}
		return false;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}