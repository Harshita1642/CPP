// Take as input a two-d array. Wave print it row-wise.

// Input Format
// Two integers M(row) and N(column) and further M * N integers(2-d array numbers).

// Constraints
// Both M and N are between 1 to 10.

// Output Format
// All M * N integers are seperated by commas with 'END' written in the end(as shown in example).

// Sample Input
// 4 4
// 11 12 13 14
// 21 22 23 24
// 31 32 33 34
// 41 42 43 44
// Sample Output
// // 11, 12, 13, 14, 24, 23, 22, 21, 31, 32, 33, 34, 44, 43, 42, 41, END
// #include<iostream>
// using namespace std;
// int main(){
//     int m,n;
//     cin>>m>>n;
//     int arr[m][n];
//     for(int i=0 ; i<m ; i++){
//         for(int j=0 ; j<n ; j++){
//             cin>>arr[i][j];
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }

//     return 0;
// }

#include<iostream>
void insert(int arr[],int& n,int pos,int val){
    if(pos>=0 and pos<=n){
        for(int i=n; i>pos ; i--){
            arr[i]=arr[i-1];
        }
        arr[pos]=val;
        n++;
    }
}
using namespace std;
int main(){
    int arr[10];
    int n;
    cin>>n;
    int ele;
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    insert(arr,n,1,6);
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}