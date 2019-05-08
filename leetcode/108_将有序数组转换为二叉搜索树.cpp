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
	TreeNode *creatBST( int leftIndexBegin, int rightIndexEnd, vector<int>& vec ) {
		if( leftIndexBegin > rightIndexEnd )
			return nullptr;
		int midIndex = ( leftIndexBegin + rightIndexEnd ) >> 1;
		TreeNode *root = new TreeNode( vec[ midIndex ] );
		root->left = creatBST( leftIndexBegin, midIndex - 1, vec );
		root->right = creatBST( midIndex + 1, rightIndexEnd, vec );
		
		return root;
	}
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if( nums.size() == 0 )
        	return nullptr;
        	
		int mid = nums.size() >> 1;
		TreeNode *root = new TreeNode( nums[ mid ] );
		root->left = creatBST( 0, mid - 1, nums );
		root->right = creatBST( mid + 1, nums.size() - 1, nums );
		
		return root;     	
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}