#include<iostream>
#include<bits/stdc++.h>
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
};
// create mapping and return target node
Node* createParentMapping(Node* root,int target,map<Node*,Node*> &nodeToParent){
    Node* result=nullptr;
    queue<Node*> q;
    q.push(root);
    nodeToParent[root]=nullptr;
    while(!q.empty()){
        Node* front=q.front();
        q.pop();
        if(front->data==target) result=front;
        if(front->left){
            nodeToParent[front->left]=front;
            q.push(front->left);
        }
        if(front->right){
            nodeToParent[front->right]=front;
            q.push(front->right);
        }
    }
    return result;
}
int burnTree(Node* root,map<Node*,Node*> &nodeToParent){
    map<Node*,bool> visited;
    queue<Node*> q;
    q.push(root);
    visited[root]=true;
    int ans=0;
    while(!q.empty()){
        bool flag=false;
        int size=q.size();
        for(int i=0 ; i<size ; i++){
            Node* front=q.front();
            q.pop();
            if(front->left && !visited[front->left]){
                flag=true;
                q.push(front->left);
                visited[front->left]=true;
            }
            if(front->right && !visited[front->right]){
                flag=true;
                q.push(front->right);
                visited[front->right]=true;
            }
            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag=true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]]=true;
            }
        }
        if(flag) ans++;
    }
    return ans;
}
int minTime(Node* root,int target){
    //algo:
    //step1: create nodeToParent mapping
    //step2: fnd target node
    //step3: burn the tree in min time
    //Time Complexity: O(n)+O(n)
    //Space Complexity: O(n)+O(n)-->O(n)
    map<Node*,Node*> nodeToParent;
    Node* targetNode=createParentMapping(root,target,nodeToParent);
    int ans=burnTree(targetNode,nodeToParent);
    return ans;
}
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
int main(){
    Node* root=nullptr;
    root=buildTree(root);
    cout<<minTime(root,8);
    //Input: 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1
    // output: 7
    return 0;
}