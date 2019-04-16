/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

class Solution {
private:
	int *uglyArray = nullptr;	
public:
    int GetUglyNumber_Solution( int index ) {
    	if( index == 0 ) 
    		return 0;
   		
        uglyArray = new int[ index ]();//申请保存丑数的数组空间
   		uglyArray[ 0 ] = 1;//第一位丑数是1
   		int curArrayIndex = 1;//下一个丑数的下标
   		int *twoPtrarray = uglyArray;//因子为2的丑数序列
   		int *threePtrarray = uglyArray;//因子为3的丑数序列
   		int *fivePtrArray = uglyArray;//因子为5的丑数序列
   		
        //找到第指定个数的丑数
   		while( curArrayIndex < index ) {
			int minValue = min( *twoPtrarray * 2, 
				min( *threePtrarray * 3, *fivePtrArray * 5 ) );//返回3个序列中最小的一个丑数作为下一个真正的丑数
			uglyArray[ curArrayIndex ] = minValue;//保存该丑数同时也是序列中最大的丑数
			
			while( *twoPtrarray * 2 <= uglyArray[ curArrayIndex ] )//找出因子为2序列中第一个大于真正丑数序列中最大的丑数
				++twoPtrarray;//不断下移
				
			while( *threePtrarray * 3 <= uglyArray[ curArrayIndex ] )//同理
				++threePtrarray;
				
			while( *fivePtrArray * 5 <= uglyArray[ curArrayIndex ] )//同理
				++fivePtrArray;
			++curArrayIndex;
	   	}
	   	
	   	int res = uglyArray[ curArrayIndex - 1 ];
	   	delete []uglyArray;
	   	return res;
    }
};

int main(int argc, char *argv[])
{
	Solution oj;
	cout << oj.GetUglyNumber_Solution( 4 );
	return 0;
}