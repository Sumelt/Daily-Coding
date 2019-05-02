/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto i = 0; if( nums.size() == 0 ) return 0;
        for( auto index = 1; index < nums.size(); ++index )
        {
            if( nums[ index ] != nums[ i ] ){ //核心思想，同时也保存下来着不重复的项
                ++i;
                nums[ i ] = nums[ index ];
            }
        }
        return i + 1;
    }
    
};

int main(int argc, char *argv[])
{
	
	return 0;
}