#include<iostream>
using namespace std;
class A{
    public:
    void func1()
    {
        cout<<"Inside function1"<<endl;
    }
};
class B: public A{
    public:
    void func2(){
        cout<<"inside class B"<<endl;
    }
};
class C: public A{
    public:
    void func2(){
        cout<<"inside class C"<<endl;
    }
};
int main()
{
    B b;
    b.func1();
    b.func2();
    C c;
    c.func1();
    c.func2();
    return 0;
}