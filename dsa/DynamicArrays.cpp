#include<iostream>
using namespace std;
int sum(int arr[],int n)
{
    int sum=0;
    for(int i=0 ; i<n ; i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0 ; i<n ; i++)
    {
        cin>>arr[i];
    }
    int ans=sum(arr,n);
    cout<<"answer is "<<ans<<endl;
    // //case1 
    // while(true)
    // {
    //     int i=5;//it will allocate memory to i and then deallocates while going to next iterations
    //     //it keeps on going which is not benefitial
    //     //static memory clears automatically 
    // }
    // //case2
    // while(true)
    // {
    //     int* ptr=new int;//don't do this
    //     //here ptr which is assigned memory in stack and which gets allocated and deallocated automatically
    //     //but this new int is allocating memory in heap which we will keep going and once all memory got filled it will crash the program
    // }
    //so array allocated in heap should be deallocated
    delete []arr;
    return 0;
}