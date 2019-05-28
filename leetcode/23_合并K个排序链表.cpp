/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <functional>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool cmp( ListNode* list1, ListNode* list2 ) {
	return list1->val > list2->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if( lists.size() == 0 )
        	return nullptr;
  		ListNode *res = nullptr;
       	priority_queue<ListNode*, vector<ListNode*>, 
		   			function<bool( ListNode*, ListNode* )>>que( cmp );
   		for( ListNode* node = lists[ 0 ]; node != nullptr; node = node->next )
   			que.push( node );				
						
       	for( int i = 1; i < lists.size(); ++i ) {
       		ListNode* node = lists[ i ];
			while( !que.empty() && node	!= nullptr ) {
				ListNode* head = que.top();
				if( head->val < node->val )
					head->next = node;
				else node->next = head;
				que.pop();
				node = node->next
			}
    	}
       		
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}