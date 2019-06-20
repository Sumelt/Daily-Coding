/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
//和153思路一样，这里处理了重复的元素 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int prIndex = 0, lastIndex = nums.size() - 1;
        int midIndex = ( prIndex + lastIndex ) >> 1;
        
        if( nums[ prIndex ] < nums[ lastIndex ] )
        	return nums[ prIndex ];
       	while( lastIndex - prIndex != 1 ) {
	    	if( nums[ prIndex ] == nums[ lastIndex ] &&
				nums[ lastIndex ] == nums[ midIndex ] ) {
				int midNumber = nums[ prIndex ];
				for( int i = prIndex + 1; i <= lastIndex; ++i )
					midNumber = min( midNumber, nums[ i ] );
				return midNumber;
			}
			if( nums[ midIndex ] >= nums[ prIndex ] )
				prIndex = midIndex;
			else lastIndex = midIndex;
			midIndex = ( prIndex + lastIndex ) >> 1;
    	}
        return nums[ lastIndex ];
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}