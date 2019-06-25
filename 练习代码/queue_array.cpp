/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string>

#define max 100

using namespace std;


int front = -1, rear = -1;
int q[max] = {0};


void clear(){
	front = rear = -1;
}

int size(){
	return rear-front;
}

bool empty(){
	if(front==rear)
		return true;
	else return false;
}

void push(int x){
	q[++rear] = x;
}

void  pop(){
	front++;
}

int get_front()
{
	return q[front];
}

int get_back()
{
	return q[rear];
}

void print(){
	for(int i = front+1; i<=rear; i++)
		cout<<q[i]<<' ';
}

int main(int argc, char *argv[])
{
	clear();
	push(3);
	push(6);
	pop();
	print();
	return 0;
}




