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
    void deleteNode( ListNode** pHead, ListNode *pToBeDeleter )
    {		
		if( pHead == nullptr || pToBeDeleter == nullptr )
			return;
			
		//只有一个节点并且删除该节点 
		if( *pHead == pToBeDeleter && pToBeDeleter->next == nullptr ) {
				delete pToBeDeleter;
				*pHead = nullptr;				
		}
		//多节点删除尾节点
		else if( *pHead != pToBeDeleter && pToBeDeleter->next == nullptr ) {
			while( (*pHead)->next != pToBeDeleter )
				(*pHead) = (*pHead)->next;
			(*pHead)->next = nullptr; //断开连接 
			delete pToBeDeleter;		
		}
		//多节点删除不是尾节点
		else {
			ListNode *tmPtr = pToBeDeleter->next;
			pToBeDeleter->val = tmPtr->val;
			pToBeDeleter->next = tmPtr->next;
			delete tmPtr;
		}			 		 
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}