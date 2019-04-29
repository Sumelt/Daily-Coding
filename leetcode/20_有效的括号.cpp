/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
        stack<char>tmp;
        int index = s.size() - 1;        
  		if( s.size() > 0 ) {
		  	tmp.push( s[ index-- ] );
		  }
 		
        while( index >= 0 )
        {				  	
			if( !tmp.empty() ) 
				switch( tmp.top() ){
					case ')' : if( s[ index ] =='(' ) tmp.pop(); 
									else tmp.push( s[ index ] ); break;
					case '}' : if( s[ index ] == '{' ) tmp.pop(); 
									else tmp.push( s[ index ] ); break;
					case ']' : if( s[ index ] == '[' ) tmp.pop(); 
									else tmp.push( s[ index ] ); break;
				}					
			--index;                                             	
        }     
        if( tmp.empty() )
            return true;
        else return false;
    }
int main(int argc, char *argv[])
{
	cout << isValid("()[{]");
	
	return 0;
}