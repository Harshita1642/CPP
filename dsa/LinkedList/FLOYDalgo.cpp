//FLOYD->used for cycle detection
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void insertAtHead(Node* &tail,Node* &head,int data)
{
    if(head==NULL)
    {
        Node* insertNode=new Node(data);
        head=insertNode;
        tail=insertNode;
    }
    else{
        Node* insertNode=new Node(data);
        insertNode->next=head;
        head=insertNode;
    }
}
void insertAtTail(Node* &tail,int d)
{   //new node create
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
} 
void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* floydDetectLoop(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;
    Node* temp=head;
    while(temp!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast)
        {
            return slow;
        }
    }
    if(temp==NULL)
    {
        return NULL;
    }
}
Node* getStartingNode(Node* head){
    if(head==NULL)
    {
        return NULL;
    }
    Node* intersection=floydDetectLoop(head);
    Node* slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
void removeLoop(Node* head)
{
    if(head==NULL)
    {
        return;
    }
    Node* startingnode=getStartingNode(head);
    Node* temp=startingnode;
    while(temp->next!=startingnode)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}
int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    insertAtHead(tail,head,10);
    insertAtHead(tail,head,12);
    insertAtHead(tail,head,25);
    insertAtHead(tail,head,22);
    print(head);
    cout<<"tail "<<tail->next<<endl;
    tail->next=head->next;
    if(floydDetectLoop(head))
    {
        cout<<"It is a circular Linked List"<<endl;
    }
    else
    {
        cout<<"It is not a circular Linked List"<<endl;
    }
    Node* startingNode=getStartingNode(head);
    cout<<"Starting node of CLL "<<startingNode->data<<endl;
    removeLoop(head);
    print(head);
    return 0;
}