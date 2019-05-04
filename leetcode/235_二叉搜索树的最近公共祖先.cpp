/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( root == nullptr )
        	return nullptr;
       	if( p->val > root->val && q->val > root->val )
       		root = lowestCommonAncestor( root->right, p, q );
  		if( p->val < root->val && q->val < root->val )
  			root = lowestCommonAncestor( root->left, p, q );
  			
		return root;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}