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
Node* insertToBst(Node* root,int data){
    if(!root){
        Node* temp=new Node(data);
        return temp;
    }
    if(data>root->data){
        root->right=insertToBst(root->right,data);
    }
    else{
        root->left=insertToBst(root->left,data);
    }
    return root;
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
    int n;
    cin>>n;
    Node* root=nullptr;
    for(int i=0; i<n ; i++){
        int ele;
        cin>>ele;
        root=insertToBst(root,ele);
    }
    int target,k;
    cin>>target>>k;
    levelOrderTraversal(root);
    delete root;
    return 0;
}