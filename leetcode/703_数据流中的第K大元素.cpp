/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <list>
using namespace std;

class KthLargest {
	list<int> array;
	int kMax;
public:
    KthLargest(int k, vector<int>& nums) { 
		//array = list<int>( nums.begin(), nums.end() );
		kMax = k;  	     
    }
    
    int add(int val) {
        make_heap( array.begin(), array.end() ); //排成最大堆 
		array.push_back( val );//元素插入 
		push_heap( array.begin(), array.end() ); //调整最大堆 
 		sort_heap( array.begin(), array.end(), 
		 		[]( int e1, int e2 )->bool { return e1 < e2;}  ); //从小到大排序 
		 		
		return array[ array.size() - kMax ];
    }
};

int main(int argc, char *argv[])
{
	vector<int>vec = { 2, 5, 3, 1, 8, 7 };
	KthLargest oj( 3, vec );
	
	cout << oj.add( 10 ) << endl;
	cout << oj.add( 12 );
	return 0;
}