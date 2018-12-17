/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include<iostream>

using namespace std;

class test{
	int number;
	
public:
	test(){
		int b =10;
        number = b;
	}
	void out1(){
        cout<<number<<endl;
    }
    void out2() const{
        cout<<number<<endl;
    }
    void out3() const{
        number+=10; //error
        cout<<number<<endl;
    }
}; 

int main(int argc, char *argv[])
{

	return 0;
}




