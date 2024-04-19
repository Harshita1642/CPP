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
Node* flatten(Node* root){
    Node* curr=root;
    while(curr!=NULL){
        if(curr->left){
            Node* pred=curr->left;
            while(pred->right){
                pred=pred->right;
            }
            pred->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
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
    Node* root=new Node(1);
    root->left = new Node(3);
    root->right = new Node(4);
    root->right->left = new Node(2);
    root->right->right = new Node(5);
    Node* ans=flatten(root);
    levelOrderTraversal(ans);
    return 0;
}