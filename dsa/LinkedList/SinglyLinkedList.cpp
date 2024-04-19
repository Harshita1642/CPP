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
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            
            delete next; 
            this->next=NULL;
        }
    }
};
void insertAtHead(Node* &tail,Node* &head,int d){
    if(head==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else
    {
        //new node create
        Node* temp=new Node(d);
        temp->next=head;
        head=temp;  
    }
}
void insertAtTail(Node* &tail,Node* &head,int d)
{   
    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else{
        //new node create
        Node* temp=new Node(d);
        tail->next=temp;
        tail=temp;
    }
} 
void insertAtPosition(Node* &tail,Node* &head,int position,int d)
{
    //insert at Start
    if(position==1)
    {
        insertAtHead(tail,head,d);
        return ; 
    }
    Node* temp=head;
    int cnt=1;
    while(cnt< position-1)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        tail=temp;
    }
    Node* nodetoInsert=new Node(d);
    nodetoInsert->next=temp->next;
    temp->next=nodetoInsert;
}
void deleteNode(int position,Node* &head){
    // cout<<"I am in fnc"<<endl;
    if(position==1)
    {
        Node* temp=head;
        //head ko aage shift krdo
        head=head->next;
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
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
Node * uniqueSortedList(Node * head) {
   	//empty List
    if(head == NULL)
        return NULL;
    cout<<" i m in fnc"<<endl;
    //non empty list
    Node* curr = head;
    
    while(curr != NULL) {
        cout<<" i m in fnc"<<endl;
        if( (curr -> next != NULL) && curr -> data == curr -> next -> data) {
            Node* next_next = curr ->next -> next;
            // Node* nodeToDelete =  curr -> next;
            // delete(nodeToDelete);
            curr -> next = next_next;
        }
        else //not equal
        {
            curr = curr -> next;
        }   
    }
    
    return head; 
}
Node* removeDuplicates(Node* head){
    if(head==NULL)
    {
        return NULL;
    }
    Node* curr=head;
    Node* temp,*nodeToDelete;
    while(curr!=NULL && curr->next!=NULL)
    {
        temp=curr;
        while(temp->next!=NULL)
        {
            cout<<"temp->data "<<temp->data<<endl;
            if(curr->data==temp->next->data)
            {
                // cout<<"temp->data "<<temp->data<<endl;
                nodeToDelete =  temp->next;
                // delete(nodeToDelete); 
                temp->next= temp->next->next;
                // // cout<<"temp->data "<<temp->data<<endl;
            }
            else{
                temp=temp->next;
            }
        }
        curr=curr->next;
    }
    return head;
}
Node* reverseLinkedList(Node* head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
Node* recurrsiveReverse(Node* &head,Node* curr,Node* prev){
    //Base condition
    if(curr==NULL)
    {
        head=prev;
        return prev;
    }
    Node* forward=curr->next;
    return recurrsiveReverse(head,forward,curr);
    curr->next=prev;
}
Node* addOne(Node *head) 
{
        if(head->next==NULL)
        {
            head->data+=1;
            return head;
        }
        // Your Code here
        // return head of list after adding one
        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->data+=1;
        return head;
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
int main()
{
    //created a new node
    Node* node1=new Node(9);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    Node* rs=addOne(node1);
    cout<<"mera ans";
    print(rs);
    Node* node2=new Node(15);
    //head pointed to node1
    Node* head=node1;
    Node* tail=node1;
    print(head);
    insertAtTail(tail,head,2);
    print(head); 
    insertAtTail(tail,head,5);
    insertAtTail(tail,head,4);
    insertAtTail(tail,head,2);
    insertAtTail(tail,head,2);
    print(head);
    // Node* cn=uniqueSortedList(head);
    // print(cn);
    // removeDuplicates(head);
    Node* check=removeDuplicates(head);
    print(check);
    // insertAtPosition(tail,head,1,8);
    // print(head);
    // cout<<"head "<<head->data<<endl;
    // cout<<"tail "<<tail->data<<endl;
    // deleteNode(4,head);
    // print(head);
    // cout<<"head "<<head->data<<endl;
    // cout<<"tail "<<tail->data<<endl;
    // Node* reversed=reverseLinkedList(head);
    // print(reversed);
    // cout<<"head "<<endl;
    // print(head);
    // Node* prev=NULL;
    // Node* curr=head;
    // Node* reverseKaro=recurrsiveReverse(head,curr,prev);
    // print(reverseKaro);
    return 0;
}