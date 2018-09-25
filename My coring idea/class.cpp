/*----------------------------------------------------------------

* @Author: Su

* @Description:  

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

class Gf
{
	private:
		string name;
		int age;
		double property;
	public:
		void kiss();
		void hug(); 
};

void Gf::kiss()
{
	cout<<"Kiss you"<<endl;
}

void Gf::hug()
{
	cout<<"Hug you"<<endl;
}

int main(int argc, char *argv[])
{
	Gf test;
	test.hug();
	test.kiss();
	return 0;
}




