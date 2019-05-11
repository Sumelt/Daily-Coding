/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <climits>
using namespace std;

/*题解看不懂*/ 
class Solution{
private:
	int maxValue = INT_MIN;z
public:
	int getMaxValue( const int *array, int rows, int cols ) {
		
		int *saveValue = new int[ cols ]();
		
		for( int row = 0; row < rows; ++row )
			for( int col = 0; col < cols; ++col ) {
				
				int leftValue = 0, downValue = 0;
				if( row > 0 )
					downValue = saveValue[ col ];
				if( col > 0 )
					leftValue = saveValue[ col - 1 ];
				
				saveValue[ col ] = max( leftValue, downValue ) + 
					array[ row * cols + col ];					
			}				
	}	
};

int main(int argc, char *argv[])
{
	
	return 0;
}