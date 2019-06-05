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
private:
	
public:
    int singleNumber(vector<int>& nums) {
        int arrayBit[ 32 ] = { 0 };      
        for( auto value : nums ) {
            int andBit = 1;
        	for( int i = 31; i >= 0; --i ) {
        		if( ( andBit & value ) != 0 )
        			++arrayBit[ i ];
				andBit <<= 1;        	
	        }
        }
        int res = 0;
    	for( auto value : arrayBit ) {
	    	res <<= 1;    		
	    	res += ( value % 3 );
	    }
	    return res;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}