/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <map>
using namespace std;
int main(int argc, char *argv[])
{
	_Rb_tree<int, int, _Identity<int>, less<int>>rbtree;
	
	cout << rbtree.size();
	
	return 0;
}