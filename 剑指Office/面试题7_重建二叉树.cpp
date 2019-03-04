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

TreeNode* CreatTreeNode( vector<int> *pre,vector<int> *vin, 
	int preStartIndex, int preEndIndex, int vinStartIndex, int vinEndIndex )
{
	if( preStartIndex > preEndIndex ) return 0;
	//if( vinStartIndex > vinEndIndex  ) return 0;
	TreeNode *root = new TreeNode( ( *pre )[ preStartIndex ] );	
		
	int inRootIndex = 0;
	for( ; inRootIndex <= vinEndIndex; ++inRootIndex )
		if( ( *vin )[ inRootIndex ] == ( *pre )[ preStartIndex ] ) //找到 中序序列中的根节点 
			break;
	int Length = inRootIndex - vinStartIndex; //左子树的长度 
	root ->left = CreatTreeNode( pre, vin, 
		preStartIndex + 1, preStartIndex + Length, vinStartIndex, inRootIndex - 1 );
	root ->right = CreatTreeNode( pre, vin, 
		preStartIndex + Length + 1, preEndIndex, inRootIndex + 1, vinEndIndex );
	
	return root;
}

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
	if( pre.size() == 0 || vin.size() == 0 ) return NULL;
	int preStartIndex = 0; int vinStartIndex = 0;
	int preEndIndex = pre.size() - 1; int vinEndIndex = vin.size() - 1;
	
	return CreatTreeNode( &pre, &vin, 
		preStartIndex, preEndIndex, vinStartIndex, vinEndIndex );
}

int main(int argc, char *argv[])
{
	vector<int> pre = {1,2,4,7,3,5,6,8};
	vector<int> vin = {4,7,2,1,5,3,8,6};
	TreeNode *root = reConstructBinaryTree( pre, vin );
	cout << root->val;
	cout << root->left->val;
	cout << root->right->val;
	return 0;
}