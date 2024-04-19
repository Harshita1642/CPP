#include<iostream>
#include<math.h>
#include<algorithm>
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
void createTree(Node* root,int n){
    if(n==0) return;
    if((char)root->data=='M'){
        Node* child1=new Node('M');
        Node* child2=new Node('F'); 
        root->left=child1;
        root->right=child2;
    }
    else{
        Node* child1=new Node('F');
        Node* child2=new Node('M'); 
        root->left=child1;
        root->right=child2; 
    }
    createTree(root->left, n-1);
    createTree(root->right, n-1);
}
void breadthfirstValues(Node* root,vector<char>& ans){
    //Time Complexity O(n)...n no of nodes
    //Space Complexity O(n)
    if(root==nullptr) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
         ans.push_back((char)curr->data);
        q.pop();
        if(curr->left!=nullptr) q.push(curr->left);
        if(curr->right!=nullptr) q.push(curr->right);
    }
}
string kthChildNthGeneration(int n, long long int k)
{
    if(n==1) return "Male";
    Node* root=new Node('M');
    vector<char> ans;
    createTree(root, n-1);
    breadthfirstValues(root, ans);
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    // cout<<endl<<ans[((2*n-3)-1)+(k)]<<endl;
    int prev=2*(pow(2,n-2)-1);
    cout<<prev<<endl;
    if(ans[prev+(k)]=='F') return "Female";
    else return "Male";
    // return "uhh";
}
int main(){
    cout<<kthChildNthGeneration(7,37);
    return 0;
}