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
		
private:
	int baseCount;
};

class peason : 	private base{
	friend void visted( peason& ); //友元函数可以通过派生类访问基类的公有和保护成员 
		
public:	
	int derivedIndex;
	

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

//void vistedPrint( peason *object )
//{
//	object->print();
//}

int main(int argc, char *argv[])
{
	class peason ptr;
	//class base *fatherPtr = &ptr; // 当派生类以非公有发生继承 从派生类转换到基类失效 
	//fatherPtr->base::print(); //强制访问基类成员
	//fatherPtr->print(); //访问派生类的成员
	//class peason *tmPtr = &ptr;
	//tmPtr->print();
	//Polymorphism( ptr ); //当派生类以非公有发生继承 多态失效 
	//vistedPrint( ptr );
	return 0;
}