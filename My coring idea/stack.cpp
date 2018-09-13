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
#include <string.h>
#include <stack> 

using namespace std;

int main(int argc, char *argv[])
{
	stack<int>stk;
	if(stk.empty())
		cout<<"YES empty"<<endl;
	else cout<<"NO empty"<<endl;
	stk.push(425);
	stk.push(500);
	stk.pop();
	cout<<endl<<stk.top()<<" size:"<<stk.size();
	
	return 0;
}




