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
// 1. Initialize current as root 
// 2. While current is not NULL
//    If the current does not have left child
//       a) Print current’s data
//       b) Go to the right, i.e., current = current->right
//    Else
//       a) Find rightmost node in current left subtree
// OR
//               node whose right child == current.
//          If we found right child == current
//              a) Update the right child as NULL of that node whose right child is current
//              b) Print current’s data
//              c) Go to the right, i.e. current = current->right
//          Else
//              a) Make current as the right child of that rightmost 
//                 node we found; and 
//              b) Go to this left child, i.e., current = current->left
void MorrisTraversal(Node* root){
    if(root==nullptr) return;
    Node* current=root;
    while(current!=nullptr){
        if(current->left==nullptr){
            cout<<current->data<<" ";
            current=current->right;
        }
        else{
            Node* pre=current->left;
            while(pre->right!=nullptr && pre->right!=current){
                pre=pre->right;
            }
            if(pre->right==nullptr){
                pre->right=current;
                current=current->left;
            }
            else{
                pre->right=nullptr;
                cout<<current->data<<" ";
                current=current->right;
            }
        }
    }
}
int main(){
    Node* root=new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
 
    MorrisTraversal(root);
    return 0;
}