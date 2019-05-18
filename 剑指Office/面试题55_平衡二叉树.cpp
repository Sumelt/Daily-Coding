/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
private:
	bool IsBalanced_Solution(TreeNode* pRoot, int *depth) {
		if( pRoot == nullptr ) {
			*depth = 0;//这里就是对left或者right赋值
			return true;
		}
			
		int left, right;		
		bool leftRes = IsBalanced_Solution( pRoot->left, &left );
		bool rightRes = IsBalanced_Solution( pRoot->right, &right );
		
		if( !leftRes || !rightRes )//以pRoot为根节点的左右子树已经不再平衡直接返回
			return false;
		
		int res = abs( left - right );//求得差值
		*depth = 1 + ( left > right ? left : right );//这里就是对left或者right赋值
		return res > 1 ? false : true;//判断子树是否平衡
	}
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
		
		if( pRoot == nullptr )
			return true;
		int depth = 0;
		return IsBalanced_Solution( pRoot, &depth );
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}