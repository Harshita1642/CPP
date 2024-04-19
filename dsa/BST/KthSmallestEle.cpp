#include<iostream>
using namespace std;
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
Node* insertToBST(Node* root,int data){
    if(root==nullptr){
        Node* temp=new Node(data);
        return temp;
    }
    if(data>root->data){
        root->right=insertToBST(root->right,data);
    }
    else{
        root->left=insertToBST(root->left,data);
    }
}
int kSmallest(Node* root,int &i,int k){
    if(root==nullptr) return -1;
    //L
    int left=kSmallest(root->left,i,k);
    if(left!=-1){
        return left;
    }
    //N
    i++;
    if(i==k){
        return root->data;
    }
    //R
    return kSmallest(root->right,i,k);
}
int main(){
    Node* root=new Node(5);
    insertToBST(root,4);
    insertToBST(root,8);
    insertToBST(root,2);
    insertToBST(root,6);
    insertToBST(root,10);
    insertToBST(root,7);
    insertToBST(root,3);
    int i=0;
    cout<<kSmallest(root,i,3);
    return 0;
}