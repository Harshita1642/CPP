#include<iostream>
#include<vector>
using namespace std;
string give_str(int a){
    if(a==1) return "one";
    if(a==2) return "two";
    if(a==3) return "three";
    if(a==4) return "four";
    if(a==5) return "five";
    if(a==6) return "six";
    if(a==7) return "seven";
    if(a==8) return "eight";
    if(a==9) return "nine";
}
void solve(int n){
    vector<string> ans;
    while(n>0){
        int a=n%10;
        string corres=give_str(a);
        ans.push_back(corres);
        n=n/10;
    }
    for(int i=ans.size() ; i>=0 ; i--){
        cout<<ans[i]<<"\t";
    }
    return ;
}
int main(){
    solve(123);
    return 0;
}