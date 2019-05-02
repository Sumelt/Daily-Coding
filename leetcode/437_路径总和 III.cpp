/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;

 //Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
private:
    int findPath( TreeNode* root, int sum ) {
        
        if( root == nullptr )
            return 0;
        
        int res = 0;
        if( root->val == sum )
        	res += 1;
            
        res += findPath( root->left, sum - root->val );
        res += findPath( root->right, sum - root->val );
        
        return res;
    }
public:
    int pathSum( TreeNode* root, int sum ) {
        if( root == nullptr )
            return 0;
        
        int res = findPath( root, sum );
        	res += pathSum( root->left, sum );
        	res += pathSum( root->right, sum );
        
        return res;
    }
};

int main()
{
	return 0;
}