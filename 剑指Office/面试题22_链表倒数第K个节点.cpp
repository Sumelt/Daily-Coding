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

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if( pListHead == nullptr || k == 0 )
    	return nullptr;
   	ListNode *forwardPtr = pListHead;
   	ListNode *afterPtr = pListHead;
   	
   	for( int i = 0; i < k - 1; ++i )
   		if( forwardPtr->next != nullptr ) forwardPtr = forwardPtr->next;
   		else return nullptr;
	for( ; forwardPtr->next != nullptr; forwardPtr = forwardPtr->next )
		afterPtr = afterPtr->next;
	return afterPtr;
   		
}

int main(int argc, char *argv[])
{
	
	return 0;
}