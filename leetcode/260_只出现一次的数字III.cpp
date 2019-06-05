/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int allAndRes = 0;
        allAndRes = accumulate( nums.begin(), nums.end(), 0, bit_xor<int>() );
		allAndRes &= -allAndRes;
		
  		vector<int>res( 2, 0 );
  		for( auto value : nums )
  			if( ( value & allAndRes ) == allAndRes )
  				res[ 1 ] ^= value;
			else res[ 0 ] ^= value;
		
		return res;
    } 
};

int main(int argc, char *argv[])
{
	
	return 0;
}