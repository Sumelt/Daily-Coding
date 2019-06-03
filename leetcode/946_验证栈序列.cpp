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

class Solution {
private:
	stack<int, list<int>>stk;
public:
    bool validateStackSequences(const vector<int>& pushed, const vector<int>& popped) {
    	if( !pushed.size() || !popped.size() )
    		return true;
  		int popIndex, pushIndex;
		popIndex = pushIndex = 0;
		//入栈元素还未遍历完成，并且要多一次循环进行比较  
  		while( pushIndex <= pushed.size() ) {
			//当前的栈顶元素和出栈序列的元素相同，则栈顶元素弹出，出栈元素下标位置移动
            //这里要不断循环，因为出栈后的下一个元素也可能和新栈顶元素相同
            while( !stk.empty() && ( stk.top() == popped[ popIndex ] ) ) {
			  		stk.pop();
			  		++popIndex;
			  }
			if( pushIndex < pushed.size() )//入栈下一个元素
				stk.push( pushed[  pushIndex++ ] );
			else break;//已经全部比较完成
		}
		if( stk.empty() )//栈顶为空时，说明符合要求
			return true;
		else
			return false;
    }
};


int main(int argc, char *argv[])
{
	Solution oj;
	cout << oj.validateStackSequences( {1,2,3,4,5}, {4,5,3,2,1});
	return 0;
}