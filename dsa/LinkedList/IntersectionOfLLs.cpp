#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    ~Node() {
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};
void insertAtTail(Node* &tail,int d)
{   
    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        // head=temp;
    }
    else{
        //new node create
        Node* temp=new Node(d);
        tail->next=temp;
        tail=temp;
    }
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
Node* intersection(Node* l1,Node* l2){
    Node* curr1=l1;
    Node* curr2=l2;
    Node* prev1=NULL;
    Node* prev2=NULL;
    Node* ans=NULL;
    Node* temp = nullptr;
    while(curr1!=NULL && curr2!=NULL){
        if(curr1->data<curr2->data){
            prev1=curr1;
            curr1=curr1->next;
        }
        else if(curr2->data< curr1->data){
            prev2=curr2;
            curr2=curr2->next;
        }
        else{
            prev1->next=curr1->next;
            prev2->next=curr2->next;
            if(ans==nullptr){
                ans = curr1;
                temp=ans;
                temp->next=curr2;
                temp= temp->next;
            }else{
                temp->next=curr1;
                temp=temp->next;
                temp->next = curr2;
                temp=temp->next;
            }
            curr1=prev1->next;
            curr2=prev2->next;
        }
    }
    temp->next=NULL;
    return ans;
}
int main() {
   Node* l1=new Node(0);
    Node* l1Head=l1;
    int a;
    cout<<"Enter elements  of 1st LL: "<<endl;
    do{
        cin>>a;
        insertAtTail(l1,a);
    }while(a!=-1);
    print(l1Head->next);
    Node* l2=new Node(0);
    Node* l2Head=l2;
    int b;
    cout<<"Enter elements  of 1st LL: "<<endl;
    do{
        cin>>b;
        insertAtTail(l2,b);
    }while(b!=-1);
    print(l2Head->next);
    Node* ans=intersection(l1Head->next,l2Head->next);
    print(ans);
    print(l1Head->next);
    print(l2Head->next);

    return 0;
}