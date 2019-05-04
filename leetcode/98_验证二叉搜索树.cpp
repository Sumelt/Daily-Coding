/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	bool res = true;
	stack<int>stk;
	void judgeBST( TreeNode* root ) {
		if( root == nullptr )
			return ;
			
		judgeBST( root->left );
        
		if( stk.size() == 0 )//栈中没有元素则表示将压入第一个元素，直接压入
			stk.push( root->val );
       //元素压入前都要判断要压入的元素是否大于栈顶元素
		else if( stk.size() > 0 && root->val <= stk.top() ) {
			res = false;
			return ;
		}
		else stk.push( root->val );		
        
		judgeBST( root->right );		
	}
public:
    bool isValidBST(TreeNode* root) {
        judgeBST( root );
        return res;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}