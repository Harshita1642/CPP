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
int widthOfBT(Node* root){
    //In this question we are giving indexing to each node as per there level
    if(!root) return 0;
    int ans=0;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int size=q.size();
        int mmin=q.front().second;
        int first,last;
        for(int i=0 ; i<size ; i++){
            int cur_id=q.front().second-mmin;
            Node* node=q.front().first;
            q.pop();
            if(i==0)first=cur_id;
            if(i==size-1) last=cur_id;
            if(node->left){
                q.push({node->left,cur_id*2+1});
            }
            if(node->right){
                q.push({node->right,cur_id*2+2});
            }
        }
        ans=max(ans,last-first+1);
    }
    return ans;
}
void inorder(Node* root,vector<int> &in){
    if(root==nullptr) return;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
vector<int> mergeArray(vector<int> a,vector<int> b){
    vector<int> ans(a.size()+b.size());
    int i=0,j=0;
    int k=0;
    while(i<a.size() and j<b.size()){
        if(a[i]<b[j]){
            ans[k++]=a[i++];
        }
        else{
           ans[k++]=b[j++];
        }
    }
    while(i<a.size()){
        ans[k++]=a[i++];
    }

    while(j<b.size()){
        ans[k++]=b[j++];
    }
    return ans;
}
Node* inorderToBst(vector<int> &in,int start,int end){
    if(start>end) return nullptr;
    int mid=(start+end)/2;
    Node* root=new Node(in[mid]);
    root->left=inorderToBst(in,start,mid-1);
    root->right=inorderToBst(in,mid+1,end);
    return root;
}
Node* mergeBST(Node* root1,Node* root2){
    vector<int> bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);
    vector<int> arr=mergeArray(bst1,bst2);
    int s=0,e=arr.size()-1;
    return inorderToBst(arr,s,e);
} 
int main(){
    Node* root=nullptr;
    root=buildTree(root);
    // 1 3 5 -1 -1 3 -1 -1 2 -1 9 -1 -1 
    levelOrderTraversal(root);
    cout<<widthOfBT(root);
    return 0;
}