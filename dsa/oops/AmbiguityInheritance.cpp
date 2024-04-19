#include<iostream>
using namespace std;
class A{
    public:
    void func()
    {
        cout<<"mein cute sa function A class ka member hoon"<<endl;
    }
};
class B{
    public:
    void func()
    {
        cout<<"mein cute sa function B class ka member hoon"<<endl;
    }
};
class C:public A,public B{
    public:
    void myfunc()
    {
        cout<<"mein na C class ka member hoon aur na A B class meri parent classes hain"<<endl;
    }
};
int main()
{
    C obj;
    obj.myfunc();
    obj.A::func();
    obj.B::func(); 
    return 0;
}