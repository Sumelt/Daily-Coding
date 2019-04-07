/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

class Solution {
private:
	void reverseCore( string ::iterator *startPtr, string ::iterator *endPtr ){
		--( *endPtr );
		while( *startPtr < *endPtr )
			swap( *( *startPtr )++, *( *endPtr )-- );					
	}
	
	void reverseString( string &str ){
		auto begin = str.begin();
		auto end = str.end();
		reverseCore( &begin, &end );
				
		begin = str.begin();
		end = begin;
		
		while( *end != '\0' ){
			while( *end != ' ' && *end != '\0' ) ++end;
			auto temp = end;
			reverseCore( &begin, &end );
			end = temp;			
			begin = ++end;
		}	
	}
public:
    string ReverseSentence(string str) {
        if( str.size() == 0 )
        	return string();
		reverseString( str );	
       	return str;
    }
};

int main(int argc, char *argv[])
{
	string str( "student. a am I" );
	Solution oj;
	cout << oj.ReverseSentence( str );
	return 0;
}