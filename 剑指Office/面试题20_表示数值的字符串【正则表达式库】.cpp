/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Solution {
public:
    bool match( const char* str, const char* pattern ) {
		std::regex rgx( pattern );
    	return std::regex_match( str, rgx );
    }
};

int main(int argc, char *argv[])
{
	const char *pat = "a";
	const char *str = "";
	Solution oj;
	cout << oj.match( pat, pat );
	return 0;
}