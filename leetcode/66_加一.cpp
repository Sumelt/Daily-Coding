/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        stack<int>stk;
        vector<int>res;
        for( auto value : digits )
            stk.push( value );
        bool flag = true;
        while( !stk.empty() ) {
        	if( flag && stk.top() + 1 >= 10 ) {
	        	res.push_back( ( stk.top() + 1 ) % 10 );
	        	flag = false;
	        	stk.pop();
	        	if( stk.empty() )
	        		res.push_back( 1 );
        		else {
		        	while( !stk.empty() && stk.top() + 1 >= 10 ) {
	        			res.push_back( ( stk.top() + 1 ) % 10 );
	        			stk.pop();
	        		}
		        	if( stk.empty() )
	        			res.push_back( 1 );
        			else {
			        	res.push_back( ( stk.top() + 1 ) % 10 );
			        	res.pop();
			        } 
		        } 
	        }
            else if( flag ) {
                res.push_back( stk.top() + 1 );
                stk.pop();
                flag = false;
            }                
            else {
            	res.push_back( stk.top() );
            	stk.pop();
            }            
        }
        reverse( res.begin(), res.end() );
        return res;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}