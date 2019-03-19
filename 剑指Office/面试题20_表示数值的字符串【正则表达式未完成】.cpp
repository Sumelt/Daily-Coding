/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool isNumeric( string str )
{
//	std::string strValue;
	
//	while( *string++ != '\0' )
////		strValue += *string;
	regex repPattern( "[+-]?\\d*(\\.\\d+)?([eE][+-]?\\d+)?",
		regex_constants::extended );
	match_results<string::const_iterator> rerResult;
	bool bValid = regex_match(str, rerResult, repPattern);
		
	return bValid;
} 

int main(int argc, char *argv[])
{
	string str( "123.45e+6" );
	cout << isNumeric( str );
	return 0;
}