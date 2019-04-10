/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[])
{
	vector<int>vec = { 1, 2, 3 };
	vector<int>vec2;

	//copy( vec.cbegin(), vec.cend(), inserter( vec2, vec2.begin() ) );	
	//cout << vec2.front();
	
	back_insert_iterator< vector<int> > it =  back_inserter( vec );
	*it = 5;
	cout << vec.back();
	return 0;
}