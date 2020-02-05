/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class CaffeineBeverage {
public:
	//禁止子类修改的 virtual final 函数 
	virtual void prepareRecipe() final {
		boilWater();
		brew();
		pourInCup();
		//钩子手法hook 
		if( isAddConment() ) addCondiment();
	}
	
	virtual void brew() = 0;
	virtual void addCondiment() = 0;
	void boilWater() {
		cout << "Boiling water" << endl;
	}
	void pourInCup() {
		cout << "pouring into cup" << endl;
	}
	bool isAddConment( bool	status = false ) {
		return status;
	} 
};

class Tea : public CaffeineBeverage {
public:
	void brew() {
		cout << "dripping tea" << endl;
	}
	void addCondiment() {
		cout << "add lemon" << endl;
	}	
};

class Coffee : public CaffeineBeverage {
public:
	void brew() {
		cout << "dripping coffe" << endl;
	}
	void addCondiment() {
		cout << "add sugar and milk" << endl;
	}
};
int main(int argc, char *argv[])
{
	CaffeineBeverage *coffee = new Coffee();
	CaffeineBeverage *tea = new Tea();
	
	coffee->prepareRecipe();
	tea->prepareRecipe();
	delete coffee;
	delete tea;
	
	return 0;
}