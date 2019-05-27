/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
private:
public:
    int numSquares(int n) {
        assert( n > 0 );
       	bool visted[ n + 1 ] = { 0 };
       	queue<pair<int, int>>que;
       	
       	que.push( make_pair( n, 0 ) );
       	visted[ n ] = true;
       	
       	while( !que.empty() ) {
	    	int number = que.front().first;
	    	int step = que.front().second;
	    	que.pop();
	    		    		
    		for( int i = 1; ; i++ ) {
		    	int diff = number - pow( i, 2 );
		    	if( diff < 0 )
		    		break;
		    	if( number == 0 )
	    			return step + 1;
	    		if( !visted[ diff ] ) {
		    		que.push( make_pair( diff, step + 1 ) );
		    		visted[ diff ] = true;
		    	}
		    }	
    	}
    	return 0;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}