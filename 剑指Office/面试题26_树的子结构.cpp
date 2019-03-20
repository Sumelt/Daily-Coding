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

bool judgeStruct(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if( !pRoot2 )
		return true;
	if( !pRoot1 )
		return false;
	bool res = false;
	
	res = judgeStruct( pRoot1->left, pRoot2->left ) &&
		judgeStruct( pRoot1->right, pRoot2->right );
	return res;
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if( pRoot1 == nullptr || pRoot2 == nullptr )
		return false;
	bool res = false;	
	if( pRoot1->val == pRoot2->val )
		res = judgeStruct( pRoot1, pRoot2 );
	if( !res )
		res = HasSubtree( pRoot1->left, pRoot2 );
	if( !res )
		res = HasSubtree( pRoot1->right, pRoot2 );
	return res;
}

int main(int argc, char *argv[])
{
	
	return 0;
}