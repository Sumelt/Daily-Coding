/*----------------------------------------------------------------

* @Author: Su

* @Description: 
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
则重建二叉树并返回。
* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
	
	
	TreeNode* CreateTree( vector<int> pre,vector<int> vin, int preStartIndex,
		int preEndIndex, int vinStartIndex, int vinEndIndex ) {
		
		if ( vinStartIndex > vinEndIndex )
			return nullptr;
		int vinMidIndex	= vinStartIndex;
		for( ; vinMidIndex <= vinEndIndex; ++vinMidIndex )
			if( vin[ vinMidIndex ] == pre[ preStartIndex ] )
				break;
		int length = vinMidIndex - vinStartIndex;
		TreeNode* root = new TreeNode( vin[ vinMidIndex ] );
		root->left = CreateTree( pre, vin, preStartIndex + 1, preEndIndex, 
			vinStartIndex, vinMidIndex - 1 );
		root->right = CreateTree( pre, vin, preStartIndex + length + 1, 
			preEndIndex, vinMidIndex + 1, vinEndIndex );
		
		return root;
	}
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		if( pre.size() == 0 || vin.size() == 0 )
			return nullptr;
		return CreateTree( pre, vin, 0, pre.size() - 1, 0, vin.size() - 1 );
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}