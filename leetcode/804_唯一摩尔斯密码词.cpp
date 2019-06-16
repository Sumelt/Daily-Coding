/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <set>
using namespace std;

class Solution {
private:
	const char *codes[ 26 ] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",
				".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
				"...","-","..-","...-",".--","-..-","-.--","--.." };

public:
    int uniqueMorseRepresentations(vector<string>& words) {
    	set<string>Set;
    	string code;
        for( auto str : words ) {
        	for( int i = 0; i < str.size(); ++i )
        		code += codes[ str[ i ] - 'a' ];
       		Set.insert( code );
       		code.clear();
        }
        return Set.size();
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}