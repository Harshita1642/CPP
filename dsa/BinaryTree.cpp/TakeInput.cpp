#include<iostream>
#include<queue>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data=0){
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
    ~Node(){
        delete left;
        delete right;
    }
};
Node* buildTree(){
    int ele;
    cin>>ele;
    Node* root=new Node(ele);
    string leftele,rightele;
    cin>>leftele;
    if(leftele=="true") root->left=buildTree();
    cin>>rightele;
    if(rightele=="true") root->right=buildTree();
    return root;
}
void levelOrderTraversal(Node* root){
    if(root==nullptr) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* forntNode=q.front();
        q.pop();
        cout<<forntNode->data<<" ";
        if(forntNode->left){
            q.push(forntNode->left);
        }
        if(forntNode->right){
            q.push(forntNode->right);
        }
    }
}
int main(){
    Node* root=nullptr;
    root=buildTree();
    //10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
    levelOrderTraversal(root);
    return 0;
}