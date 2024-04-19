#include<iostream>
using namespace std;
void update(int **p)
{
    // p=p+1;
    //Kuch change hoga-> NO
    // *p=*p+1;
    //Kuch change hoga-> YES
    **p=**p+1;
    //Kuch change hoga-> YES
}
int main()
{
    int i=5;
    int* ptr=&i;
    int** ptr2=&ptr;
    cout<<"before "<<i<<endl;
    cout<<"before "<<ptr<<endl;
    cout<<"before "<<ptr2<<endl;
    update(ptr2);
    cout<<"after "<<i<<endl;
    cout<<"after "<<ptr<<endl;
    cout<<"after "<<ptr2<<endl;
    return 0;
}