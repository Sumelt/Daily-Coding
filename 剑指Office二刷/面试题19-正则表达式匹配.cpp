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
        
		if( *str != END && *pattern == END )//目标串还未匹配完，模已经匹配完 
			return false;
		//对于串匹配完，而模还未匹配完这种情况是有效的，比如 a ab*	
        
		//第二位是*
		if( *( pattern + 1 ) == '*' ) {
			//这里*str != END要求不越界
            if( *str != END && ( *pattern == '.' || *str == *pattern ) )
				return 
                	//匹配，一一匹配
                	mathCode( str + 1, pattern + 2 ) ||
					//不匹配，又因为*可以匹配0个字符	
                	mathCode( str, pattern + 2 ) ||
					//匹配，又因为*可以匹配多个字符		
                	mathCode( str + 1, pattern );
            //不匹配，串不动，模后移动，因为*可以匹配0个字符
			else return mathCode( str, pattern + 2 );
		}		
		//第二位不是*
        //这里*str != END要求不越界
		else if( *str != END && ( *pattern == '.' || *str == *pattern ) )
			return mathCode( str + 1, pattern + 1 );		
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