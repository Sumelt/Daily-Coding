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
		static int num;
		
		Gf(string, int, double);
		Gf(){}
		~Gf()
		{
			cout<<"Be deleted"<<endl;
		}
		void set(string, int, double);
		void kiss();
		void hug(); 
};


Gf::Gf(string test, int test2, double test3)
{
	name = test;
	age = test2;
	property = test3;
}


void Gf::set(string n, int ag, double pro)
{
	name = n;
	age = ag;
	property = pro;
}

void Gf::kiss()
{
	cout<<"Kiss you"<<endl;
	cout<<name<<' '<<age<<' '<<property<<endl;
}

void Gf::hug()
{
	cout<<"Hug you"<<endl;
}

int Gf::num = 12;

int main(int argc, char *argv[])
{
	//Gf *test = new Gf;
//	test.hug();
//	test.kiss();
	cout<<Gf::num;
	//delete test;
	Gf mygf;
	return 0;
}




