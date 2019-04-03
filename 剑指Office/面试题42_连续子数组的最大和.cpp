/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    	if( array.size() == 0 )
    		return 0;
   		int curSum = 0;
   		int maxSum = INT_MIN;
   		for( int i = 0; i < array.size(); ++i ) {
			if( curSum <= 0 )
				curSum = array[ i ];
			else curSum += array[ i ];
			if( curSum > maxSum )
				maxSum = curSum;
	   }
		return maxSum;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}