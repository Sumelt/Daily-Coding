/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
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
    int TreeDepth(TreeNode* pRoot)
    {
		if( pRoot == nullptr )
			return 0;
		int leftMaxDeep = TreeDepth( pRoot->left );
		int rightMaxDeep  =TreeDepth( pRoot->right );
		
		return ( leftMaxDeep > rightMaxDeep  ) ? ( leftMaxDeep + 1 ) :
			( rightMaxDeep + 1 );
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}