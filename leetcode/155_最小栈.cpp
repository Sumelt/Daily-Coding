/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <list>
#include <stack>
using namespace std;

class MinStack {
private:
	stack<int, list<int>>stkMin;
	stack<int, list<int>>stk;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
    	stk.push( x );
    	if( !stkMin.empty()&& x < stkMin.top() )
    		stkMin.push( x );
   		else if( !stkMin.empty() )
   			stkMin.push( stkMin.top() );
		else stkMin.push( x ); 
    }
    
    void pop() {
        stkMin.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
    	return stkMin.top();
    }
};


int main(int argc, char *argv[])
{
	
	return 0;
}