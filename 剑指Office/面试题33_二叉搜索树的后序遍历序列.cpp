/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		if( sequence.size() == 0 )
			return false;
		if( sequence.size() == 1 )//只有一个节点
			return true;
		int leftIndex = 0;
		int rightIndex = 0;
		int rootValue = sequence[ sequence.size() - 1 ];//根节点的数值
		
		//寻找左子树（左子树的区间很重要，并且决定了右子树的区间）
        for( leftIndex; leftIndex < sequence.size() - 1; ++leftIndex )
			if( sequence[ leftIndex ] > rootValue )
				break;
       //寻找右子树
		for( rightIndex = leftIndex; rightIndex < sequence.size(); ++rightIndex )
			if( sequence[ rightIndex ] < rootValue )
				return false;
		
        //容器的初始化区间一定是【)范围，二叉搜索树不要求是完全二叉树
		bool left = true;//左子树不存在也是真
		if( leftIndex > 0 )//左子树存在
			left = VerifySquenceOfBST( 
				vector<int>( sequence.begin(), sequence.begin() + leftIndex ) );
        
		bool right = true;//右子树不存在也是真
		if( leftIndex < sequence.size() - 1 )//右子树存在
			right = VerifySquenceOfBST( 
				vector<int>( sequence.begin() + leftIndex, sequence.end() - 1 ) );
				
		return ( left && right );
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}