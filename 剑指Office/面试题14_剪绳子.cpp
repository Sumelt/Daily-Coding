/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <cmath>
using namespace std;

int maxArea( int sumLength )
{
	if( sumLength <= 1 )
		return 0;
	if( sumLength == 2 )
		return 1;
	if( sumLength == 3 )
		return 2;
	
	int maxAreaArray[ sumLength + 1 ] = { 0 };
	maxAreaArray[ 1 ] = 1;
	maxAreaArray[ 2 ] = 2;
	maxAreaArray[ 3 ] = 3;
	
	int maxAreaValue = 0;
	for( int iLength = 4; iLength <= sumLength; ++iLength ) { //从小的部分开始计算 
		maxAreaValue = 0;
		for( int jLength = 1; jLength <= iLength / 2; ++jLength ) {
			int Area = maxAreaArray[ jLength ] * maxAreaArray[ iLength - jLength ];
			if( Area > maxAreaValue )
				maxAreaValue = Area;
							
		}
		maxAreaArray[ iLength ] = maxAreaValue;	//不断获得子问题的最优解		
	}
	return maxAreaArray[ sumLength ];
} 

//贪心算法

int maxAreaGreedy( int sumLength )
{
	if( sumLength <= 1 )
		return 0;
	if( sumLength == 2 )
		return 1;
	if( sumLength == 3 )
		return 2;
	
	int timeOfTree = 0;
	int timeOfTwo = 0;
	
	if( sumLength > 5 ) {
		timeOfTree = sumLength / 3; //尽可能多的减去长度为3的绳子长度 
	}
	if( sumLength - timeOfTree * 3 == 1 ) //当绳子的长度剩下 4的时候不要再剪长度为3的绳子 
		--timeOfTree;
	timeOfTwo = ( sumLength - timeOfTree * 3 ) / 2;//此时的方法是把长度为4的绳子剪成两段 每段为长度为2 
	return pow( 2, timeOfTwo ) * pow( 3, timeOfTree );
}

 
int main(int argc, char *argv[])
{
	int length = 8;
	cout << maxArea( length ) << endl;
	cout << maxAreaGreedy( length );
	
	return 0;
}