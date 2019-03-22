/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
private:
	stack<int>stk;//主栈
	stack<int>aidStk;//辅助栈
	int minValue;//最小元

public:
    void push(int value) {
		if( stk.empty() )
			minValue = value;//栈为空，最小元一定是第一个入栈的元素
		else
			if( value < minValue )//遇到更小的元素
				minValue = value;
		stk.push( value );//压入每一个元素
		aidStk.push( minValue );//同步主栈压入元素，每次都压入最小元		        
    }
    void pop() {
     stk.pop();
     aidStk.pop();
    }
    int top() {
     	return stk.top();
    }
    int min() {
        return aidStk.top();//辅助栈始栈顶始终保持着最小元
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}