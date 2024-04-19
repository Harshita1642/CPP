#include<iostream>
#include<vector>
#include<queue>
#include <algorithm> // For find
#include <utility> // For pair
#include<map>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data=0){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
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
void solve(Node* root,map<int,int> &track,int x){
    if(root==nullptr) return;
    if(track.find(x)==track.end()){
        track[x]=root->data;
    }
    solve(root->left,track,x-1);
    solve(root->right,track,x+1);
}
int main(){
    map<int,int> ans;
    Node* root=nullptr;
    root=buildTree(root);
    levelOrderTraversal(root);
    cout<<endl;
    solve(root,ans,0);
    for(auto p: ans){
        cout<<p.first<<" "<<p.second<<endl;
    }
   // 4 2 1 -1 -1 3 -1 -1 7 6 -1 -1 9 -1 -1

    return 0;
}