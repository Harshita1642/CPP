#include<iostream>
#include<queue>
using namespace std;
int SumMaxMin(int arr[],int n,int k)
{
    int sum=0;
    deque<int> dqMax(k);
    deque<int> dqMin(k);
    int max=arr[0];
    int min=arr[0];
    for(int i=0 ; i<k ; i++)
    {
        if(max<arr[i])
        {
            max=i;
        }
        if(min>arr[i])
        {
            min=i;
        }
    }
    dqMax.push_back(max);
    dqMin.push_back(min);
    for(int i=k ; i<n ; i++)
    {
        sum+=dqMax.front()+dqMin.front();
        if(!dqMax.empty() && dqMax.front()-i>=k && !dqMin.empty() && dqMin.front()-i>=k)
        {
            
        }
    }
}
int main()
{
    int *arr;
    int n;
    cin>>n;
    int k;
    cin>>k;
    arr=new int[n];
    for(int i=0 ; i<n ; i++)
    {
        cin>>arr[i];
    }
    SumMaxMin(arr,n,k);
    return 0;
}