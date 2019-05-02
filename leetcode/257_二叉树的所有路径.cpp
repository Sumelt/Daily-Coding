/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;


  //Definition for a binary tree node.
  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
		vector<string>res;
        if( root == nullptr )
        	return res;
       	if( root->left == nullptr && root->right == nullptr ) { //叶节点
	       		res.push_back( to_string( root->val ) );
	       		return res;
	       }
       			
		auto savres = binaryTreePaths( root->left );//左子树中的路径
		for( int i = 0; i < savres.size(); ++i )
			res.push_back( to_string( root->val ) + "->" + savres[ i ] );//路径的首位置加上根节点
			
		savres = binaryTreePaths( root->right );//右子树中的路径
		for( int i = 0; i < savres.size(); ++i )
			res.push_back( to_string( root->val ) + "->" + savres[ i ] );
		
		return res;			
    }
};;

int main(int argc, char *argv[])
{
	
	return 0;
}