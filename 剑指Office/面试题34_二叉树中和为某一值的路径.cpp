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
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
private:
	vector<vector<int> >res;
	int requestNumber; 
public:
	void getPath( TreeNode* root, vector<int>nowRes, int sum ) {
		if( root == nullptr )
			return;
			
		nowRes.push_back( root->val );
		sum += root->val;
		if( sum == requestNumber && 
			root->left == nullptr && root->right == nullptr ) {
				res.push_back( nowRes );
				return;
			}			
		getPath( root->left, nowRes, sum );
		getPath( root->right, nowRes, sum );
		
	}
	
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		if( root == nullptr || expectNumber == 0 )
			return vector<vector<int> >();
		requestNumber = expectNumber;
		getPath( root, vector<int>(), 0 );		
		return res;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}