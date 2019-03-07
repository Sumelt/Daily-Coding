/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;


struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next; //指向父节点 
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

TreeLinkNode* GetNext(TreeLinkNode* pNode) {
    if( pNode == nullptr ) return nullptr;
    
    TreeLinkNode *TreeNodeNext = nullptr;
    if( pNode->right ) { //判断有无右节点 
    	TreeNodeNext = pNode->right;
		while( TreeNodeNext->left != nullptr )
			TreeNodeNext = TreeNodeNext->left;
    }
    else {
    	if( pNode->next ) { //判断有无父节点 
	    	TreeLinkNode *currNode = pNode;
	    	TreeNodeNext = pNode->next; //当前节点的父节点 
	    	while( TreeNodeNext != nullptr && currNode != TreeNodeNext->left ) //父节点不空 并且当前节点不是 它父节点的左节点 
    		{
	    		currNode = TreeNodeNext; //向上遍历 
				TreeNodeNext = TreeNodeNext->next;	    		
	    	}
	    }
    }
    return TreeNodeNext;
}

int main(int argc, char *argv[])
{
	
	return 0;
}