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
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
private:
	stack<TreeNode*>Stack[ 2 ]; //0 odd 1 even
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
		if( pRoot == nullptr )
			return  vector<vector<int>>();
		vector< vector<int> >res;
		vector< int >oneRowRes;
		int Parity = 0; //当前的层数的奇偶性质
		Stack[ Parity ].push( pRoot );//压入根节点，根层是奇数层
		while( !Stack[ 0 ].empty() || !Stack[ 1 ].empty() )
		{
			TreeNode *topNode = Stack[ Parity ].top();
			Stack[ Parity ].pop();
			oneRowRes.push_back( topNode->val );
			//奇数层从左到右 
			if( Parity == 1 ) {//表明当前是偶数层，则左右节点需要压入奇数层
				if( topNode->right != nullptr )
					Stack[ 1 - Parity ].push( topNode->right );					
				if( topNode->left != nullptr )
					Stack[ 1 - Parity ].push( topNode->left );				
			}
			//偶数层从右到左 
			else{//表明当前是奇数层，则左右节点需要压入偶数层
				if( topNode->left != nullptr )
					Stack[ 1 - Parity ].push( topNode->left );				
				if( topNode->right != nullptr )
					Stack[ 1 - Parity ].push( topNode->right );
			}
			if( Stack[ Parity ].empty() ) {
				res.push_back( oneRowRes );//压入该层结果
				oneRowRes.clear();//该层暂存清除
				Parity = 1 - Parity;//奇偶层切换
			}
		}
		return res;		
    }		
};

int main(int argc, char *argv[])
{
	
	return 0;
}