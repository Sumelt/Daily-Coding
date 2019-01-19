/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>

using namespace std;

class PrintIt{
	public:
		PrintIt( ostream &os ) : _os( os ){}
				
		template <typename elemType>
		void print( const elemType &elem, char delimiter = '\n' )
		{
			_os << elem << delimiter;
		}
	
	private:
		ostream& _os;
};

template<typename OutStream>
class PrintItPlus{
	public:
		PrintItPlus( OutStream &os ) : _os( os ){}
				
		template <typename elemType>
		void print( const elemType &elem, char delimiter = '\n' )
		{
			_os << elem << delimiter;
		}
	
	private:
		ostream& _os;
};

int main(int argc, char *argv[])
{
	PrintIt to_cout( cout );
	to_cout.print(123);
	string mystring("Hello");
	to_cout.print(mystring);
	
	PrintItPlus<ostream> to_coutplus( cout );
	return 0;
}




