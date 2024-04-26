#include<iostream>
#include<vector>
using namespace std;
// top down approach or memoization TC O(n) SC O(n)+O(n)
int fibb(int n,vector<int> &dp){
    if(n==0 || n==1) return n;
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=fibb(n-1,dp)+fibb(n-2,dp);
    dp[n]=ans;
    return ans;
}
// bottom up approach or tabulation TC O(n) SC O(n)
int fibbCal(int n){
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2 ; i<=n ; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
//most optimised approach TC O(n) SC O(1)
int solve(int n){
    int val1=0,val2=1;
    for(int i=2 ; i<=n ; i++){
       int  val3=val1+val2;
       val1=val2;
       val2=val3;
    }
    return val2;
}
int main(){
    int n=7;
    vector<int> dp(n+1,-1);
    cout<<fibb(n,dp);
    cout<<endl;
    cout<<fibbCal(n);
    cout<<endl;
    cout<<solve(n);
    return 0;
}