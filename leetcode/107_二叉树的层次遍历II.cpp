/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>>res;
		queue<pair<TreeNode*, int>>que;
		
		if( root == nullptr )
			return res;
		que.push( make_pair( root, 0 ) );
		while( !que.empty() ) {
			TreeNode *node = que.front().first;
			int level = que.front().second;
			que.pop();
			if( level == res.size() )
				res.push_back( vector<int>() );
				
			res[ level ].push_back( node->val );
			
			if( node->left )
				que.push( make_pair( node->left, level + 1 ) );
			
			if( node->right )
				que.push( make_pair( node->right, level + 1 ) );	
		}
		return vector<vector<int>>( res.rbegin(), res.rend() );
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}