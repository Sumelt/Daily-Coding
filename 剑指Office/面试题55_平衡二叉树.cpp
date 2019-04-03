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
public:
	int IsBalanced( TreeNode *root, int deep ) {//根节点
		if( root == nullptr )
			return 0;
		int left = IsBalanced( root->left, deep );//根节点的左子树
		int right = IsBalanced( root->right, deep );//根节点的右子树
		
		return 1 + ( left > right ? left : right );//根节点+左右子树中最大的深度
	}
    bool IsBalanced_Solution(TreeNode* pRoot) {
		if( pRoot == nullptr ) //节点为空也是平衡树
			return true;
		int left = IsBalanced( pRoot->left, 0 );//判断根节点的左子树
		int right = IsBalanced( pRoot->right, 0 );//判断根节点的右子是
		int res = abs( left - right );//它们差的绝对值不超过1为平衡树
		return res > 1 ? false : true;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}