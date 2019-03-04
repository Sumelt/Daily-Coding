/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
vector<int> printListFromTailToHead(ListNode* head) {
	if( head == nullptr ) return vector<int>();
	stack<int>stk;
	ListNode *ptr = head;
	vector<int>vec;
	while( ptr != nullptr ) {
		stk.push( ptr->val );
		ptr = ptr->next;
	}
		
	while( !stk.empty() ) {
		vec.push_back( stk.top() );
		stk.pop();		
	}
	return vec;	
}

int main(int argc, char *argv[])
{
	
	return 0;
}