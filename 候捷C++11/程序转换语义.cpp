/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

class strExample{
private :
public :
	int number;
	strExample( int value ){
		number = value;
		cout << "call struct function\n";
	}
	strExample(){
		cout << "call default struct function\n";
	}
	strExample( const strExample& Example ) {
		number = Example.number;
		cout << "call Copy struct function\n";
	}

//	strExample( const strExample& Example ) = delete;
//	strExample& operator=( const strExample& ) = delete;
//	strExample& operator=( const strExample&& ) noexcept = delete;
//	strExample( strExample&& ) noexcept = delete;
	
	~strExample(){
		cout << "call destruct function\n";
	}
};

class vPtrBase{
public : 
	int value;
	vPtrBase(){
		Print(); 
	}
	virtual void Print(){
		cout << "Base print\n";
	}
};

class vPtrDerived : public vPtrBase	 {
public : 
	vPtrDerived(){
		Print(); 
	}
	virtual void Print(){
		cout << "Derived print\n";
	}
};

void outPrint( vPtrBase *ptr )
{
	ptr->Print();
}

int main(int argc, char *argv[])
{
	vPtrDerived derived;
	cout << sizeof( vPtrBase );
	return 0;
}