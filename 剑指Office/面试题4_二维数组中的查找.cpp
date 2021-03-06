/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//较为复杂  
//bool Find(int target, vector<vector<int> > array) {
//	int sumRow = array.size() - 1; int sumColumn = array[0].size() - 1;
//	int aimColumnIndex = sumColumn; int aimRowIndex = 0;
//	if( sumRow < 0 && sumColumn < 0 ) return false;
//	while( aimRowIndex <= sumRow && aimColumnIndex >= 0 && array[ aimRowIndex ][ aimColumnIndex ] != target )
//	{
//		for( ; aimColumnIndex >= 0 && aimRowIndex <= sumRow &&
//			array[ aimRowIndex ][ aimColumnIndex ] > target; --aimColumnIndex ); //排除不符合的列 
//
//		for( ; aimColumnIndex >= 0 && aimRowIndex <= sumRow && array[ aimRowIndex ][ aimColumnIndex ] < target; ++aimRowIndex );
//	}
//	if( aimRowIndex <= sumRow && aimColumnIndex >= 0 && array[ aimRowIndex ][ aimColumnIndex ] == target ){
//		return true;
//	} 
//		
//	else return false;
//}


//time O(n) space O(1)
bool Find(int target, vector<vector<int> > array) {
	int sumRow = array.size() - 1; int sumColumn = array[0].size() - 1; //获得总最大行列的下标 
	int aimColumnIndex = sumColumn; //最后一列开始 
    int aimRowIndex = 0; //第一行开始 
	if( sumRow < 0 && sumColumn < 0 ) return false; //边界判断 
	while( aimRowIndex <= sumRow && aimColumnIndex >= 0 )
	{
		if( array[ aimRowIndex ][ aimColumnIndex ] > target ) //该列比目标值大 
			--aimColumnIndex;		//排除该列 
		else if( array[ aimRowIndex ][ aimColumnIndex ] < target ) //该列比目标值小 
			++aimRowIndex; //排除该行 
		else if( array[ aimRowIndex ][ aimColumnIndex ] == target ) //相等 则找到 
			return true;
	}			
	return false;
}

int main(int argc, char *argv[])
{
	//vector<vector<int> > array = { {2,4},{ 4, 7 } };
	//cout << Find( 7, array );
			
	return 0;
}




