/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if( array.size() == 0 )
        	return vector<int>();
       	int aheadPtr = 0; //前指针
       	int behindPtr = array.size() - 1; //后指针
       	
       	while( aheadPtr < behindPtr ) {
	    	if( array[ aheadPtr ] + array[ behindPtr ] > sum ) //和比目标数大
	    		--behindPtr;//后指针前移
    		else if( array[ aheadPtr ] + array[ behindPtr ] < sum ) //和比目标数小
    			++aheadPtr;//前指针后移
   			else break;//相等
    	}
    	if( aheadPtr < behindPtr ) { //判断是否正确的跳出条件
	    	vector<int> res = { array[ aheadPtr ], array[ behindPtr ] };
	    	return res;
	    }
    	else return vector<int>();
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}