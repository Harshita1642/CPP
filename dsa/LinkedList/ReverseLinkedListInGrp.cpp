#include<iostream>
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
void insertionAtTail(Node* &tail,int data){
    Node* temp=new Node(data);
    if(tail==NULL) {
        tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}
void print(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
pair<Node*,Node*> reverse(Node* head,int k,int i=0){
    if(i==k-1) return {head,head->next};
    pair<Node*,Node*> p=reverse(head->next,k,i+1);
    head->next->next=head;
    head->next=nullptr;
    return p;
}
int length(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
Node* reverseKGroup(Node* head, int k) {
    if(k==1) return head;
    int len=length(head);
    int n=len/k;
    pair<Node*,Node*> p=reverse(head,k);
    Node* ans=p.first;
    Node* temp=p.first;
    int i=1;
    Node* curr=p.second;
    while(i<=n-1){
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        pair<Node*,Node*> pu=reverse(curr,k);
        temp->next=pu.first;
        curr=pu.second;
        i++;
    }
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=curr;
    return ans;
}
int main(){
    Node* head=new Node(1);
    Node* tail=head;
    insertionAtTail(tail,2);
    insertionAtTail(tail,3);
    insertionAtTail(tail,4);
    print(head);
    int k=2;
    pair<Node*,Node*> ans=reverse(head,k);
    print(ans.first);
    print(ans.second);
    return 0;
}