#include<iostream>
#include<queue>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d=0){
        data = d;
        left = NULL;
        right = NULL;
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
        return nullptr;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
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
vector<int> leftView(Node* root){
    vector<int> ans;
    if(root==nullptr) return ans;
    queue<pair<Node*,int>> q;
    int leftToRight=0;
    q.push({root,leftToRight});
    while(!q.empty()){
        int size=q.size();
        int flag=1;
        while(!q.empty() && q.front().second==(leftToRight)){
            pair<Node*,int> frontNode=q.front();
            q.pop();
            if(flag)ans.push_back(frontNode.first->data);
            flag=0;
            if(frontNode.first->left){
                q.push({frontNode.first->left,!leftToRight});
            }
            if(frontNode.first->right){
                q.push({frontNode.first->right,!leftToRight});  
            }
        }
        flag=1;
        leftToRight=!leftToRight;
    }
    return ans;
}
int main(){
    Node* root=nullptr;
    root=buildTree(root);
    vector<int> ans=leftView(root);
    for(int j: ans){
        cout<<j<<" ";
    }
    return 0;
}