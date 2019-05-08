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
	stack<TreeNode*>stackP;
	stack<TreeNode*>stackQ;
	void savePath( TreeNode *root, TreeNode *destination, stack<TreeNode*>&stack ) {
		if( root == nullptr )
			return;
		stack.push( root );
		if( stack.top()->val == destination->val )
			return;
		savePath( root->left, destination, stack );
		savePath( root->right, destination, stack );
		if( stack.top()->val != destination->val )
			stack.pop();
	}
	
	TreeNode* retAncestor( stack<TreeNode*> &stackP, stack<TreeNode*> &stackQ ) {
		if( stackP.size() > stackQ.size() ) {
			int diff = stackP.size() - stackQ.size();
			for( int i = 0; i < diff; ++i )
				stackP.pop();
		}
		else if( stackP.size() < stackQ.size() ) {
			int diff = stackQ.size() - stackP.size();
			for( int i = 0; i < diff; ++i )
				stackQ.pop();			
		}
		
		while( !stackP.empty() && !stackQ.empty() ) {
			if( stackP.top()->val == stackQ.top()->val )
				return stackP.top();
			stackQ.pop();
			stackP.pop();
		}
		return nullptr;
	}
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ancestor = nullptr;
		if( root == nullptr )
        	return ancestor;
       	savePath( root, p, stackP );
       	savePath( root, q, stackQ );
       	if( !stackQ.size() || !stackP.size() )
       		return nullptr;
  		else
			ancestor = retAncestor( stackP, stackQ );
		return ancestor;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}