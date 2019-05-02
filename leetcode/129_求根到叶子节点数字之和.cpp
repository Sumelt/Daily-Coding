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

class Solution {
private:   
    vector<vector<int>>res;
    vector<int>savres;
    void findPath( TreeNode* root ) {		
		if( root == nullptr )
 			return ;
 			
        if( root->left == nullptr && root->right == nullptr ) { //遇到叶节点     	
			savres.push_back( root->val );//压入叶节点       	
        	res.push_back( savres );//找到一条路径
        	savres.pop_back();//弹出最后一个节点，回到上一个节点
        	return ;		
        }
        else savres.push_back( root->val );
        
		findPath( root->left );//左子树		
		findPath( root->right );//右子树
		savres.pop_back();//该节点的左右子树都遍历了，则也要回到上一个节点
    }
public:
    int sumNumbers( TreeNode* root ) {
        if( root == nullptr )
            return 0;
        int calRes = 0;
        findPath( root );
        
        for( int i = 0; i < res.size(); ++i ) {
			int nowRes = 0;
			for( int j = 0; j < res[ i ].size(); ++j )
				nowRes = nowRes *10 + res[ i ][ j ];
			calRes += nowRes;
        }       
        return calRes;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}