/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int count = 0;
	int res = 0;
	void Recursive( TreeNode* root, int k ) {
		if( root == nullptr )
			return;
		Recursive( root->left, k );
		++count;
		if( count == k ) {
			res = root->val;
			return;
		} 			
		Recursive( root->right, k );
	}
public:
    int kthSmallest(TreeNode* root, int k) {
        
        Recursive( root, k );
        return res;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}