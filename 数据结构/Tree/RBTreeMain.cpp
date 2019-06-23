/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include "./RBtree.h" 
#include "../openFile.h"
using namespace std;

void openTXTFile(){
	RBTree<string, int> map;
	string filePath = "../Set_Map/pride-and-prejudice.txt";
	vector<string>words;
	
	opfile::openfile( filePath, words );
	cout << "all words: " << words.size() << endl;
	
	for( auto iters = words.begin(); iters != words.end(); ++iters ) {
		map.insert( *iters, 1 );
	}
	cout << "handle words sum: " << map.size() << endl;
	
	cout << "pride words sum: " << *map.search( "pride" ) << endl;
	
}
using namespace std;
int main(int argc, char *argv[])
{
	openTXTFile();
	return 0;
}