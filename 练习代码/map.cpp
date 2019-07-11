/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <map>
#include <unordered_set> 
using namespace std;
int main(int argc, char *argv[])
{
	map <char,int>mp;
	mp['a'] = 2;
	mp['b'] = 3;
//	mp['c'] = 56;
//	mp['1'] = 2;
//	map <char,int>::iterator it;
//	for(it = mp.begin();it!=mp.end();it++)
//		cout<<it->first<<":"<<it->second<<endl;
//	it = mp.find('b');
//	for(it;it!=mp.end();it++)
//		cout<<it->first <<':' <<it->second <<endl;
//	it = mp.find('b');
//	mp.erase(it,mp.end());
//	//mp.erase('a');
//	cout<<endl<<':'<<mp.size();
//	std::unordered_set <int> my;
	if( mp.insert( pair<char, int>('k', 33) ).second == false ) 
		cout << "false"  << endl;
	else cout << "success" << endl;
	
	return 0;
}



