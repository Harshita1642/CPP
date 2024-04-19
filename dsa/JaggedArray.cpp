// A jagged array is an array of arrays such that member arrays can be of different sizes, in 2D array terms 
// for each row we can have a variable number of columns
#include<iostream>
using namespace std;
int main()
{
    int row;
    cin>>row;
    int* cols=new int[row];
    cout<<"enter the column indexes: "<<endl;
    for(int i=0 ; i<row ; i++)
    {
        cin>>cols[i];
    }
    int** arr=new int*[row];
    for(int i=0; i<row ; i++)
    {
        arr[i]=new int[cols[i]];
    }
    cout<<"enter the 2d arrays elements: "<<endl;
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<cols[i]  ; j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"2d Array is: "<<endl;
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<cols[i]  ; j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    for(int i=0 ; i<row ; i++)
    {
        delete [] arr[i];
    }
    delete []cols;
    delete []arr;
    cout<<"Memory released";
    return 0;
}