#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int d){
        this->data=d;
        this->next=nullptr;
    }
};
void traversal(Node* head){//recursive approach
    if(head==nullptr) return;
    cout<<(char)head->data<<"\t";
    traversal(head->next);
}
void print(Node* head){//iterative approach
    while(head!=nullptr){
        cout<<(char)head->data<<"\t";
        head=head->next;
    }
    cout<<endl;
}
void LinkedListValues(Node* head,vector<char> &ans){
    if(head==nullptr) return;
    ans.push_back((char) head->data);
    LinkedListValues(head->next,ans);
}
int sumList(Node* head){
    if(head==nullptr) return 0;
    return head->data+sumList(head->next);
}
char getNodeValue(Node* head,int index,int level=0){
    if(head==nullptr) return '0';
    if(level==index) return (char)head->data;
    return getNodeValue(head->next,index,level+1);
}
void zipperLinkedLists(Node* a,Node* q){//T.C --> O(min(n,m))...n is no of nodes in list1 and m is no of nodes in list2
    if(a==nullptr || q==nullptr) return;
    Node* first=a->next;
    Node* second=q->next;
    q->next=first;
    a->next=q; 
    zipperLinkedLists(first,second);
}
Node* zipperLL(Node* head1,Node* head2){//T.C --> O(min(n,m))...n is no of nodes in list1 and m is no of nodes in list2
    Node* tail=head1;
    Node* curr1=head1;
    Node* curr2=head2;
    int cnt=0;
    while(curr1!=nullptr && curr2!=nullptr){
        if(cnt%2==0){
            tail->next=curr2;
            curr2=curr2->next;
        }else{
            tail->next=curr1;
            curr1=curr1->next;
        }
        tail=tail->next;
        cnt++;
    }
    if(curr1!=nullptr) tail->next=curr1;
    if(curr2!=nullptr) tail->next=curr2;
    return head1;
}
int main(){
    Node* a=new Node('a');
    Node* b=new Node('b');
    Node* c=new Node('c');
    Node* d=new Node('d');
    a->next=b;
    b->next=c;
    c->next=d;
    Node* q=new Node('q');
    Node* r=new Node('r');
    Node* s=new Node('s');
    q->next=r;
    r->next=s;
    zipperLinkedLists(a,q);
    print(a);
    Node* ans=zipperLL(a,q);
    print(ans);
    // traversal(a);
    // cout<<endl;
    // print(a);
    // vector<char> ans;
    // LinkedListValues(a,ans);
    // for(int i=0 ; i<ans.size() ; i++){
    //     cout<<ans[i]<<"\t";
    // }
    // cout<<endl<<getNodeValue(a,2);
    // Node* a=new Node(1);
    // Node* b=new Node(2);
    // Node* c=new Node(3);
    // Node* d=new Node(4);
    // a->next=b;
    // b->next=c;
    // c->next=d;
    // cout<<sumList(a);
    return 0;
}