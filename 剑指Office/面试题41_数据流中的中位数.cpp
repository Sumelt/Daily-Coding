/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
private:
	priority_queue<double>maxHeap;
	priority_queue<double, vector<double>, greater<double> >minHeap;
	int sumCount = 0;	
public:
    void Insert(int num)
    {
        //even 插入最小堆
        if( ( sumCount & 0x01 ) != 1  ) { 
        	if( !maxHeap.empty() && num <= maxHeap.top() ) {//如果要插入的数字比最大堆的还小
	        	maxHeap.push( num );
	        	minHeap.push( maxHeap.top() );
	        	maxHeap.pop();
	        }
        	else minHeap.push( num );
        	++sumCount;
        }
        //odd 插入最大堆
		else { 
			if( !minHeap.empty() && num >= minHeap.top()  ) //如果要插入的数字比最小堆的还大
			{
				minHeap.push( num );
				maxHeap.push( minHeap.top() );
				minHeap.pop();
			}
			else maxHeap.push( num );
			++sumCount;
		}
    }
    double GetMedian()
    { 
    	if( sumCount == 0 )	
    		return 0;
		if( sumCount & 0x01 == 1 )
    		return minHeap.top();
   		else 
			return ( maxHeap.top() + minHeap.top() ) / 2;
    }
};

int main(int argc, char *argv[])
{

	Solution oj;
	oj.Insert( 3 );
	cout << oj.GetMedian();
	//cout << ( 0 & 0x01 );
	return 0;
}