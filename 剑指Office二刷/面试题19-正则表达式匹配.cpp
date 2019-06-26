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
	const char END = '\0';
	bool mathCode( char* str, char* pattern ) {
		if( *str == END && *pattern == END )
			return true; //匹配全部完成
		if( *str != END && *pattern == END ) 
			return false;
			
		//第二位是*
		if( *( pattern + 1 ) == '*' ) {
			if( *str == *pattern || ( *pattern == '.' && *str != END ) )
				return mathCode( str + 1, pattern + 2 ) ||
						mathCode( str, pattern + 2 ) ||
							mathCode( str + 1, pattern );
			else return mathCode( str, pattern + 2 );
		}
		
		//第二位不是*
		else if( *str != END && ( *pattern == '.' || *str == *pattern ) ) {
			return mathCode( str + 1, pattern + 1 );
		}
		//第二位不是*，同时第一位也不是. 
		else return false;
			
	}
public:
    bool match(char* str, char* pattern) {
    	if( str == nullptr && pattern == nullptr )
    		return false;
   		else return mathCode( str, pattern );
    }
};


int main(int argc, char *argv[])
{
	
	return 0;
}