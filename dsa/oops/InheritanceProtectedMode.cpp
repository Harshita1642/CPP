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
        
        int getWeight() const
        {
            return this->weight;
        }
        int getAge()
        {
            return this->age;
        }
};
class Male: protected Human{
    public:
        string color;
    void sleep()
    {
        cout<<"Male is sleeping"<<endl;
    }
    int getHeight() const
    {
            return this->height;
    }
};
int main()
{
    Male obj;
    //obj.weight is private variable can't be accessed directly
    //obj.age is protected variable can't be accessed directly
    //All fncs&DM of human class are not protected means can't be accessed directly it can be used inside Male class
    // obj.setAge(12);
    // obj.setHeight(155);
    // obj.setWeight(45);
    // cout<<"Age = "<<obj.getAge()<<endl;
    cout<<"Height = "<<obj.getHeight()<<endl;
    // cout<<"Weight = "<<obj.getWeight()<<endl;
    obj.color="blue";
    cout<<obj.color<<endl;
    obj.sleep();
    return 0;
}