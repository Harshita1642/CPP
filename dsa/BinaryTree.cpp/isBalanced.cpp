#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *build(string s)
{
    if (s == "true")
    {
        int d;
        cin >> d;
        node *root = new node(d);
        string l;
        cin >> l;
        if (l == "true")
        {
            root->left = build(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = build(r);
        }
        return root;
    }
    return NULL;
}

pair<int,bool> isHeightBalancedOptimised(node *root)
{
    // Write your code here
    if(root==nullptr) return {0,true};
    pair<int,bool> lh= isHeightBalancedOptimised(root->left);
    pair<int,bool> rh= isHeightBalancedOptimised(root->right);
    bool isBalanced= lh.second && rh.second && abs(lh.first-rh.first)<=1;
    int height= max(lh.first,rh.first)+1;
    return {height,isBalanced};
}

int main()
{
    node *root = build("true");
    //10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
    cout << boolalpha << isHeightBalancedOptimised(root).second;

    return 0;
}
