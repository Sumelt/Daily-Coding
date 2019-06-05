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
    int singleNumber(vector<int>& nums) {
        int res;
        for( auto value : nums )
        	res ^= value;
       	return res;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}