#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
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
void paths(node* root,vector<int> way,vector<vector<int>> &result){
    if(root->left==nullptr && root->right==nullptr) {
        way.push_back(root->data);
        result.push_back(way);
        way.pop_back();
        return;
    }
    // cout<<root->data<<endl;
    way.push_back(root->data);
    paths(root->left,way,result);
    paths(root->right,way,result);
}
bool isSumTree(node* root)
{
    if(root->left==nullptr && root->right==nullptr) return true;
    if(isSumTree(root->left) && isSumTree(root->right)){
        // cout<<root->data<<endl;
        cout<<root->left->data+root->right->data<<" "<<root->data<<endl;
        if(root->left->data+root->right->data==root->data) return true;
        else return false;
    }
    else return false;
}
int main(){
    node* root=nullptr;
    root = buildTree(root);
    // vector<int> way;
    // vector<vector<int>> result;
    // paths(root,way,result);
    // 10 20 40 -1 -1 60 -1 -1 30 -1 -1
    // 10 20 10 -1 -1 10 -1 -1 30 -1 -1
     cout<<endl;
    cout<<isSumTree(root)<<endl;
    return 0;
}