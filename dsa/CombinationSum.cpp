#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        int sum=0;
        for(int i=0;i<candidates.size();i++){
            while(sum<=target){
                if(sum+candidates[i]<=target){
                    sum+=candidates[i];
                    temp.push_back(candidates[i]);
                    cout<<sum<<endl;
                    for(int k:temp)cout<<k<<" ";
                    cout<<endl;
                    if(sum==target){
                        ans.push_back(temp);
                        cout<<"push"<<endl;
                        temp.pop_back();
                        sum=0;
                        for(int k:temp)sum+=k;
                        break;
                    }
                    int findnum = target-sum;
                    auto it = find(temp.begin(),temp.end(),findnum);
                    if(it!=temp.end()){
                        temp.push_back(findnum);
                        ans.push_back(temp);
                        cout<<"push"<<endl;
                        sum=0;
                        temp.clear();
                    }
                }
                else {
                    temp.pop_back();
                    sum-=candidates[i];
                    break;
                }
            }
        }
        return ans;
}

int main(){
    vector<int> candidates={2,3,6,7};
    int target=7;
    vector<vector<int>> ans = combinationSum(candidates,target);
//    for(const vector<int>& i:ans){
//        for(int j:i){
//            cout<<j<<" ";
//        }
//        cout<<endl;
//    }
    return 0;
}