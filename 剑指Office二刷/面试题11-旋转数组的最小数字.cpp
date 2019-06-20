/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int prIndex = 0, lastIndex = rotateArray.size() - 1;
        int midIndex = prIndex + ( ( lastIndex - prIndex ) >> 1 );
        
        //数组原本就为有序的 
        if( rotateArray[ prIndex ] < rotateArray[ lastIndex ] )
        	return rotateArray[ prIndex ];
        //结束条件为位置相差1
        while( lastIndex - prIndex != 1 ) {
        	//三个位置的元素都相等转为顺序遍历数组 
			if( rotateArray[ prIndex ] == rotateArray[ lastIndex ] && 
				rotateArray[ prIndex ] == rotateArray[ midIndex ] ) {
					int minNumber = rotateArray[ prIndex ];
					for( int i = prIndex + 1; i <= lastIndex; ++i  )
						minNumber = min( minNumber, rotateArray[ i ] );//求得最小的元素
					return minNumber;
			}
			//最小元素位于之后		
			if( rotateArray[ midIndex ] >= rotateArray[ prIndex ] )
				prIndex = midIndex;//这里直接把中间位置赋给前一个指针
			//最小元素位于之前 
			else if( rotateArray[ midIndex ] <= rotateArray[ lastIndex ]) 
				lastIndex = midIndex;//中间位置赋给后指针
			//更新中间值
            midIndex = prIndex + ( ( lastIndex - prIndex ) >> 1 );
        }
        
        return rotateArray[ lastIndex ];
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}