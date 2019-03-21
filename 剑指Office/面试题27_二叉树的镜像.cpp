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

void Mirror2( TreeNode *pRoot ) {
	if( pRoot == nullptr )
		return;
	swap( pRoot->left, pRoot->right );
	Mirror2( pRoot->left );
	Mirror2( pRoot->right );
}

void Mirror( TreeNode *pRoot ) {
	if( pRoot == nullptr || ( !pRoot->left && !pRoot->right ) )
		return;
	TreeNode *temp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = temp;
	
	Mirror( pRoot->left );
	Mirror( pRoot->right );	
}

int main(int argc, char *argv[])
{
	
	return 0;
}