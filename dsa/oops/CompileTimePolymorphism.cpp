#include<iostream>
using namespace std;
class A{
    public:
    void sayHello()
    {
        cout<<"Hello maam"<<endl;
    }
    void sayHello(string name){
        cout<<"Hello "<<name<<endl;
    }
}; 
class Calculate{
    public:
    void sum(int a,int b)
    {
        cout<<"Sum = "<<a+b<<endl;
    }
    void sum(float a,float b)
    {
        cout<<"Sum = "<<a+b<<endl;
    }
    void sum(double a,double b)
    {
        cout<<"Sum = "<<a+b<<endl;
    }
};
int main()
{
    A obj;
    obj.sayHello();
    obj.sayHello("harshita");
    Calculate obj1;
    obj1.sum(1.88,0.22);
    obj1.sum(3,7);
    obj1.sum(1.2f,0.8f);
    return 0;
}