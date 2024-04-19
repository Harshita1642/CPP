#include<iostream>
using namespace std;
class LinkedList{
public:
    int val;
    LinkedList* next;
    LinkedList(){
        val=0;
        next=nullptr;
    }
    LinkedList(int d){
        val=d;
        next=nullptr;
    }
};
class MyLinkedList {
    LinkedList* head;
    LinkedList* tail;
    int index;
public:
    MyLinkedList() {
        head=new LinkedList();
        tail=new LinkedList();
        index=0;
    }
    
    int get(int index) {
        int i=0;
        LinkedList* temp=head;
        while(i<index && temp->next!=nullptr){
            temp=temp->next;
            i++;
        }
        if(i==index) return temp->val;
        return -1;
    }
    
    void addAtHead(int val) {
        LinkedList* temp=new LinkedList(val);
        if(index==0){
            head=temp;
            tail=temp;
        }
        else{
            // cout<<"entered";
            temp->next=head;
            head=temp;
        }
        // cout<<head->val<<" "<<temp->val<<" "<<endl;
        index++;
    }
    
    void addAtTail(int val) {
        LinkedList* temp=new LinkedList(val);
        if(index==0){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        index++;
    }
    
    void addAtIndex(int j, int val) {
        if(j>index){
        return;}
        else if(j == index){
            addAtTail(val);
            return;}
        else if(j==0)
        {addAtHead(val);
            return;}
        int i=0;
        LinkedList* temp=head;
        while(i<j-1 && temp!=nullptr){
            temp=temp->next;
            i++;
        }
        LinkedList* newNode=new LinkedList(val);
        LinkedList* nextNode=temp->next;
        temp->next=newNode;
        newNode->next=nextNode;
        index++;
    }
    void print(){
        LinkedList* temp=head;
        while(temp!=nullptr){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void deleteAtIndex(int i) {
        if(index==0){
            head=NULL;
            return;
        }
        if(i>=index) return;
        else if(i == index-1){
            if(i==0){
                head=NULL;
                tail=NULL;
            }
            else{
                LinkedList* temp = head;
                while(temp->next!=tail) {
                    temp= temp->next;
                }
                tail = temp;
                temp->next = NULL;
            }
        }
        else if(i==0) {
            LinkedList* temp = head;
            head = head->next;
            temp =NULL;
        }
        else {
            LinkedList* temp = head;
            for(int j=0; j<i-1;++j) {
                temp = temp->next;
            }
            LinkedList* t = temp->next;
            temp->next = temp->next->next;
            t->next = NULL;
            
        }
        index--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main(){
    MyLinkedList* obj = new MyLinkedList();
    // obj->addAtHead(7);
    // obj->addAtHead(2);
    // obj->addAtHead(1);
    // obj->addAtIndex(3,0);
    // obj->deleteAtIndex(2);
    // obj->addAtHead(6);
    // obj->print();
    // obj->addAtTail(4);
    // obj->print();
    // cout<<obj->get(4);
    // obj->print();
    // obj->addAtHead(4);
    // obj->addAtIndex(5,0);
    // obj->addAtHead(6);
    // obj->print();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    obj->print();
    obj->deleteAtIndex(1);
    obj->deleteAtIndex(1);
    obj->deleteAtIndex(1);
    obj->print();

    return 0;
}