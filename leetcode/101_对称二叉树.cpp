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
private:
    bool judge( TreeNode* leftreeNode, TreeNode* rightreeNode ) {
        if( leftreeNode == nullptr && rightreeNode == nullptr )
            return true;    	
        if( leftreeNode == nullptr || rightreeNode == nullptr )
            return false;
		if( leftreeNode->val != rightreeNode->val )
			return false;
			
   		return judge( leftreeNode->left, rightreeNode->right ) &&
                	judge( leftreeNode->right, rightreeNode->left );        
    }
public:
    bool isSymmetric(TreeNode* root) {
        if( !root )
            return true;
        return judge( root, root );
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}