#include<iostream>
#include<queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* solve(Node* root){
    if(!root) return nullptr;
    if((root->left==nullptr && root->right==nullptr)) return root;
    root->right=solve(root->right);
    Node* l=root;
    if(root->left){
        l=solve(root->left);
        root->left=nullptr;
        Node* curr=l;
        while(curr->right){
            curr=curr->right;
        }
        curr->right=root;
    }
    // l->right=root;
    if(root->left){
        cout<<"*";
        Node* temp=root->left;
        root->left=nullptr;
        // Node* curr=temp;
        // while(curr->right){
        //     curr=curr->right;
        // }
        temp->right=root;
        // curr->right=temp;
        cout<<root->data<<" "<< temp->data<<endl;
        return temp;
    }
    return l;
}
Node *flattenBST(Node *root)
{
    // code here
    return solve(root);
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
    // 5 3 7 2 4 6 8
    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);
    Node* ans=flattenBST(root);
    cout<<"Printing flatten bst"<<endl;
    levelOrderTraversal(ans);
    return 0;
}