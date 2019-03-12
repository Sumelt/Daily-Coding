/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

class base{
protected: 
	int basevalue;
		
public:
	int baseIndex;
	virtual void print(){ cout << "base" << endl; } //基类的虚函数 
	void basePrint( ) { cout << "basePrint without value" <<endl; }
	void basePrint( int value ) { 
		cout << "basePrint with value: " << value << endl; 
	}
		
private:
	int baseCount;
};

class peason : public base{
	friend void visted( peason& ); //友元函数可以通过派生类访问基类的公有和保护成员 
		
public:	
	int derivedIndex;
	void derivedPrintMessage(){ cout << " message from peason class " << endl; }
	using base::basePrint; //继承基类所有的重载版本 
	void basePrint( char c ) { //还能定义属于自己的版本 ，不会覆盖基类的版本 
		cout << "belong derived function " << endl;
	}
	
private:
	int derivedCount;
	void print() override { cout << "kid" << endl; }  //重载基类的成员函数 

protected:
	int derivedValue;

};

class animal : private peason{
	void visted( animal &ptr ) {
		peason *derivedToBasePtr = &ptr;
	}
	
public:	
	using peason::derivedIndex;
};

void visted( peason &ptr )
{
	ptr.basevalue = 2; //使用派生类对象访问基类的公有和保护成员 
	ptr.baseIndex = 3;
	class base *fatherPtr = &ptr; //友元中使用了派生类向基类转换
}

void Polymorphism( base& fatherRefer ) //动态绑定 
{
	fatherRefer.print();
}


int main(int argc, char *argv[])
{
	class peason ptr;
	class peason *fatherPtr = &ptr; // 当派生类以非公有发生继承 从派生类转换到基类失效
	fatherPtr->basePrint( 'a' );
//	fatherPtr->print(); //动态对象 
//	fatherPtr->base::print(); //强制访问基类成员
//	fatherPtr->print(); //访问派生类的成员
//	Polymorphism( ptr ); //当派生类以非公有发生继承 多态失效 
	
	return 0;
}