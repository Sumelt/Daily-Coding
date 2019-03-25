/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
    	if( pRoot == nullptr )
    		return vector< vector<int> >();
    	vector<int> nowRes;
		vector< vector<int>	>res;
		int nowsum = 1;
		int nextSum = 0;
		
		queue<TreeNode*>que;
		que.push( pRoot );
		
		while( !que.empty() ) {
			TreeNode *topNode = que.front();
			que.pop();
			--nowsum;
			nowRes.push_back( topNode->val );
			if( topNode->left != nullptr ) {
				que.push( topNode->left );
				++nextSum;
			}
			if( topNode->right != nullptr ) {
				que.push( topNode->right );
				++nextSum;
			}
			if( nowsum == 0 ) {
				nowsum = nextSum;
				nextSum = 0;
				res.push_back( nowRes );
				nowRes.clear();
			}			
		}
		return res;		
    }   
};

int main(int argc, char *argv[])
{
	
	return 0;
}