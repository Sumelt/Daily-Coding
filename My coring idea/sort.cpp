/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a,int b)
{
      return a<b;   //升序排列，如果改为return a>b，则为降序

}
int main(int argc, char *argv[])
{
	 char a[3]={'2','1','9'},i;
     sort(a,a+3,compare);
     for(i=0;i<3;i++)
     	cout<<a[i]<<' ';

     return 0;
}
