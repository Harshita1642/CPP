#include<iostream>
#include<vector>
#include<queue>
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
// brute force
vector<int> solveZigZag(Node* root){
    if(root==nullptr) return {};
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    int leftToRight=0;
    while(!q.empty()){
        vector<Node*> temp;
        while(q.size()>0){
            Node* frontNode=q.front();
            q.pop();
            temp.push_back(frontNode);
        }
        for( auto i: temp){
            Node* frontNode=i;
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
        if(leftToRight){
            for(int i=temp.size()-1 ; i>=0 ; i--){
                ans.push_back(temp[i]->data);
            }
        }
        else{
            for(auto i: temp){
                ans.push_back(i->data);
            }
        }
        leftToRight=!leftToRight;
    }
    return ans;
}
// optimised version
vector<vector<int>> solve(Node* root){
    vector<vector<int>> result;
    if(root==nullptr) return result;
    queue<Node*> q;
    q.push(root);
    bool leftToRight=true;
    while(!q.empty()){
        int size=q.size();
        vector<int> row(size);
        for(int i=0 ; i<size ; i++){
            Node* frontNode=q.front();
            q.pop();
            int index= leftToRight ? i: (size-1-i);
            row[index]=frontNode->data;
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
        leftToRight=!leftToRight;
        result.push_back(row);
    }
    return result;
}
int main(){
    vector<int> ans;
    Node* root=nullptr;
    root=buildTree(root);
    levelOrderTraversal(root);
    cout<<endl;
   ans=solveZigZag(root);
   for(int i : ans){
        cout<<i<<" ";
   }
   cout<<endl;
   vector<vector<int>> rs=solve(root);
    for(auto i: rs){
        for(auto j : i){
            cout<<j<<" ";
        }
    }
   // 4 2 1 -1 -1 3 -1 -1 7 6 -1 -1 9 -1 -1

    return 0;
}