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
	void ConvertNode( TreeNode *curNode, TreeNode *&connectNode )//这里必须是指针的指针
	{
		if( curNode == nullptr )
			return;
		
		if( curNode->left != nullptr )
			ConvertNode( curNode->left, connectNode );//不断遍历到左子树的叶节点
		curNode->left = connectNode;//该节点的左指针指向要连接的节点，也就是双向链表中该节点的前指针
		
		if( connectNode != nullptr )//连接节点不为空情况下
			connectNode->right = curNode;//连接节点的右指针指向当前的节点，即是双向链表中该节点的后指针
		connectNode = curNode;//要连接节点上移，变成当前的节点
		
		if( curNode->right != nullptr )
			ConvertNode( curNode->right, connectNode );//当前节点下移，递归右子树
	}
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if( pRootOfTree == nullptr )
        	return nullptr;
       	TreeNode *connectNode = nullptr;
       	ConvertNode( pRootOfTree, connectNode );//调用之后connectNode称为尾节点
       	TreeNode *listHead =  connectNode;//指向尾节点
       	
       	while( listHead != nullptr && listHead->left != nullptr ) //寻找链表的头节点
       		listHead = listHead->left;//不断往前找
      		
  		return listHead;
    }
};


int main(int argc, char *argv[])
{
	
	return 0;
}