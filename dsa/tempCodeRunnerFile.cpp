clude<iostream>
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