/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
using namespace std;
static bool flag = 0;

class iterator_overflow{
	public:
		iterator_overflow( int index, int max ) 
			: _index( index ), _max( max ){}
		int index(){ return _index; }
		int max() { return _max; }
		void what_happen( ostream &os = cerr ){
			os <<"throw exception" <<endl;
		}
				
	private:
		int _index;
		int _max;
};

bool myexception( bool flag )
{
	if( flag )
		throw iterator_overflow( 3, 2 );
	else return true;
}

int myexception_handing()
{
	int erro_number = 0;
//	myexception( true );
//	cout <<"no print message!" <<endl;
	try{
		myexception( true );
		cout <<"no print message!" <<endl;
	}	 
	catch( iterator_overflow &iof ){
		iof.what_happen( cout );
		erro_number = 40;
	}
	catch( ... ){
		cout <<"Catch all exception!" <<endl;
	}
	
	return erro_number;
}

int main(int argc, char *argv[])
{
	myexception_handing();
	return 0;
}




