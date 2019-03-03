/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>& s) {
        int size = s.size();
        int last = size - 1;
        for( int i = 0; i < size / 2; ++i )
        {
			int Difference = s[ i ] - s[ last ];
			s[ i ] -= Difference;
			s[ last-- ] += Difference;
        }
        
    }

int main(int argc, char *argv[])
{
	vector<char>str;
	str.push_back('H');
	str.push_back('P');
	reverseString( str );
	for(  auto value : str )
		cout << value;
	return 0;
}