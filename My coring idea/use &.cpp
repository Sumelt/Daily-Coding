/*----------------------------------------------------------------

* @Author: Su

* @Description:  测试引用 ，有点脑壳疼 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>


using namespace std;

void swap(int * &p1, int * &p2){
	int *temp = p1;
	p1 = p2;
	p2 = temp;
}

int main(int argc, char *argv[])
{
   int a = 1, b = 2;
   int *p1 = &a;//cout<<p1<<' '<<*p1<<' ';printf("%p",&a);
   int *p2 = &b;
   swap(p1, p2);
   cout<<a<<' '<<b<<endl;
   printf("%d %d",*p1, *p2);
	return 0;
}




