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


bool isSymmetrical( TreeNode* pRoot1, TreeNode* pRoot2 )
{
	//同时把空节点考虑进来
    if( pRoot1 == nullptr && pRoot2 == nullptr )//如果它们都为空
		return true;
	if( pRoot1 == nullptr || pRoot2 == nullptr )//其中一个为空另一个不为空
		return false;
	if( pRoot1->val != pRoot2->val )//值不相等
		return false;
		
	//一个遍历左节点，另一个遍历右节点
    return isSymmetrical( pRoot1->left, pRoot2->right ) &&
		isSymmetrical( pRoot1->right, pRoot2->left );
}

bool isSymmetrical(TreeNode* pRoot)
{
	return isSymmetrical( pRoot, pRoot ); //交由重载函数判断
}

int main(int argc, char *argv[])
{
	
	return 0;
}