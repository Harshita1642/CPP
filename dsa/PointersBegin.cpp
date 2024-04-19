#include<iostream>
using namespace std;
int main()
{
    int i=5;
    //declaring and intialising the pointer
    int *ptr=&i;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;

    //Bad practice;
    //int *ptr1;//it will point to anything in memory which is not good way to declare
    //at this place we can provide 0 as address to ptr1 as if it is pointing to null means aisi koi memory hai nahi
    int *ptr1=0;
    //cout<<ptr<<endl;//it will give segmentation fall because ptr1 does not exist in memory it will make sense when 
    // it is directed to a valid address
    int j=2;
    ptr1=&j;
    cout<<ptr1<<" "<<*ptr1<<endl;

    //if we make any change to the pointer pointing value so it will change that exact value whose address is stored in pointer
    (*ptr)++;
    cout<<i<<endl;//6 hogyi hogi i ki value

    //copying one pointer to another
     int *ptr2=ptr;
     cout<<ptr2<<endl<<*ptr2;

    //important concept
    
    return 0;
}