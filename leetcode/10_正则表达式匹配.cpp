/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
	bool matchCode( string s, string p ) {
		if( s.size() == 0 && p.size() == 0 )
			return true;
		if( s.size() != 0 && p.size() == 0 )
			return false;
					
		auto sIter = s.begin(), pIter = p.begin();
		
		if( *( pIter + 1 ) == '*' ) {
			if( sIter != s.end() && ( *sIter == *pIter || *pIter == '.' ) )
				return  matchCode( string( sIter + 1, s.end() ), string( pIter + 2, p.end() ) ) ||
						matchCode( string( sIter, s.end() ), string( pIter + 2, p.end() ) ) ||
						matchCode( string( sIter + 1, s.end() ), string( pIter, p.end() ) );
						
			else return matchCode( string( sIter, s.end() ), string( pIter + 2, p.end() ) );
		}
		else if( sIter != s.end() && ( *sIter == *pIter || *pIter == '.' ) )
			return matchCode( string( sIter + 1, s.end() ), 
				string( pIter + 1, p.end() ) );
		else return false;		
	}
public:
    bool isMatch(string s, string p) {
     	if( s.size() == 0 && p.size() == 0 )
     		return true;
  		else return matchCode( s, p );
    }
};

int main(int argc, char *argv[])
{
	Solution oj;
	cout << oj.isMatch( "aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c" );
	return 0;
}