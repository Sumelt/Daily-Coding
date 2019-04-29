/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if( root == nullptr )
            return 0;
        int leftDepth = minDepth( root->left );
        int rightDepth = minDepth( root->right );
        
        if( leftDepth && rightDepth )
            return min( leftDepth, rightDepth ) + 1;
        else return leftDepth + rightDepth + 1;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}