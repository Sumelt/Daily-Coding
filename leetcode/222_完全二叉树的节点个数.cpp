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
    int count = 0;
    void cal( TreeNode* root ) {
        if( root == nullptr )
            return;
        ++count;
        if( root->left != nullptr ) {
            cal( root->left );
            cal( root->right );
        }            
        else return;      
    }
public:
    int countNodes(TreeNode* root) {
        if( root == nullptr )
            return 0;
        cal( root );
        return count;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}