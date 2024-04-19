#include<iostream>
using namespace std;
class Animal{
    public:
    int age,weight;
    void bark(){
        cout<<"Barking"<<endl;
    }
};
class Human{
    public:
    string color;
    void speak()
    {
        cout<<"speaking"<<endl;
    }
}; 
class Hybrid: public Animal,public Human{

};
int main()
{
    Hybrid obj;
    obj.speak();
    obj.bark();
    return 0;
}