/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 29/09/18 16:17

----------------------------------------------------------------*/

     // demo1_14.cpp   friend functions
#include<iostream>
using namespace std;

    //类 
    class CRectangle {
        int width, height;
        
      public:
        void set_values (int, int);
        
        int area (void) {return (width * height);}
        
        friend CRectangle duplicate (CRectangle);
        
    };
    
    //类的成员函数实现 
    void CRectangle::set_values (int a, int b) {
        width = a;
        height = b;
    }
    
    //友元函数实现 
    CRectangle duplicate (CRectangle rectparam) {
        CRectangle rectres;
        rectres.width = rectparam.width*2;
        rectres.height = rectparam.height*2;
        return (rectres);
    }
    
    int main () {
        CRectangle   rect, rectb;
        
        rect.set_values (2,3);
        rectb = duplicate (rect);
        //cout<<rect.area()<<endl;
        cout << rectb.area();
    }




