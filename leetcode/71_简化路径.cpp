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
	stack<string>stk;
	
public:
    string simplifyPath(string path) {
		if( !path.size() )
			return string();
		string res = string();
		
		int idx = 0;
		if( path[ idx++ ] == '/' )
			stk.push( "/" );
			
		while( idx < path.size() ) {
			
			while( idx < path.size() && path[ idx ] == '/' ) 
				++idx;
			int start = idx;
			
			while( idx < path.size() && path[ idx ] != '/' )
				++idx;
				
			string substr = path.substr( start, idx - start );
			
			if( substr.size() > 0  ) {
				if( substr == ".." )  {
					if( stk.size() > 1 )
						stk.pop();					
				}
				else if( substr != "." && substr != "/")
					stk.push( substr );
			}
			
		}
		while( stk.size() > 1 ) {
			res.insert( 0, stk.top() );
			res.insert( 0, "/" );
			stk.pop();
		}
		if( !res.size() )
			res.insert( 0, "/" );
			 	
		return res;
    }
};

int main(int argc, char *argv[])
{
	Solution oj;
	cout << oj.simplifyPath("/a/./b/../../c/");
	return 0;
}
