/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if( input.size() == 0 || k == 0 || k > input.size() )
        	return vector<int>();
       	set<int>savKnumber;//保存K个元素的容器
       	for( int i = 0; i < input.size(); ++i ) {
	    	if( savKnumber.size() != k )//先保存K个元素
	    		savKnumber.insert( input[ i ] );
    		else if( input[ i ] < *savKnumber.rbegin() ) {//比较最大元素
		    	savKnumber.erase( *savKnumber.rbegin() );//删除最大的元素
    			savKnumber.insert( input[ i ] );	//插入该元素
		    }  			
    	}
        return vector<int>( savKnumber.begin(), savKnumber.end() );
    }
};
int main(int argc, char *argv[])
{
	
	return 0;
}