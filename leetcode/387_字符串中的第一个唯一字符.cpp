/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
	int appearIndex[ 26 ];
public:
    int firstUniqChar(string s) {
        if( s.size() <= 0 )
        	return -1;
		fill( appearIndex, appearIndex + 26, 0 );
        
        for( int i = 0; i < s.size(); ++i )
        	appearIndex[ s[ i ] - 'a' ] = i;
        	
       	for( int i = 0; i < s.size(); ++i )
       		if( appearIndex[ s[ i ] - 'a' ] == i )
       			return i;
       		else appearIndex[ s[ i ] - 'a' ] = -1;	
		return -1;
    }        
};

int main(int argc, char *argv[])
{
	
	return 0;
}