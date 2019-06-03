/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
private:
	deque<int>dque;
	vector<int>res;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       if( nums.size() == 0 ) 
      		return res;
  		//先填满滑动窗口
        for( int i = 0; i < k; ++i ) {
			  	while( !dque.empty() && nums[ dque.back() ] < nums[ i ] )
		  			dque.pop_back();
	  			dque.push_back( i );		  	
		  }
      	res.push_back( nums[ dque.front() ] );//滑动窗口填满后，压入窗口的最大值	
  		for( int i = k; i < nums.size(); ++i ) {
	//判断当前的队列的首元素是否已经滑出，当前处理的下标 - 队列首元素的下标 >= 窗口大小
	  		if( i - dque.front() >= k )
	  			dque.pop_front();
		  	while( !dque.empty() && nums[ dque.back() ] < nums[ i ] )
	  			dque.pop_back();
  			dque.push_back( i );
		  	res.push_back( nums[ dque.front() ] );//压入窗口的最大值
		}
		return res;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}