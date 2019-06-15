/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include "../openFile.h"
#include "./BinarySearchTree.h"
using namespace BSTversion2;

void findWord( const string& str ){
		BST<string, int> tree;
		string filePath = "./bible.txt";
		vector<string>words;
		
		opfile::openfile( filePath, words );//打开圣经文本 
		
		for( auto iters = words.begin(); iters != words.end(); ++iters ) {
			int *res = tree.search( *iters );
			if( res == nullptr )
				tree.insert( *iters, 1 );
			else ++( *res );
		}
		cout << "Sum word: " << tree.size() << endl;
		if( tree.contain( str ) )
			cout << str << " appear: " << (*tree.search( str )) << " times" << endl;
		else 
			cout << str << "no appear !!!" << endl;
		//测试函数 
//		auto node = tree.minNode();
//		cout << node->key << endl;
//		tree.removeNode( node->key );
//		cout << tree.contain( node->key ) << endl;
//		cout << "Sum word: " << tree.size() << endl;
		cout << *tree.ceil( str ) ;
	}

int main(int argc, char *argv[])
{	
	findWord( "melt" );

	return 0;
}