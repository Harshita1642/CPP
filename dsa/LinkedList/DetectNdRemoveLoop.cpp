#include<iostream>
#include<map>
using namespace std;
class Node{
public: 
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
void insertionAtTail(Node* &tail,int data){
    Node* temp=new Node(data);
    if(tail==nullptr){
        tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}
void print(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
    }
}
bool detect(Node* head){
    if(head==nullptr || head->next==nullptr) return false;
    map<Node*,bool> visited;
    Node* temp=head;
    while(temp->next!=nullptr){
        
    }
}
int main(){
    return 0;
}