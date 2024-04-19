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
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertToBST(root,data);
        cin>>data;
    }
}
Node* LCA(Node* root,int p,int q){
    if(root==nullptr) return nullptr;
    if(root->data < p && root->data< q){
        return LCA(root->right,p,q);
    }
    if(root->data > p && root->data > q){
        return LCA(root->left,p,q);
    }
    return root;
}
int main(){
    Node* root=NULL;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);
    return 0;
}