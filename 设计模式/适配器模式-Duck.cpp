/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

//抽象基类：鸭子 
class Duck {
public:
	virtual void quack() = 0;
	virtual void fly() = 0;
};

class MallardDuck {
public:
	void quack() {
		cout << "I am MallardDuck, Quack" << endl;
	}
	void fly() {
		cout << "I am MallardDuck, Fly" << endl;
	}
};

//抽象基类：火鸡 
class Tuekry {
public:
	virtual void gobble() = 0;
	virtual void fly() = 0;	
};

class WildTurkey : public Tuekry {
public:
	void gobble() {
		cout << "I am WildTurkey, gobble" << endl;
	}
	
	void fly() {
		cout << "I am WildTurkey, fly" << endl;
	}
};

//适配器：继承了鸭子类 
class TuekryToDuckAapater : public Duck {
private:
	Tuekry *m_tuekry;
public:
	TuekryToDuckAapater( Tuekry* tuekry ) : m_tuekry( tuekry ) {}
	
	//实现了鸭子的接口：使用的是火鸡的方法 
	void quack() {
		m_tuekry->gobble();
	}
	void fly() {
		m_tuekry->fly();
	}
	
};

int main(int argc, char *argv[])
{
	Tuekry *tue = new WildTurkey();
	Duck *duck = new TuekryToDuckAapater( tue );
	duck->fly();
	duck->quack();
	
	delete tue;
	delete duck;
	
	return 0;
}