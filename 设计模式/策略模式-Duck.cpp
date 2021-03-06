﻿/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

//抽象飞行类 
class Fly {
public:
	virtual void fly() = 0;
};

//抽象叫声类 
class Quack {
public:
	virtual void quack() = 0;
};

//抽象基类 
class Duck {
public:
	Fly *flyBehavior;
	Quack *quackBehavior;
	
	virtual ~Duck();
	void performFly();
	void performQuack();
	void performSwim();//所有的鸭子都会叫，属于公有部分
	void setFlyBehavior( Fly *newFlyWay );//封装方法，使得算法独立于使用模块 
	void setQuackBehavior( Quack *newQuackWay ); 
};

Duck::~Duck() {
	delete flyBehavior;
	delete quackBehavior;
}

void Duck::performFly() {
	flyBehavior->fly();
}

void Duck::performQuack() {
	quackBehavior->quack();	
}

void Duck::performSwim() {
	cout << "all duck can swimming" << endl;
}

void Duck::setQuackBehavior( Quack *newQuackWay ) {
	quackBehavior = newQuackWay;
}

void Duck::setFlyBehavior( Fly *newFlyWay ) {
	flyBehavior = newFlyWay;
} 

//**********************// 
//自定义飞行动作类 
class FlyWithWind : public Fly {
public:
	void fly() {
		cout << "I can Fly with wind" << endl;
	}
};

class FlyWithRock : public Fly {
public:
	void fly() {
		cout << "I can Fly with rock" << endl;
	}
};

//自定义叫声类 
class QuackMute : public Quack {
public:
	void quack() {
		cout << "I can quack wawa" << endl;
	}
};

//自定义类实现 
class MuteDuck : public Duck {
public:
	MuteDuck();
};

MuteDuck::MuteDuck() {
	flyBehavior = new FlyWithWind();
	quackBehavior = new QuackMute();
}



int main(int argc, char *argv[])
{
	MuteDuck mduck;
	mduck.performFly();
	mduck.performQuack();
	mduck.performSwim();
	mduck.setFlyBehavior( new FlyWithRock() );
	mduck.performFly();
	return 0;
}