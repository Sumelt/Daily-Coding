/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include "./hashTable.h"
#include "../openFile.h"
using namespace std;

void openTXTFile(){
	HashTable<string, int> hashT;
	string filePath = "../Set_Map/pride-and-prejudice.txt";
	vector<string>words;
	
	opfile::openfile( filePath, words );
	cout << "all words: " << words.size() << endl;
	
	for( auto iters = words.begin(); iters != words.end(); ++iters ) {
		hashT.Push( *iters, 1 );
	}
	cout << "handle words sum: " << hashT.Size() << endl;
	
	cout << "pride words sum: " << hashT.Get( "pride" ) << endl;
	
}
int main(int argc, char *argv[])
{
	openTXTFile();
	return 0;
}