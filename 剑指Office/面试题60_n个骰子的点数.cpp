/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxPoints = 6; //骰子最大点数，便于扩展
class Solution {
private:
	int maxSum;
	int minSum;
	
	int *array = nullptr;
	void Split( int sumCount ) {
		for( int point = 1; point <= maxPoints; ++point )
			SplitCal( sumCount, sumCount, point );//第一个骰子的点数:头 
	}
	void SplitCal( int sumCount, int curCount, int reSum ) {//骰子总数 当前剩余骰子个数 累加和
		if( curCount == 1 ) { //该堆只有一个骰子
			++array[ reSum - sumCount ];
			return;
		}			
		for( int point = 1; point <= maxPoints; ++point )
			SplitCal( sumCount, curCount - 1, reSum + point );//子的点数,不断分成两堆
	}
public:
    void printProbability( int sumCount ) {
        if( sumCount == 0 )
        	return;
       	maxSum = sumCount * maxPoints;
       	minSum = sumCount;
       	array = new int[ maxSum - minSum + 1 ]();//申请空间
       	double total = pow( maxPoints, sumCount );//排列组合情况总数
       	
       	Split( sumCount );
       	
       	for( int i = minSum; i <= maxSum; ++i )
       		printf( "%d : %e\n", i, array[ i - sumCount ]/total );
  		delete []array;      	
    }
};
/* bug 
class Solution2 {
private:
	int maxSum;
	int minSum;
	int flag = 0;
	int *array[2] = { nullptr, nullptr };
	void calProbability( int sumCount ) {
		
		for( int i = 1; i <= maxPoints; ++i )
			array[ flag ][ i ] = 1;
		
		for( int k = 2; k <= sumCount; ++k ) {
			for( int i = 0; i < k; ++i )
				array[ 1 - flag ][ i ] = 0;
			
			for( int i = k; i <= maxPoints * k; ++i ) {
				array[ 1- flag ][ i ] = 0;
				for( int j = 1; j <= i && j <= maxPoints; ++j )
					array[ 1- flag ][ j ] += array[ flag ][ i - j ];
			}
			flag = 1 - flag;		
		}		 
	}
public:
    void printProbability( int sumCount ) {
        if( sumCount == 0 )
        	return;
       	minSum = sumCount;
       	maxSum = maxPoints * sumCount;
       	array[ 0 ] = new int[ maxSum + 1 ]();
       	array[ 1 ] = new int[ maxSum + 1 ]();
       	
       	calProbability( sumCount );
       	double total = pow( maxPoints, sumCount );
       	for( int i = minSum; i <= maxSum * sumCount; ++i )
       		//printf( "%d : %e\n", i, array[ flag ][ i ]/total );
 			cout << array[ flag ][ i ] << endl;
  		delete []array[ 0 ];
		delete []array[ 1 ];      	
    }
};
*/
int main(int argc, char *argv[])
{
	Solution2 oj;
	oj.printProbability( 2 );
	
	return 0;
}