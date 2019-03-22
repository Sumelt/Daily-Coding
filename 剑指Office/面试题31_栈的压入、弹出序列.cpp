/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <stack>
#include <vector>
#include <memory>
using namespace std;

class Solution {
private:
	stack<int>stk;	
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if( pushV.size() == 0 || popV.size() == 0 )
        	return false;     	
        auto index = pushV.begin();//要压入栈的第一个元素的迭代器
        int popvIndex = 0;//指向弹出元素的下标
        stk.push( *index );
 		
 		while( index != pushV.end() )//入栈元素还没全部入栈
 		{
			if( !stk.empty() ) {
				if( stk.top() == popV[ popvIndex ] ) {//栈顶和指向弹出元素相等
					stk.pop();//栈顶元素出栈
					++popvIndex;//指向下一个弹出元素
				}
				else//栈顶和指向弹出元素不相等
					if( pushV.end() != ++index  )//主栈压入下一个元素
						stk.push( *index );	
			}
			else//主栈空了但入栈序列的元素还没全部入栈
				if( pushV.end() != ++index  )//不断入栈
					stk.push( *index );				
		}
        if( stk.empty() )//如果符合一个弹出序列则主栈最后为空
        	return true;
       	return false;
        	
    }
};

int main(int argc, char *argv[])
{
	Solution oj;
	cout << oj.IsPopOrder( { 1,2,3, 4, 5 }, { 4, 3, 5, 1, 2 } );
	return 0;
}