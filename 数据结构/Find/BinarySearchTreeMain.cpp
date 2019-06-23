/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include "../openFile.h"
#include "./BinarySearchTree.h"
#include "../codeTime.h"
using namespace BSTversion2;


void findWord( const string& str ){
	BST<string, int> tree;
			string filePath = "./bible.txt";
	vector<string>words;
			
	opfile::openfile( filePath, words );//打开圣经文本 
	cout << "Sum word: " << words.size() << endl;		

	for( auto iters = words.begin(); iters != words.end(); ++iters ) {
		int *res = tree.search( *iters );
		if( res == nullptr )
			tree.insert( *iters, 1 );
		else ++( *res );
	}
	cout << "Sum word: " << tree.size() << endl;
	
 	
	bool res = tree.contain( str );

	if( res ) {
		cout << str << " appear: " << (*tree.search( str )) << " times" << endl;
	}
		
	else 
		cout << str << "no appear !!!" << endl;
			
			
//测试函数 
//		auto node = tree.minNode();
//		cout << node->key << endl;
//		tree.removeNode( node->key );
//		cout << tree.contain( node->key ) << endl;
//		cout << "Sum word: " << tree.size() << endl;
//		cout << *tree.ceil( str ) ;
}

int main(int argc, char *argv[])
{	
	findWord( "god" );

	return 0;
}