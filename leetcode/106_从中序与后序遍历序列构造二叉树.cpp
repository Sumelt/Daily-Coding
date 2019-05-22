/*----------------------------------------------------------------

* @Author: Su

* @Description: 

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
private:
    TreeNode* creatTreeNode( vector<int>& postorder, vector<int>& inorder, 
		int postStartIndex, int postEndIndex, int inStartIndex, int inEndIndex )
	{
        if( inStartIndex > inEndIndex )
            return nullptr;
        TreeNode *root = new TreeNode( postorder[ postEndIndex ] );
        int rootIndex = inStartIndex;
        for( ; rootIndex <= inEndIndex; ++rootIndex ) 
            if( postorder[ postEndIndex ] == inorder[ rootIndex ] )
                break;
        int length = rootIndex  - inStartIndex;
        root->left = creatTreeNode( postorder, inorder, 
			postStartIndex, postStartIndex + length - 1, inStartIndex, rootIndex - 1 );
        root->right = creatTreeNode( postorder, inorder, 
			postStartIndex + length, postEndIndex - 1, rootIndex + 1, inEndIndex );
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if( postorder.size() <= 0 || inorder.size() <= 0 )
            return nullptr;
        return creatTreeNode( postorder, inorder, 
			0, postorder.size() - 1, 0, inorder.size() - 1 );
    }
};

int main(int argc, char *argv[])
{
	Solution oj;
	vector<int>a = { 2, 3, 1 };
	vector<int>b = { 2, 1, 3 };
	auto node = oj.buildTree( b, a );
	cout << node->val;
	cout << node->left->val;
	cout << node->right->val;
	return 0;
}