//Input->412 then Output-> Four One Two
#include<iostream>
using namespace std;
void sayDigits(int n)
{
    //Base case
    if(n==0)
        return;   
    //processing part
    string arr[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    int number=n%10;
    n=n/10;
    //Recursive Relation
    sayDigits(n);
    cout<<arr[number]<<"\t";
}
int main()
{
    int n;
    cin>>n;
    sayDigits(n);
    return 0;
}