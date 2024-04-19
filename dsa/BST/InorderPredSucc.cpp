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
pair<int, int> predecessorSuccessor(Node *root, int key)
{
    // Write your code here.
    Node* temp=root;
    int pred=-1;
    int succ=-1;
    while(temp->data!=key){
        if(temp->data > key){
            succ=temp->data;
            temp=temp->left;
        }
        else{
            pred=temp->data;
            temp=temp->right;
        }
    }
    Node* lefttree=temp->left;
    while(lefttree!=NULL){
        pred=lefttree->data;
        lefttree=lefttree->right;
    }
    Node* righttree=temp->right;
    while(righttree!=NULL){
        succ=righttree->data;
        righttree=righttree->left;
    }
    return {pred,succ};
}
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
int main(){
    Node* root=NULL;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);
    pair<int,int> ans=predecessorSuccessor(root,5);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}  