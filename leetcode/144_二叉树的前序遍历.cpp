/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
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
		bool out;//为真时，输出该节点
		TreeNode *root;
		command( bool flag, TreeNode *node ) : out( flag ), root( node ) {}
	};
	
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if( root == nullptr )
        	return res;
       	stack<command>stack;
       	stack.push( command( false, root ) );//先压入一个指令，然后才能压入三个关键的指令
       	
       	while( !stack.empty() ) {
       		command front = stack.top();
       		stack.pop();
	    	if( front.out )
	    		res.push_back( front.root->val );
    		else {
	    		if( front.root->right )//指令一
	    			stack.push( command( false, front.root->right ) );
	   			if( front.root->left )//指令二
	   				stack.push( command( false, front.root->left ) );
				
				stack.push( command( true, front.root ) );//指令三，最后压入最先访问
		    }
    	}
    	return res;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}