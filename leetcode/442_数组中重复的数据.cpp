/*----------------------------------------------------------------

* @Author: Su

* @Description: 
给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。

找到所有出现两次的元素。

你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-duplicates-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if( nums.size() == 0 )
        	return vector<int>();
        	
       	nums.push_back( 0 );
       	vector<int>res;
       	for( int i = 0; i < nums.size() - 1; ++i ) {
	    	int index = ( nums[ i ] >0 ? nums[ i ] : nums[ i ] * ( -1 ) );
	    	if( nums[ index	] > 0 )
    			nums[ index ] *= ( -1 );
	    	else res.push_back( index );
    	}
       	return res;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}