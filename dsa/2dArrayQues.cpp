//Matrix Multiplication
// #include<iostream>
// using namespace std;
// int main(){
//     int m,n,p;
//     cin>>m>>n>>p;
//     int arr[m][n];
//     cout<<"elements of 1st array: ";
//     for(int i=0 ; i<m ; i++){
//         for(int j=0 ; j<n ; j++){
//             cin>>arr[i][j];
//         }
//     }
//     int arr2[n][p];
//     cout<<"elements of 2nd array: ";
//     for(int i=0 ; i<n ; i++){
//         for(int j=0 ; j<p ; j++){
//             cin>>arr2[i][j];
//         }
//     }
//     int ans[m][p];
//     for(int i=0 ; i<m ; i++){
//         for(int j=0 ; j<p ; j++){
//             ans[i][j]=0;
//             for(int k=0 ; k<n ; k++){
//                 ans[i][j]+=arr[i][k]*arr2[k][j];
//             }
//         }
//     }
//     cout<<"Output: "<<endl;
//     for(int i=0 ; i<m ; i++){
//         for(int j=0 ; j<p ; j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }
//Spiral Print in 2d matrix
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[5][5];
//     for(int i=0 ; i<5 ; i++){
//         for(int j=0 ; j<5 ; j++){
//             cin>>arr[i][j];
//         }
//     }
//     int rstart=0,rend=4,cstart=0,cend=4;
//     while(rstart<=rend || cstart<=cend){
//             for(int j=cstart ; j<=cend ; j++){
//                 cout<<arr[rstart][j]<<" ";
//             }
//             rstart++;
//             for(int i=rstart ; i<=rend ; i++){
//                 cout<<arr[i][cend]<<" ";
//             }
//             cend--;
//             for(int j=cend ; j>=cstart ; j--){
//                 cout<<arr[rend][j]<<" ";
//             }
//             rend--;
//             for(int i=rend ; i>=rstart ; i--){
//                 cout<<arr[i][cstart]<<" ";
//             }
//             cstart++;
//     }
//     return 0;
// }
// 1 2 3 4 5 16 17 18 19 6 15 24 25 20 7 14 23 22 21 8 13 12 11 10 9

//Wave Print in 2d matrix
// #include<iostream>
// using namespace std;
// int main(){
//     int mat[5][4] = {{  1,   2,   3,   4},
//                     {  5,   6,   7,   8},
//                     {  9, 10, 11, 12},
//                     {13, 14, 15, 16},
//                     {17, 18, 19, 20}};
//     int cols=4;
//     for(int j=0 ; j<cols ; j++){
//         if(j%2==0){
//             for(int i=0 ; i<=4 ; i++){
//                 cout<<mat[i][j]<<" ";
//             }
//         }else{
//             for(int i=4 ; i>=0 ; i--){
//                 cout<<mat[i][j]<<" ";
//             }
//         }
//     }
//     return 0;
// }
//Transpose of a matrix
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
//     int temp;
//     for(int i=0 ; i<3 ; i++){
//         for(int j=i+1 ; j<3 ; j++){
//             temp=arr[i][j];
//             arr[i][j]=arr[j][i];
//             arr[j][i]=temp;
//         }
//     }
//     for(int i=0 ; i<3 ; i++){
//         for(int j=0 ; j<3 ; j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

//Check whether the 2d array is identity matrix or not
#include<iostream>
using namespace std;
int main(){
    int arr[3][3]={
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    int chck=0;
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            if(i==j && arr[i][j]!=1){
                cout<<"false";
                chck=1;
                break;
            }
            if(i!=j && arr[i][j]!=0){
                cout<<"false";
                chck=1;
                break;
            }
        }
        if(chck==1) break;
    }
    if(chck==0) cout<<"true";
    return 0;
}