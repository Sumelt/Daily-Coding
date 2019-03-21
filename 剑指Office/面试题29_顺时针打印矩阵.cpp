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
	int endRows; //终止行
	int endColumns; //终止列
public:
	void printRing( int startPoint, vector<vector<int> > &matrix, vector<int> &res ){
		//从左到右打印一行
        if( endColumns >= startPoint )
			for( int i = startPoint; i <= endColumns; ++i )
				res.push_back( matrix[ startPoint ][ i ] );
		//从上到下打印一列
        if( endRows > startPoint )
			for( int i = startPoint + 1; i <= endRows; ++i )
				res.push_back( matrix[ i ][ endColumns ] );
		//从左到右打印一行
        if( endColumns > startPoint && endRows > startPoint )
			for( int i = endColumns - 1; i >= startPoint; --i )
				res.push_back( matrix[ endRows ][ i ] );
		//从下到上打印一列
        if( endColumns > startPoint && endRows - 1 > startPoint )
			for( int i = endRows - 1; i > startPoint; --i )
				res.push_back( matrix[ i ][ startPoint ] );
	}	
	vector<int> printMatrix(vector<vector<int> > matrix) {
		if( matrix.size() == 0 || matrix[ 0 ].size() == 0)
			return vector<int>();
		endRows = matrix.size() - 1;
		endColumns = matrix[ 0 ].size() - 1;
		int startPoint = 0;
		vector<int>res;//保存结果的容器
		//和总行数和总列数进行判定
		while( startPoint * 2 < matrix.size() && startPoint * 2 < matrix[ 0 ].size() ){
			printRing( startPoint, matrix, res );
			++startPoint;//下一个起始点
			--endRows;//终止行相应减少
			--endColumns;//终止列相应减少
		}						
		return res;
	}	
};


int main(int argc, char *argv[])
{
	Solution oj;
	vector<int> temp = oj.printMatrix( {{ 1}, { 3}, { 5} } );
	for( auto value : temp )
		cout << value << ' ';
	return 0;
}