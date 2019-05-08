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
	struct command {
		bool out;
		TreeNode *root;
		command( bool flag, TreeNode *node ) : out( flag ), root( node ) {}
	};
	
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if( root == nullptr )
        	return res;
       	stack<command>stack;
       	stack.push( command( false, root ) );
       	
       	while( !stack.empty() ) {
       		command front = stack.top();
       		stack.pop();
	    	if( front.out )
	    		res.push_back( front.root->val );
    		else {
	    		if( front.root->right )
	    			stack.push( command( false, front.root->right ) );
	    			
				stack.push( command( true, front.root ) );	    			
	   			
	   			if( front.root->left )
	   				stack.push( command( false, front.root->left ) );
		    }
    	}
    	return res;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}