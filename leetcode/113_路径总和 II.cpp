/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:   
    vector<vector<int>>res;
    vector<int>savres;
    void findPath( TreeNode* root, int sum ) {		
		if( root == nullptr )
 			return ;
 			
        if( root->left == nullptr && root->right == nullptr ) { //遇到叶节点     	
			if( root->val == sum ) { //判断叶节点是否是目标值
				savres.push_back( root->val );//压入叶节点       	
	        	res.push_back( savres );//找到一条路径
	        	savres.pop_back();//弹出最后一个节点，回到上一个节点
	        	return ;
	        }
	        else return ;//不符合目标值什么也不做			
        }
        else savres.push_back( root->val );
        
		findPath( root->left, sum - root->val );//左子树		
		findPath( root->right, sum - root->val );//右子树
		savres.pop_back();//该节点的左右子树都遍历了，则也要回到上一个节点
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if( root == nullptr )
            return res;
        findPath( root, sum );
        
        return res;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}