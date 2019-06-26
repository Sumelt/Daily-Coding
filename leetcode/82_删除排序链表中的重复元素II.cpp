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
		ListNode* preNode = nullptr;
       	while( curNode != nullptr && curNode->next != nullptr ) {
	    	
			if( curNode->val == curNode->next->val ) {
				int sameVal = curNode->val;
				while( curNode != nullptr && curNode->val == sameVal ) {
					ListNode* delNode = curNode;
					curNode = curNode->next;
					delete delNode;
				}
				if( preNode == nullptr )
					head = curNode;
				else if( curNode != nullptr )
					preNode->next = curNode;
				else preNode->next = nullptr;			
			}
			else {
				preNode = curNode;
				curNode = curNode->next;
			}
    	}
       	return head;
    }
};


int main(int argc, char *argv[])
{
	
	return 0;
}