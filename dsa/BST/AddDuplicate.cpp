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
    ~Node(){
        delete left;
        delete right;
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
void solve(Node* &root){
    if(root==nullptr) return ;
    Node* dup=new Node(root->data);
    Node* nextNode=nullptr;
    if(root->left){
        nextNode=root->left;
    }
    root->left=dup;
    dup->left=nextNode;
    solve(nextNode);
    solve(root->right);
}
void print(Node* root){
	if(root==NULL){
		return;
	}

	if(root->left){
		cout<<root->left->data<<" ";
	}
	else{
		cout<<"END"<<" ";
	}
	cout<<"=> ";
	cout<<root->data<<" ";
	cout<<"<= ";
	if(root->right){
		cout<<root->right->data;
	}
	else{
		cout<<"END";
	}
	cout<<endl;
	print(root->left);
	print(root->right);
}
int main(){
    Node* root=nullptr;
    int n,ele;
    cin>>n;
    // cout<<n<<endl;
    for(int i=0 ; i<n ; i++){
        cin>>ele;
        root=insertToBST(root,ele);
    }
    Node* dummy=root;
    // levelOrderTraversal(root);
    solve(root);
    // cout<<endl;
    // levelOrderTraversal(dummy);
    print(dummy);
    delete root;
    return 0;
}