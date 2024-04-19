//Problem is to figure out no of ways possible to place n queens in nXn matrix so that any of the queen does not attack each other
#include<iostream>
using namespace std;
int queen[20];// queen[i]--> where is my queen in row i.
bool check(int row,int col){
    for(int i=0; i<row;i++){
        int prow=i;
        int pcol=queen[i];
        // pcol==col check if any queen is in same col and abs(col-pcol)==abs(row-prow) this one is going to check if there is any queen present diagonally to that col
        if(pcol==col || abs(col-pcol)==abs(row-prow)){
            return false;
        }
        return true;
    }
}
int solve(int level,int n){// it will retddurn no of ways to populate [level..n-1] rows for  a valid configuration 
    //level-> row of the matrix
    //basecase
    if(level==n) return 1;
    //compute
    int ans=0;
    //loop over all choices
    for(int col=0; col<n ; col++){
        //check if the choice is valid
        if(check(level,col)){
            //place the queen
            queen[level]=col;
            //explore the option
            ans+=solve(level+1,n);
            //revert placing the queen
            queen[level]=-1;
        }
    }
    //return
    return ans;
}
int main(){
    cout<<solve(0,3);
    return 0;
}