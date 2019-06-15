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
	TreeNode* CreateTree( vector<int>& pre, vector<int>& post, 
		int &preStartIndex, int preEndIndex, int postStartIndex, int postEndIndex ) {
			
			if( ( preStartIndex > preEndIndex ) 
				|| ( postStartIndex > postEndIndex ) )
				return nullptr;
				
			int rootIndex = 0;
			for( ; rootIndex <= postEndIndex; ++rootIndex )
				if( pre[ preStartIndex ] == post[ rootIndex ] )
					break;
			if( rootIndex > postEndIndex ) {
				--preStartIndex;
				return nullptr;
			}
				
				
			int length = rootIndex - postStartIndex;
			
			TreeNode *root = new TreeNode( post[ rootIndex ] );
			root->left = CreateTree( pre, post, 
				++preStartIndex, preEndIndex, 
					postStartIndex, postStartIndex + length );
			root->right = CreateTree( pre, post, 
				++preStartIndex, preEndIndex, 
					postStartIndex, postStartIndex + length );
			return root;
		}
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    	if( pre.size() == 0 || post.size() == 0 )
    		return nullptr;
		int preStartIndex = 0;
        return CreateTree( pre, post, preStartIndex, pre.size() - 1, 0, post.size() - 1 );
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}