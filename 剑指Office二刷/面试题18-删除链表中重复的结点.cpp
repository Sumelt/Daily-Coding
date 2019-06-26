/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
		if( pHead == nullptr )
			return nullptr;
		ListNode* prNode = nullptr;
		ListNode* curNode = pHead;
		
		while( curNode != nullptr && curNode->next != nullptr ) {
			
			if( curNode->val == curNode->next->val ) {
				int sameVal = curNode->val;
				while( curNode != nullptr && curNode->val == sameVal ) {
					ListNode* delNode = curNode;
					curNode = curNode->next;
					delete delNode;
				}
				//删除的是头节点 
				if( prNode == nullptr )
					pHead = curNode;
				//删除的是中间节点 
				else if( curNode != nullptr )
					prNode->next = curNode;
				//删除的是尾节点 
				else prNode->next = nullptr;
			}
			else {
				//遍历下一个节点 
				prNode = curNode;
				curNode = curNode->next;
			}
		}
		return pHead;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}