/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	int *array = nullptr;
	int count = 0;
	void findReverseOrder( vector<int> *&vecPtr, int leftIndex, int midIndex, 
		int rightIndex )
	{
		int leftLastIndex = midIndex;//左子序列的结束坐标
		int rightFrontIndex = midIndex + 1;//右子序列的首坐标
		int curIndex = rightIndex;//辅助空间的开始坐标
		int stopIndex = rightIndex;//辅助空间的结束坐标
        //归并思想
		while( leftIndex <= leftLastIndex && rightFrontIndex <= rightIndex ) {
			//满足逆序对条件
            if( ( *vecPtr )[ leftLastIndex ] > ( *vecPtr )[ rightIndex ] ) {
				count += ( rightIndex - rightFrontIndex + 1  );//该位置的前部分元素都满足
				array[ curIndex-- ] = ( *vecPtr )[ leftLastIndex-- ];
				if( count >= 1000000007 )
                    count %= 1000000007;
			}
			else array[ curIndex-- ] = ( *vecPtr )[ rightIndex-- ];			
		}
		
		while( leftIndex <= leftLastIndex )
			array[ curIndex-- ] = ( *vecPtr )[ leftLastIndex-- ];
		while( rightFrontIndex <= rightIndex )
			array[ curIndex-- ] = ( *vecPtr )[ rightIndex-- ];
		//辅助空间数组元素导入原数组空间
		for( ++curIndex; curIndex <= stopIndex; ++curIndex )
			( *vecPtr )[ curIndex ] = array[ curIndex ];			
	}

	void ReverseOrder( vector<int> *vecPtr, int leftIndex, int rightIndex ) {
		if( leftIndex >= rightIndex )
			return;
		int midIndex = ( leftIndex + rightIndex ) >> 1;
		ReverseOrder( vecPtr, leftIndex, midIndex );
		ReverseOrder( vecPtr, midIndex + 1, rightIndex );
		findReverseOrder( vecPtr, leftIndex, midIndex, rightIndex );
	}
public:
    int InversePairs(vector<int> data) {
		if( data.size() == 0 )
			return 0;
		array = new int[ data.size() ]();
		ReverseOrder( &data, 0, data.size() - 1 );
		delete []array;
		
		return count;
    }
};



int main(int argc, char *argv[])
{
	Solution oj;
	cout << oj.InversePairs( { 1,2,3,4,5,6,7,0} );
	return 0;
}