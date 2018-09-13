/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 31/08/18 10:22

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
	queue <int> que;
	for(int i = 0; i<5; i++)
		que.push(i);
	if(!que.empty())
		{
			que.pop();
			cout<<que.front();
			cout<<endl;			
			cout<<que.back();
		}
	cout<<endl<<"queue size:"<<que.size()<<endl;	
	/*********************/
	priority_queue<int> pq;
	for(int i = 0; i<5; i++)
		pq.push(i);
	cout<<pq.top();
	pq.pop();
	cout<<endl<<pq.top();
	cout<<endl<<"priority queue:"<<pq.size();
	return 0;
}




