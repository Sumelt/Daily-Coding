/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
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


class Solution {
private:
	vector<int>res;
	void PrintList( ListNode* head ) {
		if( head == nullptr )
			return;
		printListFromTailToHead( head->next );
		res.push_back( head->val );
	}
public:
    vector<int> printListFromTailToHead(ListNode* head) {
		if( head != nullptr )
			PrintList( head );
		return res;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}