/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

class Solution {
private:
	void reverseCore( char *startPtr, char *endPtr ){
		--endPtr;
		while( startPtr < endPtr )
			swap( *startPtr++, *endPtr-- );				
	}
public:
    string LeftRotateString(string str, int n) {
        if( str.size() == 0 )
        	return string();
       	
       	reverseCore( &str[ 0 ], &str[ n ] );//翻转前n个字符
       	reverseCore( &str[ n ], &str.back() + 1 );//翻转剩余部分
       	reverseCore( &str[ 0 ], &str[ str.size() ] );//再翻转整个句子
       	
       	return str;
    }
};
int main(int argc, char *argv[])
{
	string str( "hello" );
	cout << str.back();
	return 0;
}