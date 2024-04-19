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
Node* buildTree(Node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
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
bool path(Node* root,int target,vector<int>& ans){
    if(!root) return false;
    if(root->data==target){
        ans.push_back(root->data);
        return true;
    }
    bool l=path(root->left,target,ans);
    bool r=path(root->right,target,ans);
    if(l || r){
        ans.push_back(root->data);
        return true;
    }
    return false;
}
// left-> prev right-> next
Node* change(Node* root){
    if(!root) return nullptr;
    Node* l=change(root->left);
    Node* r=change(root->right);
    l->right=root;
    root->left=l;
    root->right=r;
    r->left=root;
    return root;
}

void convertBstToDoublyLL(Node* root,Node* &prev){
    if(!root) return;
    convertBstToDoublyLL(root->left,prev);
    prev->right=root;
    root->left=prev;
    prev=root;
    convertBstToDoublyLL(root->right,prev);
}

int main(){
    Node* root=nullptr;
    root=buildTree(root);
    levelOrderTraversal(root);
    // vector<int> ans;
    // path(root,11,ans);
    // for(auto ele: ans){
    //     cout<<ele<<" ";
    // }
    // Node* ans=change(root);
    // levelOrderTraversal(ans);
    Node* dummy=new Node(-1);
    Node* prev=dummy;
    convertBstToDoublyLL(root,prev);
    // levelOrderTraversal(dummy->right);
    Node* temp = dummy->right;
    while(temp->right!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    return 0;
}