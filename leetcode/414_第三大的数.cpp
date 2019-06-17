/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
private:
	priority_queue<int, vector<int>, greater<int>>pque;
public:
    int thirdMax(vector<int>& nums, int k = 3 ) {
        
        if( nums.size() < k) {
        	sort( nums.begin(), nums.end(), []( int a, int b )->bool{ return a > b; } ) ;
        	return nums[ 0 ] ;
		} 
        	
        for( auto value : nums )
        	if( pque.size() == k && pque.top() < value ) {
	        	pque.pop();
	        	pque.push( value );
	        }
	        else if( pque.size() < k )  {
	        	if( pque.size() == 0 )
	        		pque.push( value );
        		else if( pque.top() != value )
        			pque.push( value );
        	}			
		return pque.top();
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}