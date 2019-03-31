/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	bool checkTime( vector<int> &numbers, int aimNumber ){
		int sumTime = 0;
		for( int i = 0; i < numbers.size(); ++i ) //检查该数字出现的次数
			if( numbers[ i ] == aimNumber )
				++sumTime;
		if( sumTime * 2 > numbers.size() )//出现次数过半的2倍一定大于数组长度
			return true;
		else return false;
	}
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	if( numbers.size() == 0 )
    		return 0;
   		int moreTimeNum = 0;//保存数值
   		int time = 0;//保存该数值的次数
   		
   		for( int i = 0; i < numbers.size(); ++i ) {
			if( time == 0 ) { //次数为0则保存当前的数字
				time = 1;//并置次数为1
				moreTimeNum = numbers[ i ];	
			}
			else if( moreTimeNum == numbers[ i ] )//它们相同
				++time;
			else --time;//它们不同
	   }
        //出现次数过半的数字，一定是最后一次把次数设置为1的数字
		if( time >= 1 && checkTime( numbers, moreTimeNum ) )
			return moreTimeNum;
		else return 0;
    }
};

class Solution2 {
private:
	int getKeyIndex( vector<int> &numbers, int leftIndex, int rightIndex ) {
		int keyIndex = leftIndex;
		int keyValue = numbers[ keyIndex ];
		
		while( leftIndex < rightIndex ) {
			while( leftIndex < rightIndex && numbers[ rightIndex ] >= keyValue )
				--rightIndex;
			while( leftIndex < rightIndex && numbers[ leftIndex ] <= keyValue )
				++leftIndex;
			if( leftIndex < rightIndex )
				swap( numbers[ leftIndex ], numbers[ rightIndex ] );
			else break;
		}
		swap( numbers[ leftIndex ], numbers[ keyIndex ] );
		return leftIndex;
	}
	bool checkTime( vector<int> &numbers, int aimNumber ){
		int sumTime = 0;
		for( int i = 0; i < numbers.size(); ++i ) //检查该数字出现的次数
			if( numbers[ i ] == aimNumber )
				++sumTime;
		
		if( sumTime * 2 > numbers.size() )//出现次数过半的2倍一定大于数组长度
			return true;
		else false;
	}
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	if( numbers.size() == 0 )
    		return 0;
   		int midIndex = numbers.size() >> 1;
   		int keyIndex = 0, leftIndex = 0, rightIndex = numbers.size() - 1;
   		
   		while( true	) {
			keyIndex = getKeyIndex( numbers, leftIndex, rightIndex );
			if( keyIndex == midIndex )
				break;
			
			if( keyIndex > midIndex )
				rightIndex = keyIndex - 1;
			else leftIndex = keyIndex + 1;
			
	   	}
	   	
   		if( checkTime( numbers, numbers[ midIndex ] ) )
   			return numbers[ midIndex ];
		else return 0;
    }
};

int main(int argc, char *argv[])
{
	Solution2 oj;
	cout << oj.MoreThanHalfNum_Solution( {
		4,2,1,4,2,4
	} );
	return 0;
}