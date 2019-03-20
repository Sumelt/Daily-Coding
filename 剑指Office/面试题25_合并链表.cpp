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

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if( pHead1 == nullptr ) //表1空 合并后的链表就是表2
        return pHead2;
    if( pHead2 == nullptr )
        return pHead1;
     
    ListNode *newList = nullptr;
    ListNode *newListHead = nullptr;//头节点
    while( pHead1 != nullptr && pHead2 != nullptr )
    {
        if(  pHead1->val < pHead2->val ){
            if( newList == nullptr )
                newListHead = newList = pHead1; //获得头节点           
            else {
                newList->next = pHead1;
                newList = newList->next;//更新下一个节点
            }          
            pHead1 = pHead1->next;//更新表头            
        }
        //当节点的value值相同或者表2的头结点比表1的头节点小转入处理
        else {
		    if( newList == nullptr )
		        newListHead = newList = pHead2;             
		    else {
		        newList->next = pHead2;
		        newList = newList->next;
		    }
		    pHead2 = pHead2->next;
    	}  
    }
    
    if( pHead1 == nullptr )//连接剩余的表节点
        newList->next = pHead2;       
    else newList->next = pHead1;
		 
    return newListHead;
}

ListNode* MergeRecursive(ListNode* pHead1, ListNode* pHead2)
{
	if( pHead1 == nullptr )
        return pHead2;
    if( pHead2 == nullptr )
        return pHead1;
     
    ListNode *newList = nullptr;
    
    if( pHead1->val < pHead2->val ) {	
    	newList = pHead1;
    	newList->next = MergeRecursive( pHead1->next, pHead2 );//递归下一个节点
    }
    else {
    	newList = pHead2;
    	newList->next = MergeRecursive( pHead1, pHead2->next );
    }
    return newList;
}  


int main(int argc, char *argv[])
{
	ListNode *node1 = new ListNode( 2 );
	ListNode *node3 = new ListNode( 4 );
	ListNode *node2 = new ListNode( 1 );
	node1->next = node3;
	ListNode *temp = MergeRecursive( node1, node2 );
	
	while( temp != nullptr ) {
		
		cout << temp->val;
		temp = temp->next;	
	}
		
	
	return 0;
}