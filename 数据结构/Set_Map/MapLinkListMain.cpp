/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include "./MapLinkList.h"
#include "../openFile.h"
using namespace std;

void openTXTFile(){
		MapLinkList<string, int> map;
		string filePath = "./pride-and-prejudice.txt";
		vector<string>words;
		
		opfile::openfile( filePath, words );
		cout << "all words: " << words.size() << endl;
		
		for( auto iters = words.begin(); iters != words.end(); ++iters ) {
			map.add( *iters, 1 );
		}

		cout << "after handle words: " << map.getSize() << endl;
		cout << "pride sum : " << map.get( "pride" ) << endl;
		//map.set( "melt", 2 );
}

int main(int argc, char *argv[])
{
	openTXTFile();
	return 0;
}