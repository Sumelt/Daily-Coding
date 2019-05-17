/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if( root == nullptr )
        	return vector<vector<int>>();
		stack<TreeNode*>stackLeft;
        stack<TreeNode*>stackRight;
        vector<int>curRes;
        vector<vector<int>>res;
        
        stackLeft.push( root );
        while( !stackLeft.empty() || !stackRight.empty() ) {
        	while( !stackLeft.empty() ) {
	        	TreeNode *node = stackLeft.top();
	        	stackLeft.pop();
	        	curRes.push_back( node->val );
	        	
	        	if( node->left )
	        		stackRight.push( node->left );
        		
        		if( node->right )
	        		stackRight.push( node->right );
	        }
	        if( curRes.size() > 0 )
	        	res.push_back( curRes );
	        curRes.clear();
	        
	        while( !stackRight.empty() ) {
	        	TreeNode *node = stackRight.top();
	        	stackRight.pop();
	        	curRes.push_back( node->val );
	        	
	        	if( node->right )
	        		stackLeft.push( node->right );
        		
        		if( node->left )
	        		stackLeft.push( node->left );        		
        	}
	        if( curRes.size() > 0 )
	        	res.push_back( curRes );
	        curRes.clear();        	
        }
		return res;       
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}