/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/



#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(int argc, char *argv[])
{
    int a;
    string str = "-1024";
    istringstream issInt(str);
    issInt >> a;
    cout << a <<endl;
    return 0;
}




