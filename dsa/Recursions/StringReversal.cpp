#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string stringReversal(string input){
    //base case
    if(input=="") return "";
    //Recursive call...for figuring out sub problems 
    return stringReversal(input.substr(1))+input[0];
}
int main(){
    cout<<stringReversal("hello");
    return 0;
}