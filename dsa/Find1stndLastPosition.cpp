#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int> &arr, int start,int end, int key)
{
    int mid;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        if(arr[mid]>key)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return -1;
}
vector<int> searchRange(vector<int> &arr, int x)
{
	// Write your code here.
	int n=arr.size()-1;
	int first=binarySearch(arr,0,n,x);
	int last=binarySearch(arr, first, n, x);
	vector<int> result;
	result.push_back(first);
	result.push_back(last);
	return result;
}
int main()
{
    vector<int> arr;
    int n;
    cin>>n;
   
    for(int i=0 ;  i<n ; i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    vector<int> result;
    result=searchRange(arr,-5);
    for(int i=0 ; i<result.size() ; i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}
