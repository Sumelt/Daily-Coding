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

ListNode* FindMeetNode( ListNode* pHead )
{
	ListNode *forwardPtr = pHead->next; //一开始保证快指针比慢指针快一步才能相遇 
	ListNode *afterPtr = pHead;
	
	if( forwardPtr == nullptr )
		return nullptr;
		
	while( forwardPtr != nullptr && forwardPtr != afterPtr ) {
		
		forwardPtr = forwardPtr->next; //快指针走两步 
		if( forwardPtr->next != nullptr )
		forwardPtr = forwardPtr->next;
		afterPtr = afterPtr->next; //慢指针走一步 
	}
	if( afterPtr == forwardPtr ) //找到相遇的节点 
		return forwardPtr;
	else return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if( pHead == nullptr )
		return nullptr;
	ListNode *MeetNode = FindMeetNode( pHead ); //找到相遇的点 
	if( MeetNode != nullptr )
	{

		int ringNodeCount = 1;
		ListNode *forwardPtr = pHead;
		ListNode *afterPtr = pHead;
		
		ListNode *tempNodeAdress = MeetNode;
		tempNodeAdress = tempNodeAdress->next;
		while( tempNodeAdress != MeetNode ) {
			++ringNodeCount;
			tempNodeAdress = tempNodeAdress->next;
		}
		forwardPtr = pHead;
		
		for( int i = 0; i < ringNodeCount; ++i )
			forwardPtr = forwardPtr->next;
		
		while( forwardPtr != afterPtr ) {
			forwardPtr = forwardPtr->next;
			afterPtr = afterPtr->next;
		}
		if( forwardPtr == afterPtr )	
			return forwardPtr;	
	}
	return nullptr;
}

int main(int argc, char *argv[])
{
	
	return 0;
}