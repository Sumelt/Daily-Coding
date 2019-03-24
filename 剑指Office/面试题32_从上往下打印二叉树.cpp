/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <queue>
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
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		if( root == nullptr )
			return vector<int>();
		vector<int>res;
		queue<TreeNode*>que;//存放树节点的指针队列，只能存放指针
		que.push( root );
		while( !que.empty() )//队列不为空
		{
			TreeNode *topNode = que.front();//拿到队列的首元素
			que.pop();//队列头元素出队
			res.push_back( topNode->val );
			if( topNode->left != nullptr )//左子节点入队
				que.push( topNode->left );
			if( topNode->right != nullptr )//右子节点入队
				que.push( topNode->right );
		}
		return res;					
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}