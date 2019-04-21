/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

namespace space{
class base1{
	public:
		base1(){
			cout << "base1" << endl;
		} 
		base1( int );
};

class base2{
	public:
		base2(){
			cout << "base2" << endl;
		}
		base2( int, int );
};

class der : public base1, public base2 {
	public:
		//using base1::base1;
		//using base2::base2;
		der( int value ) {
			cout << "der" << endl;
		}
		//der( int value ) : base1( value ), base2( value ){}
};
	
}


int main(int argc, char *argv[])
{
	using namespace space;
	der myder( 3 );
	return 0;
}