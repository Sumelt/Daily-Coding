/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

//女孩类 
class Girl {
public:
    Girl(char* name = ""):mName(name){}
    char* getName() {
        return mName;
    }
private:
    char* mName;
};

//礼物接口 
class GiveGift {
public:
    virtual void GiveDolls() = 0;
    virtual void GiveFlowers() = 0;
    virtual void GiveChocolate() = 0;
};

//送礼物 实例：小王 
class Pursuit : public GiveGift {
public:
    Pursuit(Girl mm):mGirl(mm){}

    virtual void GiveDolls() {
        cout<<"送"<<mGirl.getName()<<"玩具！"<<endl;
    }

    virtual void GiveFlowers() {
        cout<<"送"<<mGirl.getName()<<"鲜花！"<<endl;
    }

    virtual void GiveChocolate() {
        cout<<"送"<<mGirl.getName()<<"巧克力！"<<endl;
    }
private:
    Girl mGirl;
};

//送礼物代理类：小林 
class Proxy : public GiveGift {
public:
    Proxy(Girl mm) {
        mPuisuit = new Pursuit(mm);
    }

    virtual void GiveDolls() {
        mPuisuit->GiveDolls();
    }

    virtual void GiveFlowers() {
        mPuisuit->GiveFlowers();
    }

    virtual void GiveChocolate() {
        mPuisuit->GiveChocolate();
    }
private:
    Pursuit* mPuisuit;
};

int main() {
    Girl mm("小娟");
    Proxy pro(mm);
    pro.GiveChocolate();
    pro.GiveDolls();
    pro.GiveFlowers();

    return 0;
}