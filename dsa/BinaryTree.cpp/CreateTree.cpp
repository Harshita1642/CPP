// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node*  build(node* root){
    cout<<"enter the data for node"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"enter data for inserting in left of"<<data<<endl;
    root->left=build(root->left);
    cout<<"enter data for inserting in right of"<<data<<endl;
    root->right=build(root->right);
    return root;
}
void creatTree(node* root,vector<int>&arr,int i){
     int n=arr.size();
    if(i>=n) return;
    if (2 * i + 1 < n) {
      root->left = new node(arr[2 * i + 1]);
    }
    if(2 * i + 2 < n){
    root->right=new node(arr[2*i+2]);
    }
    creatTree(root->left,arr,2*i+1);
    creatTree(root->right,arr,2*i+2);
}
void levelordertraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}}
void solve(node* root, vector<int>& arr, int i) {
    int n = arr.size();
    if (i >= n) return;

    if (2 * i + 1 < n && arr[2 * i + 1] != -1) {
        root->left = new node(arr[2 * i + 1]);
        solve(root->left, arr, 2 * i + 1);
    }

    if (2 * i + 2 < n && arr[2 * i + 2] != -1) {
        root->right = new node(arr[2 * i + 2]);
        solve(root->right, arr, 2 * i + 2);
    }
}

int main() {
   vector<int> arr;
   arr.push_back(1);
   arr.push_back(2);
   arr.push_back(3);
   arr.push_back(4);
   arr.push_back(5);
   arr.push_back(6);
   arr.push_back(7);
   arr.push_back(8);
   node* root=new node(arr[0]);
   node* dummy=root;
   creatTree(root,arr,0);
   levelordertraversal(dummy);
   node* newroot=new node(arr[0]);
   dummy=newroot;
   solve(newroot,arr,0);
   levelordertraversal(dummy);
    return 0;
}