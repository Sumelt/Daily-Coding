/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <stack> 
using namespace std;

class Solution
{
public:
    void push(int node) { //元素压入栈1 
        stack1.push( node );
    }

    int pop() {
        int res = 0;
		if( stack2.size() <= 0 && stack1.size() > 0 ) //栈2为空 栈1不为空 
        	while( !stack1.empty() ) {
	        	stack2.push( stack1.top() ); //栈1元素导入栈2 
	        	stack1.pop(); //栈1pop 
	        }
        if( stack2.size() > 0 ) {
        	res = stack2.top(); //要删除的元素 
        	stack2.pop();
        }
		return res;	//返回元素 
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(int argc, char *argv[])
{
	
	return 0;
}