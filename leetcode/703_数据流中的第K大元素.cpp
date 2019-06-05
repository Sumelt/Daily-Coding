/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <queue>
using namespace std;

class KthLargest {
private:
	priority_queue<int, vector<int>, greater<int>>pque;
	int kMax;
public:
    KthLargest(int k, vector<int>& nums) {
       kMax = k;
	   for( int i = 0; i < nums.size(); ++i ) {
   			if( pque.size() == kMax && nums[ i ] > pque.top() ) {
				pque.pop();
			   	pque.push( nums[ i ] );
	   		}
	   		else if( pque.size() < kMax )
	   }			
    }
    
    int add(int val) {
    	if( pque.size() < kMax )
    		pque.push( val );
   		else {
   			if( val > pque.top() ) {
	        	pque.pop();
	        	pque.push( val );
     		}		   	
	   }	
        return pque.top();
    }
};


int main(int argc, char *argv[])
{
	vector<int>vec = { 2, 5, 3, 1, 8, 7 };
	KthLargest oj( 3, vec );
	
	cout << oj.add( 10 ) << endl;
	return 0;
}