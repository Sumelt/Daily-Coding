/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;
class car;

class bus
{
	friend class car;
	public:
		bus( int val ) : time(val), price(val){}
		int time;
	private:
		int price;	
	
};

class car
{
	public:
		int gas;
		void print(){ class bus mybus(5); cout<< mybus.price; }
	private:
		int spent;
};

int main(int argc, char *argv[])
{
	car mycar;
	mycar.print();
	return 0;
}

