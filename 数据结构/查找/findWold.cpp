/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include "openFile.h"

int main(int argc, char *argv[])
{
	using namespace opfile;
	string filePath = "./bible.txt";
	vector<string>words;
	openfile( filePath, words );
	//for( int i = 0; i < 100; i++ )
		//cout << words[ i ]<< endl;
	cout << words.size();
	return 0;
}