/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 02/09/18 13:27

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string.h>
#include <forward_list>

using namespace std;

int main(int argc, char *argv[])
{
//	list<int> ls;
//	list<int> ls2[3];
//	list<int>ls3(1,5); 
//		
//	ls.push_back(2);
//	ls.push_front(5);
//	cout<<ls.front()<<' ';
//	cout<<ls.back()<<endl;
//	
//	ls2[0].push_back(5);
//	ls2[1].push_back(6);ls2[1].push_back(7);ls2[1].push_back(8);
//	ls2[2].push_back(7);
//	cout<<endl<<ls2[1].back();
//	ls2[1].resize(2);
//	cout<<endl<<ls2[1].back();
//	ls2[0].swap(ls2[1]);
//	cout<<endl<<ls2[1].back()<<endl;7
//	ls2[0].merge(ls2[1],greater<int>()); g ->da dao xiao l ->xiao dao da
//	cout<<endl<<ls2[0].front()<<' '<<ls2[0].back();
//	for(list<int>::iterator iter = ls2[0].begin() ; iter != ls2[0].end() ; iter++)
//    {
//         cout<<*iter<<" ";
//    }
//    cout<<endl<<ls3.front()<<' '<<ls3.back();

	forward_list<int>list;
	list.push_front( 4 );
	list.push_front( 3 );
	list.push_front( 5 );
	
	for( auto iter = list.begin(); iter != list.end(); ) {
		cout << *iter++ <<' ';
		if( iter == list.end() )
			break;
		cout << *iter++ <<' ';
		//if( iter == list.end() )
			//break;
	}
		

	return 0;
}




