/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		assert( k > 0 );
		if( nums.size() == 0 )
			return vector<int>();
		
		unordered_map<int, int>mp;//记录每一个元素的出现次数
		for( int i = 0; i < nums.size(); ++i )
			++mp[ nums[ i ] ];
		//构造一个最小堆，STL容器是按照键来排序的，所以把出现次数作为健，数字作为值
        //仿函数：greater：数字越大优先级越低
		priority_queue<pair<int, int>, vector<pair<int, int>>, 
								greater<pair<int, int >>>pque; //count - element
		for( unordered_map<int, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter ) {
			if( pque.size() == k ) {
                //新压入的元素出现的次数比堆顶元素出现的次数还大，更新堆顶
				if( iter->second > pque.top().first ) {
					pque.pop();
					pque.push( make_pair( iter->second, iter->first ) );
				}
			}
			else pque.push( make_pair( iter->second, iter->first ) );
		}
		
		vector<int>res;
		while( !pque.empty() ) {
			res.push_back( pque.top().second );
			pque.pop();
		}
		//由于是个最小堆，元素出现次数是按照从小到大，则必须来一个翻转	
		return vector<int>( res.rbegin(), res.rend() );
    }
};

int main(int argc, char *argv[])
{
	Solution oj;
	vector<int>vec = { 1,1,1,2,2,3 };
	vec = oj.topKFrequent( vec, 2 );
	for( auto value : vec )
		cout << value << ' ';
	return 0;
}