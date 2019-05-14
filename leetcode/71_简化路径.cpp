/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>
#include <stack>
using namespace std;

class Solution {
private:
	bool flag;
	
public:
    string simplifyPath(string path) {
        string legalPath = string();
        flag = false;
  		stack<char>stack;
		      
		if( !path.size() )
        	return legalPath;
        	
 		for( int i = 0; i < path.size(); ++i ) {
		 	if( path[ i ] != '.' ) {
				if( path[ i ] == '/' && stack.size() > 0 && stack.top() == '/' )
					continue;
				else stack.push( path[ i ] );
	 		}
 		}

	 	if( stack.top() == '/' && stack.size() > 1)
	 		stack.pop();
 		while( !stack.empty() ) {
		 	legalPath += stack.top();
		 	stack.pop();
		 }
	 	return string( legalPath.rbegin(), legalPath.rend() );
    }
};

int main(int argc, char *argv[])
{
	Solution oj;
	cout << oj.simplifyPath( "/a//b////c/d//././/.." );
	return 0;
}