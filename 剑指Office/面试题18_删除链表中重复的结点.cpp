/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication( ListNode* pHead )
    {
		if( pHead == nullptr )
			return nullptr;
		ListNode* curPtr = pHead; //当前的节点指针
		ListNode* prPtr = nullptr;//当前节点的前一个节点指针
		while( curPtr != nullptr && curPtr->next != nullptr )//当前节点不空并且有下一个节点
		{
			if( curPtr->val == curPtr->next->val ) { //找到重复的节点，这里成功的前提是curPtr指针存在下一个节点
				int sameValue = curPtr->val; //保存要删除的值 
				while( curPtr != nullptr && curPtr->val == sameValue ) //删除相同值 
				{
					ListNode* deleteNodePtr = curPtr;
					curPtr = curPtr->next;
					delete deleteNodePtr;
				}
				if( prPtr == nullptr ) //删除都是头节点 
					pHead = curPtr; //头结点要重新指向
				else if( curPtr != nullptr ) prPtr->next = curPtr; //删除的是中间节点并联结上 
				else prPtr->next = nullptr; //删除的是尾节点，并且当前节点curPtr指针为空
			}
			else { //没有重复的节点，遍历下一个 
				prPtr = curPtr;
				curPtr = curPtr->next;
			} 
		}
		return pHead;			
    }
};

int main(int argc, char *argv[])
{
	ListNode* node1 = new ListNode( 2 );
	ListNode* node2 = new ListNode( 2 );
	ListNode* node3 = new ListNode( 1 );
	ListNode* node4 = new ListNode( 3 );
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = nullptr;
	ListNode* head =   deleteDuplication( node1 );
	while( head != nullptr ) {
		cout << head->val << " ";
		head = head->next;
	}
		
	return 0;
}