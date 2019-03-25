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
	vector<vector<int> >res;//保存的路径
	int requestNumber; //要求的值
public:
	void getPath( TreeNode* root, vector<int>nowRes, int sum ) {
		if( root == nullptr )
			return;
			
		nowRes.push_back( root->val );//保存该节点
		sum += root->val;//累计值
		if( sum == requestNumber && //访问到叶节点并且累加值恰好为所需值
			root->left == nullptr && root->right == nullptr ) {
				res.push_back( nowRes );//保存该路径
				return;
			}			
		getPath( root->left, nowRes, sum );//左节点
		getPath( root->right, nowRes, sum );//右节点	
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