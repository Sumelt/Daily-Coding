/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char *argv[])
{
	unordered_map<string, int>umap;
	umap[ "key1" ] = 32;
	umap[ "key22" ] = 44;
	cout << umap.bucket_size( 1 );
	return 0;
}




