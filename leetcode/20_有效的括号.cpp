/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
		if( s.size() == 0  )
			return false;
			
		stack<char>stack;
		for( int i = 0; i < s.size(); ++i ) {
			switch( s[ i ] ) {
				case '(':
				case '[':
				case '{':				
						stack.push( s[ i ] );
						break;
				default:
						if( stack.size() == 0 )
							return false;
						char top = stack.top();
						stack.pop();
						if( ( top == '(' && s[ i ] == ')' ) || 
							( top == '[' && s[ i ] == ']' ) || 
							( top == '{' && s[ i ] == '}' ) )
							break;
						else return false;				
			}
		}
		if( stack.empty() )
			return true;
		else return false;
    }
};

int main(int argc, char *argv[])
{
	Solution oj;
	cout << oj.isValid( "()" );
	return 0;
}