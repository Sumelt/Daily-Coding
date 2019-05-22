/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
    TreeNode* creatTreeNode( vector<int>& preorder, vector<int>& inorder, int preStartIndex, int preEndIndex, int inStartIndex, int inEndIndex ) {
        if( inStartIndex > inEndIndex )
            return nullptr;
        TreeNode *root = new TreeNode( preorder[ preStartIndex ] );
        int rootIndex = inStartIndex;
        for( ; rootIndex <= inEndIndex; ++rootIndex)
            if( preorder[ preStartIndex ] == inorder[ rootIndex ] )
                break;
        int length = rootIndex  - inStartIndex;
        root->left = creatTreeNode( preorder, inorder, preStartIndex + 1, preEndIndex, inStartIndex, rootIndex - 1 );
        root->right = creatTreeNode( preorder, inorder, preStartIndex + length + 1, preEndIndex, rootIndex + 1, inEndIndex );
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if( preorder.size() <= 0 || inorder.size() <= 0 )
            return nullptr;
        return creatTreeNode( preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1 );
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}