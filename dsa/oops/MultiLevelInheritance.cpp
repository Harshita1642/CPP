#include<iostream>
using namespace std;
class Animal{
    public:
    int age,weight;
    void speak()
    {
        cout<<"speaking"<<endl;
    }
};
class Dog: public Animal{

};
class GermanShperd: public Dog{

};
int main()
{
    GermanShperd d;
    d.speak();
    return 0;
}