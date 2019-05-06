/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	TreeNode* maxNode( TreeNode *root ) {
		if( root == nullptr )
			return nullptr;
		if( root->right == nullptr )
			return root;
		root = maxNode( root->right );
		
		return root;
	}
	
    TreeNode* minNode( TreeNode *root ) {
        if( root == nullptr )
            return nullptr;
        if( root->left == nullptr )
            return root;
        root = minNode( root->left );

        return root;
    }
    TreeNode* successor( TreeNode *root ) {
        root = minNode( root );
        return root;
    }

    TreeNode* predecessor( TreeNode *root ) {
        root = maxNode( root );
        return root;
    }
    //删除后继节点
    TreeNode* removeMinNode( TreeNode *root ) {
        if( root->left == nullptr ) {
            TreeNode *rightNode = root->right;
            delete root;
            return rightNode;
        }
        else root->left = removeMinNode( root->left );
        return root;
    }
	//删除前继节点
    TreeNode* removeMaxNode( TreeNode *root ) {
        if( root->right == nullptr ) {
            TreeNode *leftNode = root->left;
            delete root;
            return leftNode;
        }
        else root->right = removeMaxNode( root->right );
        return root;
    }

    TreeNode* removeNode( TreeNode *root, int key ) {
        if( root == nullptr )
            return nullptr;
        if( root->val > key )
            root->left = removeNode( root->left, key );

        else if( root->val < key )
            root->right = removeNode( root->right, key );

        if( root->val == key ) {
            //情况一：
            if( root->left != nullptr && root->right != nullptr ) {
                //方法一：后继节点 
                //TreeNode *succNode = successor( root->right );
                //root->val = succNode->val;
                //root->right = removeMinNode( root->right ); //难点
				
                //方法二：前继节点 
                TreeNode *preNode = predecessor( root->left );
                root->val = preNode->val; 
                root->left = removeMaxNode( root->left ); //难点

                return root;
            }
            //情况二：
            else if( root->left ) {
                TreeNode *leftNode = root->left;
                delete root;
                return leftNode;
            }
            else if( root->right ) {
                TreeNode *rightNode = root->right;
                delete root;
                return rightNode;		 			
            }
            //情况三：（情况二和三可以融合写在一起）
            else{
                delete root;
                return nullptr;
            }
        }
        return root;
    }
	
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
		root = removeNode( root, key );
		return root;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}