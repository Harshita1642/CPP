#include<iostream>
using namespace std;
int main()
{
    int row,col;
    cin>>row>>col;
    //creating 2d array nxn;
    int** arr=new int*[row];//creating 1d array of row pointers
    for(int i=0 ; i<row ; i++)
    {
        arr[i]=new int[col];//assinging that pointers a specific array memory
    }
    //Taking input
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col  ; j++)
        {
            cin>>arr[i][j];
        }
    }
    //Displaying Output
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col  ; j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    //releasing memmory
    for(int i=0 ; i<row ; i++)
    {
        delete [] arr[i];
    }
    delete []arr; 
    return 0;
}