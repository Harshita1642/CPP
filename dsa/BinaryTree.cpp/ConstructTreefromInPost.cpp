#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data=0){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};
void createMapping(int in[],map<int,int> &nodeToIndex,int n){
    for(int i=0 ; i<n ; i++){
        nodeToIndex[in[i]]=i;
    }
}
Node* solve(int in[],int post[],int &index,int inorderStart,int inorderEnd,int n,map<int,int> &nodeToIndex){
    if(index<0 || inorderStart>inorderEnd) return nullptr;
    int element=post[index--];
    Node* root=new Node(element);
    int position=nodeToIndex[element];
    root->right=solve(in,post,index,position+1,inorderEnd,n,nodeToIndex);
    root->left=solve(in,post,index,inorderStart,position-1,n,nodeToIndex);
    return root;
}
Node* buildTree(int in[],int post[],int n){
    map<int,int> nodeToIndex;
    createMapping(in,nodeToIndex,n);
    int a=n-1;
    Node* root=solve(in,post,a,0,n-1,n,nodeToIndex);
    return root;
}
void dfv(Node* root){
    if(root==nullptr) return; 
    cout<<root->data<<"\t";
    if(root->left!=nullptr)(dfv(root->left));
    if(root->right!=nullptr)(dfv(root->right));
}
void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}
int main(){
    int in[5]={9,3,15,20,7};
    int post[5]={9,15,7,20,3};
    int n=5;
    Node* root=buildTree(in,post,n);
    levelOrderTraversal(root);
    return 0;
}