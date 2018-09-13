/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 31/08/18 10:37

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string.h>
#include <queue>

using namespace std;

struct fruit{
	string name;
	int price;
	
	//friend bool operator < (fruit f1, fruit f2) {
		//return f1.name > f2.name; //×ÖµäÐò 
	//}
	
};

struct cmp{
	bool operator () (fruit f1, fruit f2) {
		return f1.name > f2.name; //×ÖµäÐò 
	}
};


int main(int argc, char *argv[])
{
	//priority_queue<int,vector<int>,greater<int> > q;
	//priority_queue<fruit> q;
	priority_queue<fruit,vector<fruit>,cmp> q;
	fruit f[3];
	f[0].name = "apple";
	f[0].price = 23;
	f[1].name = "aear";
	f[1].price = 10;
	f[2].name = "au";
	f[2].price = 100;
	
	for(int i = 0; i<3; i++)
		q.push(f[i]);
	cout<<q.top().name<<":"<<q.top().price;
	return 0;
}




