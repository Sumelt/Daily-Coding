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
	int firstIndex = 0;
	int lastIndex = 0;
    //得到第一次出现的下标
	int getFirstIndex( vector<int>&data, int startIndex, int endIndex, int k ) {
		if( startIndex > endIndex )
			return -1;
		int midIndex = ( startIndex + endIndex ) >> 1;
		//中间元素相同检查它前一个元素			
		if( data[ midIndex ] == k ) {
			if( ( midIndex > 0 && data[ midIndex - 1 ] != k ) || midIndex == 0 )
				return midIndex;//找到第一次出现的下标
			else endIndex = midIndex - 1;//它前一个元素相同，继续二分前半部分
		}//中间元素不同
		else {
			if( data[ midIndex ] > k )
				endIndex = midIndex - 1;
			else startIndex = midIndex + 1;			
		}		
		return getFirstIndex( data, startIndex, endIndex, k );					
	}
    
	//得到最后一次出现的下标
	int getEndIndex( vector<int>&data, int startIndex, int endIndex, int k ) {
		if( startIndex > endIndex )
			return -1;
		int midIndex = ( startIndex + endIndex ) >> 1;
		//中间元素相同检查它后一个元素		
		if( data[ midIndex ] == k ) {
			if( ( midIndex < data.size() - 2 && 
				data[ midIndex + 1 ] != k ) || midIndex == data.size() - 1 )
				return midIndex;//找到最后一次出现的下标
			else startIndex = midIndex + 1;//它后一个元素相同，继续二分后半部分
		}//中间元素不同
		else {
			if( data[ midIndex ] > k )
				endIndex = midIndex - 1;
			else startIndex = midIndex + 1;			
		}		
		return getEndIndex( data, startIndex, endIndex, k );		
	}	
public:
    int GetNumberOfK(vector<int> data ,int k) {
       if( data.size() == 0 ) 
       	return 0;
       	firstIndex = getFirstIndex( data, 0, data.size() - 1, k );
       	lastIndex = getEndIndex( data, 0, data.size() - 1, k );
       	
       if( lastIndex > -1 && firstIndex > -1 )	
			return lastIndex - firstIndex + 1;
		else return 0;
	   	
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}