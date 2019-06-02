/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <list>
using namespace std;

class MyQueue {
private:
	stack<int, list<int>>stackLeft; //in
 	stack<int, list<int>>stackRight; //out
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stackLeft.push( x );
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
    	int res = -1;
        if( stackRight.empty() && !stackLeft.empty() ) {
        	while( !stackLeft.empty() ) {
	        	stackRight.push( stackLeft.top() );
	        	stackLeft.pop();
        	}
        }
    	res = stackRight.top();
    	stackRight.pop();        
        return res;
    }
    
    /** Get the front element. */
    int peek() {
     	int res = -1;
        if( stackRight.empty() && !stackLeft.empty() ) {
        	while( !stackLeft.empty() ) {
	        	stackRight.push( stackLeft.top() );
	        	stackLeft.pop();
        	}        	
        }
        res = stackRight.top();
        return res;       
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stackRight.empty()&&stackLeft.empty();
    }
};



int main(int argc, char *argv[])
{
	
	return 0;
}