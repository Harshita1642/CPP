#include<iostream>
using namespace std;
class Human{
    public:
        int height;
    private:
        int weight;
    protected:
        int age;
    public:
        void setHeight(int height)
        {
            this->height=height;
        }
        void setWeight(int weight)
        {
            this->weight=weight;
        }
        void setAge(int age)
        {
            this->age=age;
        }
        int getHeight() const
        {
            return this->height;
        }
        int getWeight() const
        {
            return this->weight;
        }
};
class Male: public Human{
    public:
        string color;
    void sleep()
    {
        cout<<"Male is sleeping"<<endl;
    }
    //weight can't be accessible in Male class as it is private property of parent(Human) class
    // int getWeight() const
    // {
    //     return this->weight;
    // }
    //age is the protected property in Human class and it is inherited in public mode it will result in protected
    //property in Male class which can be accessed in Male class and Parent Class only 
    int getAge()
    {
        return this->age;
    }
};
int main()
{
    Male obj;
    //obj.weight is private variable can't be accessed directly
    //obj.age is protected variable can't be accessed directly
    obj.setAge(12);
    obj.setHeight(155);
    obj.setWeight(45);
    cout<<"Age = "<<obj.getAge()<<endl;
    cout<<"Height = "<<obj.getHeight()<<endl;
    cout<<"Weight = "<<obj.getWeight()<<endl;
    obj.color="blue";
    cout<<obj.color<<endl;
    obj.sleep();
    return 0;
}