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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	ListNode *resList;			
	ListNode* merge( ListNode *list1, ListNode* list2 ) {
		if( !list1 )
			return list2;
		if( !list2 )	
			return list1;
			
		ListNode *listHead = nullptr;//本次递归的节点		
		if( list1->val < list2->val ) {
			listHead = list1;
			list1->next = merge( list1->next, list2 );
		}
		else {
			listHead = list2;
			list2->next = merge( list1, list2->next );			
		}
		return listHead;
	}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if( lists.size() == 0 )
        	return nullptr;       	
		else if( lists.size() == 1 )//数组中只有一条链表直接返回
			return lists[ 0 ];
			
		resList = merge( lists[ 0 ], lists[ 1 ] );//先利用两条链表生成一条排序链表
		
		for( int i = 2; i < lists.size(); ++i )
			resList = merge( resList, lists[ i ] );//再用生成的排序链表和数组中的链表彼此归并
		return resList;
    }
};

class Solution2 {
private:
	ListNode *resList;			
	ListNode* merge( ListNode *list1, ListNode* list2 ) {
		if( !list1 )
			return list2;
		if( !list2 )	
			return list1;
			
		ListNode *listHead = nullptr;//本次递归的节点		
		if( list1->val < list2->val ) {
			listHead = list1;
			list1->next = merge( list1->next, list2 );
		}
		else {
			listHead = list2;
			list2->next = merge( list1, list2->next );			
		}
		return listHead;
	}
	ListNode* divide( vector<ListNode*>& lists, 
							int leftStartIndex, int rightEndIndex )
	{
		if( leftStartIndex >= rightEndIndex )
			return lists[ leftStartIndex ];
		int midIndex = ( leftStartIndex + rightEndIndex ) >> 1;
		ListNode *leftList = divide( lists, leftStartIndex, midIndex );
		ListNode *rightList = divide( lists, midIndex + 1, rightEndIndex );
		return merge( leftList, rightList );
		
	} 
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if( lists.size() == 0 )
        	return nullptr;       	
		else if( lists.size() == 1 )//数组中只有一条链表直接返回
			return lists[ 0 ];
		return divide( lists, 0, lists.size() - 1 );
    }
};

bool cmp( ListNode* list1, ListNode* list2 ) {
	return list1->val > list2->val;
}
class Solution3 {				
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if( lists.size() == 0 )
        	return nullptr;       	
		else if( lists.size() == 1 )//数组中只有一条链表直接返回
			return lists[ 0 ];
   		priority_queue<ListNode*, vector<ListNode*>, 
				function<bool( ListNode*, ListNode* )> > que( cmp );	
		ListNode *nullNode = new ListNode( -1 );
		ListNode *node = nullNode;
		
		for( int i = 0; i < lists.size(); ++i )
            if( lists[ i ] != nullptr )
                que.push( lists[ i ] );

		while( !que.empty() ) {
			node->next = que.top();
			node = node->next;
            que.pop();
			if( node->next != nullptr )
				que.push( node->next );			
		}
		return nullNode->next;
    }
};

int main(int argc, char *argv[])
{
	vector<ListNode*>vec;
	ListNode *list1 = new ListNode( 5 );
	ListNode *list2 = new ListNode( 2 );
	vec.push_back( list1 );
	vec.push_back( list2 );
	Solution2 oj;
	auto ls = oj.mergeKLists( vec );
	cout << ls->val;
	ls = ls->next;
	cout << ls->val;
	return 0;
}