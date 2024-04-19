#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Inorder(LNR) PreOrder(NLR)
// In --> 1 6 8 7    Pre ---> 1 6 7 8
// Pre's 1st element will always be your root element 
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d=0){
        data=d;
        left=nullptr;
        right=nullptr;
    }
};
// int findPosition(int in[],int ele,int n){
//     for(int i=0 ; i<n; i++){
//         if(in[i]==ele) return i;
//     }
//     return -1;
// }
// Node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int n){
//     if(index>=n || inorderStart>inorderEnd) return nullptr;
//     int element=pre[index++];
//     Node* root=new Node(element);
//     int position=findPosition(in,element,n);
//     root->left=solve(in,pre,index,inorderStart,position-1,n);
//     root->right=solve(in,pre,index,position+1,n,n);
// }
void createMapping(int in[],map<int,int> &nodeToIndex,int n){
    for(int i=0 ; i<n ; i++){
        nodeToIndex[in[i]]=i;
    }
}
Node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int n,map<int,int> &nodeToIndex){
    if(index>=n || inorderStart>inorderEnd) return nullptr;
    int element=pre[index++];
    Node* root=new Node(element);
    int position=nodeToIndex[element];
    root->left=solve(in,pre,index,inorderStart,position-1,n,nodeToIndex);
    root->right=solve(in,pre,index,position+1,n,n,nodeToIndex);
    return root;
}
Node* buildTree(int in[],int pre[],int n){
    int preOrderIndex=0;
    map<int,int> nodeToIndex;
    createMapping(in,nodeToIndex,n);
    Node* ans=solve(in,pre,preOrderIndex,0,n-1,n,nodeToIndex);
    return ans;
}
void dfv(Node* root){//recursive approach of depth first values
    if(root==nullptr) return; 
    cout<<root->data<<"\t";
    if(root->left!=nullptr)(dfv(root->left));
    if(root->right!=nullptr)(dfv(root->right));
}
int main(){
  int in[4]={1,6,8,7};
  int pre[4]={1,6,7,8};
  Node* root=buildTree(in,pre,4);
  dfv(root);
    return 0;
}