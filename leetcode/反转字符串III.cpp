/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        if( size == 0 ) return string();
        for( int i = 0, j = 0; i < size; ++i, j = i ){
        	while( i < size && s[ i ] != ' ' ) ++i;
            int tempIndex = i;
            while( j < i ) swap( s[ j++ ], s[ --i ] );
            i = tempIndex;
        }
        return s;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        auto prPrt = s.begin();
        auto lastPtr = s.begin();
        
        while( lastPtr <= s.end() ) {
        	while( *lastPtr != ' ' && lastPtr != s.end()  ) ++lastPtr;
        	reverse( prPrt, lastPtr );
       		++lastPtr;
       		prPrt = lastPtr;
        }      
        return s;
    }
};


int main(int argc, char *argv[])
{
	
	return 0;
}