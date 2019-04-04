/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <cstring>
using namespace std;

void reverseCore( char *startPtr, char *endPtr )
{
	--endPtr;
	while( startPtr < endPtr )
		swap( *startPtr++, *endPtr-- );
				
}

void reverseString( char *str, int lenth )
{
	if( str == nullptr )
		return;
		
	reverseCore( str, str + lenth );
	
	char *begin = str;
	char *end = begin;
	
	while( *end != '\0' )
	{
		while( *end != ' ' && *end != '\0' ) ++end;
		reverseCore( begin, end );
		begin = ++end;
	}	
}


int main(int argc, char *argv[])
{
	char array[ 16 ] = "I am a student.";
	int length = strlen( array );
	reverseString( array, length );
	
	for( int i = 0; i < length; ++i )
		cout << array[ i ];
	
	return 0;
}