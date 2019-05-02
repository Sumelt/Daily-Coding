/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	pair<int, bool>Recursive( TreeNode *root ) {
		if( root == nullptr )
			return pair<int, bool>( 0, true );
		auto leftPair = Recursive( root->left );
		auto rightPair = Recursive( root->right );
		
		//不平衡的情况有3种：左树不平衡、右树不平衡、左树和右树差的绝对值大于1
		if( ( !leftPair.second || !rightPair.second ) || 
			leftPair.first == -1 || rightPair.first == -1  )
			return pair<int, bool>( -1, false );
			
		int maxValue = max( leftPair.first, rightPair.first ) + 1;	
		bool res = abs( leftPair.first - rightPair.first ) > 1 ? false : true;
		return pair<int, bool>( maxValue, res );
	}
public:
    bool isBalanced(TreeNode* root) {
    	return Recursive( root ).second;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}