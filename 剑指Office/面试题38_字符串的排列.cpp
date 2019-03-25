/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string>res;
	int size;
public:
	void arrangement( char head, string str, string complete )
	{
		complete += head;		
		if( str.size() == 1 ) {
			complete += str;
			res.push_back( complete );
			return;
		}

		for( int i = 0; i < str.size(); ++i ) {
			swap( str[ 0 ], str[ i ] );			
			arrangement( str[ 0 ], string( str, 1, str.size() - 1 ), complete );

		}		
	}
    vector<string> Permutation(string str) {
        if( str.size() == 0 )
        	return vector<string>();
        if(  str.size() == 1) {
        	vector<string> tp;
        	tp.push_back( str );
        	return tp;
        }
            
       	size = str.size();
        for( int i = 0; i < str.size(); ++i ) {
        	if( str[ 0 ] != str[ i ] )
				swap( str[ 0 ], str[ i ] );
			else swap( s )
        	arrangement( str[ 0 ], string( str, 1, str.size() - 1 ) , string());
        	
        }      	
        return res;
        
    }
};

int main(int argc, char *argv[])
{
	Solution oj;
	oj.Permutation( "abc" );
	for( auto value : oj.res )
		cout << value << endl;
	return 0;
}