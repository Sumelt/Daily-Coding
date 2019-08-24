/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

class Solution {
private:
	int sumIndex;
	int sumrows;
	int sumcols;

public:
	bool judgePath( char *matrix, char *str, int row, int col, 
		int strIndex, bool *visted )
	{
		if( str[ strIndex ] == '\0' ) //目标路径已经全部走完 
			return true;
		bool hasPath = false;
		int tempIndex = row * sumcols + col;
		if( tempIndex <= sumIndex && matrix[ tempIndex ] == str[ strIndex ]  //该点属于目标路径中 
			&& !visted[ tempIndex ] ) {
				visted[ tempIndex ] = true; //该点设置访问过 
				strIndex++; //获取下一个目标路径中的下一个节点 
				hasPath = judgePath( matrix, str, row + 1, col, strIndex, visted )
					|| judgePath( matrix, str, row - 1, col, strIndex, visted )
					|| judgePath( matrix, str, row, col + 1, strIndex, visted )
					|| judgePath( matrix, str, row, col - 1, strIndex, visted );
			
				if( !hasPath ) {
						--strIndex;
						visted[ tempIndex ] = false;
				}	
			}

		return hasPath;
	} 
		
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
  		if( matrix == nullptr || str == nullptr || cols < 1 || rows < 1 )
  			return false;
  			
  		sumIndex = rows * cols - 1;
  		sumcols = cols;
  		sumrows = rows;
 		bool visted[ 100 ] = {false};
 		
		for( int row = 0; row < sumrows; ++row  )
			for( int col = 0; col < sumcols; ++col ){
				if( judgePath( matrix, str, row, col, 0, visted )) //判断该点是否存在路径 
					return true;			
			}
		return false;			 	
    }
};

int main(int argc, char *argv[])
{
	 char array[] = { 'a', 'b', 'c', 'e', 's', 'f', 'c', 's', 'a', 'd', 'e', 'e' }; // 3 * 4
	 char str[] = {'b','b','a','a','a'};
	 Solution so;
	 cout << so.hasPath( array, 3, 4, str );
	return 0;
}

/*
if( judgePath( matrix[ row * sumcols + col ], i, str[ aimStrIndex ] )) {
					visted[ i ] = true;
					++aimStrIndex;
					
					
					
				}*/