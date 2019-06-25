/*----------------------------------------------------------------

* @Author: Su

* @Description: 后缀表达式求值，数据类型是整型 

* @Creath Date: 07/09/18 15:17

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <string>
#include <stack>
#include <queue>


using namespace std;

queue<char> tranform(string, stack<char>, queue<char>);
int cal( queue<int>, queue<char>);

map<char,int>sigmap;
queue<int> reque;
char temp;

int main(int argc, char *argv[])
{
	string str;
	int result;
	sigmap['*'] = sigmap['/'] = 1;
	sigmap['+'] = sigmap['-'] = 0;

	cin>>str;
	for(string::iterator it = str.end(); it!=str.begin(); it--)
		if(*it==' ')
			str.erase(*it);
	
	stack<char> opstk;
	queue<char> poque; 
	 	
	while(!opstk.empty()) opstk.pop();
	while(!reque.empty()) reque.pop();
	while(!poque.empty()) poque.pop();
		
	poque = tranform(str, opstk, poque);
	
	result = cal(reque,poque); 
		
	while(!poque.empty())
	{
		cout<<poque.front()<<' ';
		poque.pop();
 	}
	
	cout<<"= "<<result<<endl;
	return 0;
}

queue<char> tranform(string str, stack<char>stk, queue<char>que)
{
	int temp;
	for(string::iterator it = str.begin(); it!=str.end();)
	{
		if(*it>='0'&&*it<='9')
		{
			que.push(*it);
			reque.push(*it-'0');
			it++;
			while((it!=str.end())&&(*it>='0'&&*it<='9'))
			{
				que.push(*it);
				temp = reque.front();
				reque.pop();
				reque.push(temp*10+*it-'0');
				it++;
			}
				
		}
			
		else if(*it=='+'||*it=='-'||*it=='*'||*it=='/')
		{
			if(stk.empty())
				stk.push(*it);
			else if(sigmap[*it]>sigmap[stk.top()])
				stk.push(*it);
			else 
			{
				while(!stk.empty()&&sigmap[*it]<=sigmap[stk.top()])
				{
					temp = stk.top();
					que.push(temp);
					stk.pop();
				}
				stk.push(*it);	
					
			}
			it++;
		}
			
	}
	while(!stk.empty())
	{
		temp = stk.top();
		que.push(temp);
		stk.pop();		
	}
	
	return que;
}

int cal(queue<int>resque, queue<char>que)
{
	int temp2, temp1;
	int res;
	stack<int> restk;
	while(!restk.empty()) restk.pop();
	
	while(!que.empty())
	{
		if(que.front()>='0'&&que.front()<='9')
			que.pop();
		else
		{
			if(restk.empty())
			{
				temp1 = reque.front();
				reque.pop();
				temp2 = reque.front();
				reque.pop();
			}
			else
			{
				temp1 = restk.top();
				restk.pop();
				temp2 = reque.front();
				reque.pop();
			}
			if(que.front()=='+')				
				restk.push(temp1+temp2);								
			else if(que.front()=='-')
				restk.push(temp1-temp2);				
			else if(que.front()=='*')
				restk.push(temp1*temp2);
			else if(que.front()=='/')
			 	restk.push(temp1/temp2);
		 	que.pop();
		}
	}
	
	return restk.top();
}



