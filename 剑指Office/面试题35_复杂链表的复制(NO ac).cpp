/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};


//class Solution {
//public:
    
    void CloneNode( RandomListNode* &pHead )
    {   	
		if( pHead != nullptr ) {
			RandomListNode *newNode = new RandomListNode( pHead->label );
			RandomListNode *curNodenext = pHead->next;
			pHead->next = newNode;
			newNode->next = curNodenext;
			CloneNode( newNode->next );						
		}
		else return;	
    } 
	
	void CloneNodeRandomPtr( RandomListNode* &pHead )
	{
		if( pHead == nullptr )
			return;
		RandomListNode *randomNode = pHead->random;
		if( randomNode != nullptr )
			pHead->next->random = randomNode->next;
		CloneNodeRandomPtr( pHead->next->next );
	}
	
	RandomListNode *CloneNodeSeparation( RandomListNode* &pHead ) {		
		if( pHead == nullptr )
			return nullptr;
		RandomListNode *CloneNode = pHead->next;
		if( CloneNode->next == nullptr )
			CloneNode->next = nullptr;
		else {
			CloneNode->next = CloneNodeSeparation( pHead->next->next );
			pHead->next = CloneNode->next;
		} 
		return CloneNode;
	} 
	
	RandomListNode* Clone(RandomListNode* pHead)
    {
        if( pHead == nullptr )
        	return nullptr;
       	RandomListNode *head = pHead;
       	CloneNode( pHead );
       	//pHead = head;
       	CloneNodeRandomPtr( pHead );
       	//pHead = head;     	
       	return CloneNodeSeparation( head );
    }
//};

using namespace std;
int main(int argc, char *argv[])
{
	RandomListNode* node = new RandomListNode( 3 );
	RandomListNode* node2 = new RandomListNode( 4 );
	node->next = node2;
	RandomListNode *temp = Clone( node );
//	cout << temp << ' ' << node << endl;
//	cout << temp->next << ' ' << node2 << endl;
	while( temp != nullptr ) {
		cout << temp->label << ' ';
		temp = temp->next;
	}
		
	return 0;
}