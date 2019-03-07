/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

// .H文件 
#ifndef _XXX 

#define xxxx
class xxxx; //类前置声明 

class xxxx //类声明 
{
	//xxxx
};

#endif

//---------------------------
// .c文件
 xxxx::funtion  //类定义 


int main(int argc, char *argv[])
{
	int a = 3;
	int b = 9;
	const int *ptr = &a;  //底层的const ，任何试图通过它修改对象都是错的 ，而本身是可变的 
	//*ptr = 4; //通过ptr修改对象是错的 
	ptr = &b; //ptr本身的值是可变的，可以重新指向b的地址 
	
	return 0;
}