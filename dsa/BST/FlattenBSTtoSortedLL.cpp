#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void inorder(TreeNode<int>* root, vector<int> &in){
    if(root == nullptr) return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

void formLinkedList(TreeNode<int>* root, vector<int> &in, int &i){
    if(root == nullptr) return;

    if(i <= in.size() - 1) {
        root->left = nullptr;
        root->right = new TreeNode<int>(in[i++]);
        root = root->right;
        formLinkedList(root, in, i);
    } else {
        root->left = nullptr;
        root->right = nullptr;
    }
}

TreeNode<int>* flatten(TreeNode<int>* root) {
    if(root == nullptr)
        return nullptr;

    vector<int> in;
    inorder(root, in);

    TreeNode<int>* newRoot = new TreeNode<int>(in[0]);
    int index = 1;
    formLinkedList(newRoot, in, index);

    return newRoot;
}

// Example usage in main function
int main() {
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(5);
    root->left->left = new TreeNode<int>(3);
    root->left->right = new TreeNode<int>(4);
    root->right->right = new TreeNode<int>(6);

    TreeNode<int>* flattenedList = flatten(root);

    cout << "Flattened Linked List:" << endl;
    while(flattenedList != nullptr) {
        cout << flattenedList->data << " ";
        flattenedList = flattenedList->right;
    }
    cout << endl;

    delete root; // Clean up memory
    return 0;
}
