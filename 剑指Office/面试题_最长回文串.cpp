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
public:
    string longestPalindrome(string s) {
        
    }
};

class Solution {
private:
	int start = 0;
	int maxlen = 1;
public:
	string longestPalindrome( string str ) {
		if( str.size() == 1 ) 
			return str;
		
		for( int i = 0; i < str.size(); ++i ) {		
			for( int j = i + 1; j < str.size(); ++j ) {
				int ptr1 = i, ptr2 = j;
				while( ptr1 < ptr2 && str.at( ptr1 ) == str.at( ptr2 ) ) {
					++ptr1;
					--ptr2;
				}
				int curlen = j - i + 1;
				if( ptr1 >= ptr2 && curlen > maxlen ) {
					maxlen = curlen;
					start = i;
				} 								
			}
		}
		return str.substr( start, maxlen );
	}
};

int main(int argc, char *argv[])
{
	
	return 0;
}