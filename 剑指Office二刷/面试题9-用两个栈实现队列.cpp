/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
using namespace std;

class Solution {
private:
	stack<int>stackPush;
	stack<int>stackPop;
public:
    void push(int node) {
       stackPush.push( node );
    }

    int pop() {
		int res;		
		if( stackPop.empty() && !stackPush.empty() )
			while( !stackPush.empty() ) {
				stackPop.push( stackPush.top() );
				stackPush.pop();
			}
			
		res = stackPop.top();
		stackPop.pop();
		return res;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}