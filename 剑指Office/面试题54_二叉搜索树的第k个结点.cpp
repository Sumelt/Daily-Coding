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
private:
	int curK = 0;
	TreeNode *Knode = nullptr;//要返回的节点
	void findKnode( TreeNode* pRoot, int k ){
		if( pRoot == nullptr )
			return;
        //中序遍历
		findKnode( pRoot->left, k );//遍历左节点	
		++curK;	//累计访问的节点数
		if( curK == k ){ //找到目标节点
			Knode = pRoot;
			return;	
		}		
		findKnode( pRoot->right, k );//遍历右节点
	}
public:
    TreeNode* KthNode(TreeNode* pRoot, int k){
		if( pRoot == nullptr || k == 0 )
			return nullptr;
		findKnode( pRoot, k );
		return Knode;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}