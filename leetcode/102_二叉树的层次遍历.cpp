/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <queue>
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        vector<int>curRes;
        if( !root )
        	return res;
       	queue<TreeNode*>que;
   	
        que.push( root );
        
        while( !que.empty() ) {
			int levelCount = que.size();
			while( levelCount > 0 ) {
				TreeNode *node = que.front();
				que.pop();
				curRes.push_back( node->val );
				--levelCount;
				
				if( node->left )
					que.push( node->left );
				if( node->right )
					que.push( node->right );
				
			}
			res.push_back( curRes );
			curRes.clear();
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
	Solution oj;
	TreeNode root( 3 );
	auto res = oj.levelOrder( &root );
	cout << res[ 0 ][ 0 ];
	return 0;
}