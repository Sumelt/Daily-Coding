/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Library {
protected :
	void stepOne() {
		cout << "this is library step one " << endl;
	}
	void stepFour() {
		cout << "this is library step four " << endl;
	}
	virtual void stepThree() = 0;
	virtual void stepTwo() = 0;
	
public :
	//稳定 
	void Run() {
		stepOne();
		stepTwo();//变化 
		stepThree();//变化 
		stepFour();
	}
	virtual ~Library() = default;
};

class Application : public Library	{
protected:
	virtual void stepTwo() {
		cout << "this is Application step two " << endl;
	}
	virtual void stepThree() {
		cout << "this is Application step three " << endl;
	}
};

int main(int argc, char *argv[])
{
	Library *object = new Application;
	object->Run();
	delete object;
	return 0;
}