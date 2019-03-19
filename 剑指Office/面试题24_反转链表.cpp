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

ListNode* ReverseList(ListNode* pHead) {
	if( pHead == nullptr )
		return nullptr;
	ListNode *forwardPtr = nullptr;
	ListNode *ownPtr = pHead;
	ListNode *nextPtr = ownPtr->next;

	while( ownPtr != nullptr ) {
		ownPtr->next = forwardPtr;
		forwardPtr = ownPtr;
		ownPtr = nextPtr;
		if( ownPtr != nullptr )
			nextPtr = ownPtr->next;
	}
	return forwardPtr;
}


int main(int argc, char *argv[])
{
	ListNode *node1 = new ListNode( 1 );
	ListNode *node2 = new ListNode( 2 );
	ListNode *node3 = new ListNode( 3 );
	node1->next = node2;
	node2->next = node3;
 	ListNode  *temp =  ReverseList( node1 );
	while( temp != nullptr ){
		cout << temp->val;
		temp = temp->next;
	}
		
	return 0;
}