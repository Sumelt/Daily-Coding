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
private:
	int TraversingList( ListNode* phead ){
		int count = 0;
		for( auto ptr = phead; ptr != nullptr; ptr = ptr->next )
			++count;
		return count;
	}
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if( pHead1 == nullptr || pHead2 == nullptr )
        	return nullptr;
       	ListNode *listOneIndex = pHead1;//获取长度
       	ListNode *listTwoIndex = pHead2;//获取长度
       	int res = TraversingList( pHead1 ) - TraversingList( pHead2 );//得到差值
		//让长的链表先走res步
        if( res < 0 )
			for( int i = 0; i < abs( res ); ++i )
				listTwoIndex = listTwoIndex->next;
		else
			for( int i = 0; i < abs( res ); ++i )
				listOneIndex = listOneIndex->next;			
  		//两链表同时走
  		for( ; listOneIndex != nullptr && listTwoIndex != nullptr && 
		  		listTwoIndex != listOneIndex;
				listOneIndex = listOneIndex->next, 
					listTwoIndex = listTwoIndex->next );
	  	//判断是不是第一个公共节点
        if( listOneIndex != nullptr && listTwoIndex != nullptr && 
			  	listOneIndex == listTwoIndex )
	  		return listOneIndex;
	  		
  		return nullptr;
    }
};

int main(int argc, char *argv[])
{
	Solution oj;
	
	return 0;
}