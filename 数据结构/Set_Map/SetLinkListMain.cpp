﻿/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include "./SetLinkList.h" 
#include "../openFile.h"
using namespace std;


void openTXTFile(){
		SetLinkList<string> set;
		string filePath = "./pride-and-prejudice.txt";
		vector<string>words;
		
		opfile::openfile( filePath, words );//打开圣经文本
		cout << "all words: " << words.size() << endl;
		
		for( auto iters = words.begin(); iters != words.end(); ++iters ) {
			set.add( *iters );
		}
		cout << "after handle words: " << set.size() << endl;
}

int main(int argc, char *argv[])
{
	openTXTFile();
	return 0;
}