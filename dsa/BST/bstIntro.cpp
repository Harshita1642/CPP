#include<iostream>
#include<queue>
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
void inorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}
bool serachInBST(Node* root,int data){
    //Recursive approach hai tun eski T.C--> O(logn) /O(height) and S.C--> O(height)
    //so to reduce the space complexity we can use iterative approach
    if(root==nullptr) return false;
    if(data > root->data){
        return serachInBST(root->right,data);
    }
    else if(data==root->data){
        return true;
    }
    else{
        return serachInBST(root->left,data);
    }
}
bool search(Node* root,int data){
    Node* temp=root;
    while(temp!=NULL){
        if(temp->data==data){
            return true;
        }
        if(temp->data > data){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return false;
}
int minVal(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}
int maxVal(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
}
Node* deleteFromBST(Node* root,int val){
    if(root==NULL) return root;
    if(root->data==val){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child
        // left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        // 2 children
        if(root->left!=NULL && root->right!=NULL){
            int mini=minVal(root->right);
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }
    }
    else if(root->data > val){
        root->left=deleteFromBST(root->left,val);
        return root;
    }
    else{
        root->right=deleteFromBST(root->right,val);
        return root;
    }
}
int main(){
    Node* root=NULL;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);
    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);
    // 10 8 21 7 25 5 4 3 -1
    cout<<"Printing Inorder"<<endl;
    inorder(root);
    cout<<endl<<"Printing Preorder"<<endl;
    preorder(root);
    cout<<endl<<"Printing Postorder"<<endl;
    postorder(root);
    cout<<endl<<"27 prsent or not "<<serachInBST(root,27)<<endl;
    cout<<"3 prsent or not "<<search(root,3);
    cout<<endl<<"Minimum Value of tree"<<minVal(root)<<endl;
    cout<<"Maximum Value of tree"<<maxVal(root)<<endl;

    root=deleteFromBST(root,7);
    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);
        return 0;
}