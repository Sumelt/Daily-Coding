/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
using namespace std;

class Solution {
private:
	priority_queue<int, vector<int>, greater<int>>pque;
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        if( nums.size() == 0 )
        	return 0;
       	
        for( auto value : nums )
        	if( pque.size() == k && pque.top() < value ) {
	        	pque.pop();
	        	pque.push( value );
	        }
	        else if( pque.size() < k ) pque.push( value );
        return pque.top();
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}