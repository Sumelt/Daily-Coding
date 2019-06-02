/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
using namespace std;

class MyStack {
private:
	vector<int>que;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push_back( x );
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = que[ que.size() - 1 ];
        que.pop_back();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return que[ que.size() - 1 ];
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}