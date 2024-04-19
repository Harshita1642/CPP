#include<iostream>
using namespace std;
class Complex{
    double real;
    double img;
    public:
    Complex(double real,double img){
        this->real=real;
        this->img=img;
    }
    Complex add(Complex& b){
        double newReal=this->real+b.real;
        double newImg=this->img+b.img;
        return Complex(newReal,newImg);
    }
    Complex mul(Complex& c){
        double newReal=(this->real)*c.real-(this->img)*c.img;
        double newImg=(this->real)*c.img+(this->img)*c.real;
        return Complex(newReal,newImg);
    }
    Complex divide(Complex& c){
        // Complex c1=c.mul(this);
    }
    void printVals(){
        cout<<real<<" "<<img<<endl;
    }
};
int main(){
    Complex c1(8,10);
    Complex c2(2,4);
    Complex ans=c1.mul(c2);
    ans.printVals();
    return 0;
}