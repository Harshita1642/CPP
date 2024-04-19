#include<iostream>
using namespace std;
//common algo to explain the calls we going to proceed
// for(all choices){
//     if(check(valid choice)){
//         move(choice)
//     }
// }
int rec(int level,int n){// ret-> the number of way to N if we are at stair level
    // level-> stair i am at

    //pruning 
    if(level>n) return 0;//Out of bound 
    //base case
    if(level==n){// if we are at nth stair then we have 1 move to go to at same place
        return 1;
    }
    //loop over choices
    int ans=0;
    for(int step=1; step<=3; step++){
        if(level+step<=n){
            //check-> is a valid choice
            int ways=rec(level+step,n);
            ans+=ways;
        }
    }
    return ans;
}
int main(){
    cout<<rec(1,4);
    return 0;
}