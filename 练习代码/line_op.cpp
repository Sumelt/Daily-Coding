/*----------------------------------------------------------------

* @Author: Su

* @Description: 链表操作集，用C++练习 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string>

using namespace std;

struct node{
	int data;
	node *next;
};

//struct stanode{
//	int data;
//	int next;
//}stanodes[max];


typedef struct node* Node;

Node creation(int* element)
{
	Node pr = new node;
	
	if(element!=NULL)
		(*pr).data = *element;
	else pr->data = 0;
	
	pr->next = NULL;
	
	return pr;
}

void print(Node head)
{
	Node p = head->next;
	while(p!=NULL)
	{
		cout<<p->data;
		p = p->next;
	}
		
}


Node insert(Node head,int element, int ads)
{
	Node p = head->next;
	
	for(int i = 1; i<ads; i++)
		p = p->next;
	Node aim = creation(&element);
	aim->next = p->next;
	p->next = aim;
	
	return head;
}

Node del(Node head, int aimele)
{
	Node pt = head->next;
	Node p;
	for(;pt->data!=aimele; pt = pt->next){
		p = pt;
	}
	p->next = pt->next;
	delete(pt);
	return head;
} 


int main(int argc, char *argv[])
{
	Node head;
	int cnt;
	
	head = creation(NULL);
	Node tp = head;
	cin>>cnt;
	
	for(int i =1; i<=cnt; i++)
	{
		
		Node p = creation(&i);
		tp->next = p;
		tp = p;
	}
	
	insert(head, 8, 4);
	del(head, 3);
	print(head);
	
	return 0;
}

//void()
//{
////	int* p = (int*)malloc(sizeof(int));
////	node* p = (node*)malloc(sizeof(node));
////	free(p);
//	int *p = new int;
//	node *p = new node;
//	delete(node);
//}




