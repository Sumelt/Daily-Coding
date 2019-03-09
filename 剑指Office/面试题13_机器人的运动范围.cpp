/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
	int sumRow;
	int sumCol;	
public:
    int countGrid( int threshold, int row, int col, int countSum, bool *visted )
    {
    	int sum = 0;  	
    	if( row >= sumRow || col >= sumCol 
			|| row < 0 || col < 0 || visted [ row * sumCol + col ] )
    		return 0;
    	int tempIndex = row * sumCol + col;
		string strRow = to_string( row );
    	for( unsigned int i = 0; i < strRow.size(); ++i ) //获取坐标数位之和 
    		sum += strRow[ i ] - '0';
    	string strCol = to_string( col );
    	for( unsigned int i = 0; i < strCol.size(); ++i ) //获取坐标数位之和 
    		sum += strCol[ i ] - '0'; 
    		
		if( sum > threshold ) //大于阀值 
			return 0;						
		else ++countSum; //本身是一个可到达的点 
		
		//cout << tempIndex << ' ' << row << ' ' << col << endl;		
		visted[ tempIndex ] = true; //标记本身已经访问过了
		//计算它四个方向可到达的点 
		countSum += countGrid( threshold, row + 1, col, 0, visted );
		countSum += countGrid( threshold, row - 1, col, 0, visted );
		countSum += countGrid( threshold, row, col + 1, 0, visted );
		countSum += countGrid( threshold, row, col - 1, 0, visted );
    	 	
    	return countSum;
    }
    
	int movingCount(int threshold, int rows, int cols)
    {
		sumRow = rows;
        sumCol = cols;
        bool visted[ 1000 ] = { false };
        int count = 0;
		count = countGrid( threshold, 0, 0, 0, visted );
		return count;
    }
};

int main(int argc, char *argv[])
{
	 
	 cout  << endl << Solution().movingCount( 5,10,10 );
	return 0;
}