#include<iostream>
using namespace std;
class Soft{
    public:
    void nature(){
        cout<<"girls are soft-hearted"<<endl;
    }
};
class Human{
    public:
    void speak()
    {
        cout<<"have ability to speak"<<endl;
    }
    void eat(){
        cout<<"Eat raw food"<<endl;
    }
};
class Male: public Human{
    public:
    void height(){
        cout<<"Male are taller"<<endl;
    }
};
class Female: public Human,public Soft{
    public:
    void height(){
        cout<<"Generally height varies from 5 feet to 5'3"<<endl;
    }
};
int main(){
    Female f;
    f.eat();
    f.speak();
    f.height();
    f.nature();
    return 0;
}