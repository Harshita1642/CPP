#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
    ~Node()
    {
        int val=this->data;
        if(next!=NULL)
        {
            delete next;
            next=NULL;
        }
        cout<<"Memory free for node with data "<<this->data<<endl;
    }
};
void insertAtHead(Node* &tail,Node* &head,int data){
    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else{
        //new node create;
        Node* temp=new Node(data);
        temp->next=head;
        head->prev=temp->next;
        head=temp;

    }
}
void insertAtTail(Node* &tail,Node* &head,int data){
    if(tail==NULL){
        Node* temp=new Node(data);
        tail=temp;
        head=temp;
    }
    else
    {
        //new node create;
        Node* temp=new Node(data);
        tail->next=temp;
        temp->prev=tail;
        temp->next=NULL;
        tail=temp;
    }
}
void insertAtPosition(Node* &tail,Node* &head,int position,int data){
    if(position==1){
        insertAtHead(head,tail,data);
        return;
    }
    Node* insertNode=new Node(data);
    Node* temp=head;
    int cnt=1;
    while(cnt< position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        insertAtTail(tail,head,data);
        return;
    }
    insertNode->next=temp->next;
    temp->next->prev=insertNode;
    temp->next=insertNode;
    insertNode->prev=temp;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){ 
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void deleteNode(int position,Node* &head){
    if(position==1)
    {
        Node* temp=head;
        temp->next->prev=NULL;
        //head ko aage shift krdo
        head=temp->next;
        //aur phele vale node ki memory free krdo
        temp->next=NULL;
        delete temp;
    }
    else
    {
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position)
        {
            prev=curr;
            curr=curr->next;  
            cnt++; 
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int getLength(Node* &head)
{
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    //cout << getLength(head) << endl;

    insertAtHead(tail,head, 11);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtHead(tail,head, 13);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtHead(tail,head, 8);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtTail(tail,head, 25);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtPosition(tail, head, 2, 100);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtPosition(tail, head, 1, 101);
    print(head);

    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtPosition(tail, head, 7, 102);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    deleteNode(1, head);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;



    return 0;
}