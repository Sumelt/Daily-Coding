/*----------------------------------------------------------------

* @Author: Su

* @Description:  ��ϰnamespace 

* @Creath Date:01/11/18 16:01

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

// ��һ�������ռ�
namespace first_space{
   void func(){
      cout << "Inside first_space" << endl;
   }
}

// �ڶ��������ռ�
namespace second_space{
   void func(){
      cout << "Inside second_space" << endl;
   }
}

using namespace second_space; //Ĭ��ʹ�õڶ��������ռ� 

int main ()
{
 
   // ���õ�һ�������ռ��еĺ���
   first_space::func();
   
   // ���õڶ��������ռ��еĺ���
   //second_space::func(); 
   func(); //ʹ��usingָ��Ĭ��ʹ�õڶ��������ռ� 
 
   return 0;
}




