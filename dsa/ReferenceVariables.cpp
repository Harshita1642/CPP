#include<iostream>
using namespace std;
int& func(int a)
{
    int num=a;
    int& ans=num;
    return ans;
}
int* fun(int n){
    int* ptr=&n;
    return ptr;
    //jbb yeh function ko call krenge tbb yeh warning dega
}
void update(int& n)
{
    n++;
}
int main()
{
    int i=5;
    int& j=i;//creating a reference variable j which will point to the same memory address where i points
    i++;
    j++;
    cout<<"i= "<<i<<endl;
    cout<<"j= "<<j<<endl;
    fun(i);
    return 0;
}