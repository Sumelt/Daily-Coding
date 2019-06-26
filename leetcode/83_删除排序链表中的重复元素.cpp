/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if( head == nullptr )
        	return nullptr;
       	ListNode* curNode = head;

       	while( curNode != nullptr && curNode->next != nullptr ) {
	    	
			if( curNode->val == curNode->next->val ) {
				int sameVal = curNode->val;
				ListNode *nextNode = curNode->next;
				while( nextNode != nullptr && nextNode->val == sameVal ) {
					ListNode* delNode = nextNode;
					nextNode = nextNode->next;
					delete delNode;
				}
				curNode->next = nextNode;			
			}
			else curNode = curNode->next;
    	}
       	return head;
    }
};


int main(int argc, char *argv[])
{
	
	return 0;
}