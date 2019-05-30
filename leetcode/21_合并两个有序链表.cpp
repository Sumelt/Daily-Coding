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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if( l1 == nullptr  )
        	return l2;
       	if( l2 == nullptr )
       		return l1;

  		ListNode* newList = nullptr;
  		if( l1->val < l2->val ) {
			newList = l1;
			newList = mergeTwoLists( l1->next, l2 );
		}
		else {
			newList = l2;
			newList->next = mergeTwoLists( l1, l2->next );
		}
  		return newList;		
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}