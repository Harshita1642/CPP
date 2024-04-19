//Conditions to be a binary tree
//1. atmost 2 children per node
//2. exactly 1 root
//3. exactly 1 path b/w root and any node
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};
void depthfirstValues(Node* root){
    //Time Complexity O(n)... n no of nodes
    //Space Complexity O(n)
    if(root==nullptr){
        cout<<"It is a empty tree";
        return;
    }
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* curr=st.top();
        cout<<(char)curr->data<<"\t";
        st.pop();
        if(curr->right!=nullptr) st.push(curr->right);
        if(curr->left!=nullptr) st.push(curr->left);
    }
}
void dfv(Node* root){//recursive approach of depth first values
    if(root==nullptr) return; 
    cout<<(char)root->data<<"\t";
    if(root->left!=nullptr)(dfv(root->left));
    if(root->right!=nullptr)(dfv(root->right));
}
void bfv(Node* root){
    if(root==nullptr){
        cout<<"It is a empty tree";
        return;
    }
    cout<<(char)root->data<<" ";
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* curr=st.top();
        if(curr->left!=nullptr && curr->right!=nullptr){
            cout<<(char)curr->left->data<<" "<<(char)curr->right->data<<" ";
            st.pop();
            if(curr->right!=nullptr) st.push(curr->right);
            if(curr->left!=nullptr) st.push(curr->left);
        }
        else if(curr->left!=nullptr){
            cout<<(char)curr->left->data<<" ";
            st.pop();
            if(curr->right!=nullptr) st.push(curr->right);
            if(curr->left!=nullptr) st.push(curr->left);
        }
        else if(curr->right!=nullptr){
            cout<<(char)curr->right->data<<" ";
            st.pop();
            if(curr->right!=nullptr) st.push(curr->right);
            if(curr->left!=nullptr) st.push(curr->left);
        }
        else st.pop();
    }
}
void breadthfirstValues(Node* root){
    //Time Complexity O(n)...n no of nodes
    //Space Complexity O(n)
    if(root==nullptr) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        cout<<(char)curr->data<<"\t";
        q.pop();
        if(curr->left!=nullptr) q.push(curr->left);
        if(curr->right!=nullptr) q.push(curr->right);
    }
}
bool treeincludes(Node* root,char target){//T.C -->O(n) and S.C --> O(n)
    if(root==nullptr) return false;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        if((char)curr->data==target) return true;
        q.pop();
        if(curr->left!=nullptr) q.push(curr->left);
        if(curr->right!=nullptr) q.push(curr->right);
    }
    return false;
}
bool TreeIncludes(Node* root,char target){//recursive approach
    if(root==nullptr) return false;
    if((char)root->data==target) return true;
    return TreeIncludes(root->left,target) || TreeIncludes(root->right,target);
}
int TreeSum(Node* root){//T.C O(n) for this recursive approach and S.C O(n) we do consume call stack for n nodes
    if(root==nullptr) return 0;
    return root->data+TreeSum(root->left)+TreeSum(root->right);
}
int TreeMin(Node* root){
    if(root==nullptr) return INT16_MAX;
    int left=TreeMin(root->left);
    int right=TreeMin(root->right);
    return min(root->data,min(left,right));
}
int TreeMaxSum(Node* root){//T.C--> O(n)  S.C -->O(n)
   if(root==nullptr) return 0;
   return root->data+max(TreeMaxSum(root->left),TreeMaxSum(root->right));
}
int main(){
    // Node* a =new Node('a');
    // Node* b=new Node('b');
    // Node* c=new Node('c');
    // Node* d=new Node('d');
    // Node* e=new Node('e');
    // Node* f=new Node('f');
    // a->left=b;
    // a->right=c;
    // b->left=d;
    // b->right=e;
    // c->right=f;
    // depthfirstValues(a);
    // cout<<endl;
    // dfv(a);
    // cout<<endl;
    // breadthfirstValues(a);
    // cout<<endl<<treeincludes(a,'e');
    // cout<<endl<<treeincludes(a,'j');
    Node* a =new Node(5);
    Node* b=new Node(11);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(2);
    Node* f=new Node(1);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=f;
    cout<<TreeSum(a)<<endl;
    cout<<TreeMin(a)<<endl;
    cout<<TreeMaxSum(a)<<endl;
    return 0;
}