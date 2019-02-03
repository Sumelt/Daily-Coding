#include <iostream>
#include <string>
using namespace std;

/*

//-------------()--------------------


//----------main-------------


*/


/*

//-------------13.13--------------------
struct X {
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << std::endl; }
    X& operator=(const X&) { std::cout << "X& operator=(const X&)" << std::endl; return *this; }
    ~X() { std::cout << "~X()" << std::endl; }
};

void f(const X &rx, X x) //X(const X&) { std::cout << "X(const X&)" << std::endl; }\
		// ~X() { std::cout << "~X()" << std::endl; } 
{
    std::vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx); //X(const X&) { std::cout << "X(const X&)" << std::endl; } // ~X() { std::cout << "~X()" << std::endl; }
    vec.push_back(x); //X(const X&) { std::cout << "X(const X&)" << std::endl; } // ~X() { std::cout << "~X()" << std::endl; }
}
//----------main-------------
    X *px = new X; //X() { std::cout << "X()" << std::endl; };
    f(*px, *px);
    delete px; //~X() { std::cout << "~X()" << std::endl; }

*/


/*

//-------------(13.28)--------------------
class TreeNode {
public:
    TreeNode( const string& str )
    	: value( str ), count( new int( 1 )), left( nullptr ), right( nullptr )
    	{}
    TreeNode( const TreeNode& hp )
    	: value( hp.value ), count( hp.count ), left( hp.left ), right( hp.right )
    	{ ++*count; }
    TreeNode& operator=( const TreeNode& hp );
    ~TreeNode()
    {
    	if( --*count == 0 )
    	{
    		delete count;
    		delete left;
    		delete right;
		}
	}
private:
    std::string value;
    int         *count;
    TreeNode    *left;
    TreeNode    *right;
};

TreeNode& TreeNode::operator=( const TreeNode& hp )
{
	++*hp.count;
	if( this == &hp )
		return *this;
	if( --*count == 0 )
	{
	    delete count;
		delete left;
		delete right;
	}
	count = hp.count;
	left = hp.left;
	right = hp.right;
	return *this;
}

class BinStrTree {
public:
	BinStrTree()
		: root( new TreeNode()){}
	BinStrTree( const BinStrTree& hp )
		: root( new TreeNode( *hp.root )){}
	BinStrTree& operator=( const BinStrTree& hp );
	~BinStrTree()
	{
		delete root;
	}
private:
    TreeNode *root;
};

BinStrTree& BinStrTree::operator=( const BinStrTree& hp )
{
	if( this == &hp )
		return *this;
	delete root;
	root = new TreeNode( *hp.root );
	return *this;
}

//----------main-------------


*/





int main(int argc, char *argv[])
{

	return 0;
}




