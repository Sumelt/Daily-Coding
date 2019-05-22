/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>mp;
        for( int i = 0; i < nums.size(); ++i ) {
        	int diff = target - nums[ i ];
        	if( mp.count( diff ) != 0 )
        		return vector<int>{ mp[ diff ], i };
       		mp[ nums[ i ] ] = i;
        }
        return vector<int>();
    }
};

int main(int argc, char *argv[])
{
	map<int, int>mp;
	cout << mp[ 2 ];
	return 0;
}