#include<iostream>
using namespace std;
class Animal{
    public:
    void speak(){
        cout<<"speaking"<<endl;
    }
};
class Dog: public Animal{
    public:
    void speak()
    {
        cout<<"Barking"<<endl;
    }
};
int main()
{
    Dog d;
    d.speak();//Barking 
    return 0;
}