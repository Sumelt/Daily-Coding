/*----------------------------------------------------------------

* @Author: Su

* @Description:  练习namespace 

* @Creath Date:01/11/18 16:01

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

// 第一个命名空间
namespace first_space{
   void func(){
      cout << "Inside first_space" << endl;
   }
}

// 第二个命名空间
namespace second_space{
   void func(){
      cout << "Inside second_space" << endl;
   }
}

using namespace second_space; //默认使用第二个命名空间 

int main ()
{
 
   // 调用第一个命名空间中的函数
   first_space::func();
   
   // 调用第二个命名空间中的函数
   //second_space::func(); 
   func(); //使用using指令默认使用第二个命名空间 
 
   return 0;
}




