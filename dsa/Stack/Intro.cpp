#include<iostream>
#include<stack>
using namespace std;
//khud ki implemented stack ho STL use nhi krr skte
class Stack{
public:
    int *arr;
    int top;
    int size;
    Stack(int size)
    {
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int element)
    {//Time Complexity: O(1)
        if(size-top>1)
        {
            top++;
            arr[top]=element;
        }
        else
        {
            cout<<"Stack overflow"<<endl;
        }
    }
    void pop()
    {//Time Complexity: O(1)
        if(top>=0)
        {
            top--;
        }
        else
        {
            cout<<"Stack underflow"<<endl;
        }
    }
    bool empty()
    {//Time Complexity: O(1)
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int peek()
    {//Time Complexity: O(1)
        if(top>0 && top<size)
        {
            return arr[top];
        }
        else
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }
    void print()
    {//Time Complexity: O(size)
        for(int i=0 ; i<size ; i++)
        {
            cout<<arr[i]<<"\t";
        }
    }
};
//Make a stack using linked list
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
class newStack{
public:
    Node* LL=new Node(-1);
    Node* temp=LL;
    void push(int element)
    {
        Node* insertNode= new Node(element);
        temp->next=insertNode;
        temp=insertNode;
    }
    void pop()
    {
        temp=LL->next;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }
    bool empty()
    {
        if(LL->data==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int top()
    {
        temp=LL->next;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        return temp->data;
    }
    void print()
    {
        temp=LL->next;
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }
};
int main()
{
    // creation of a stack
    stack<int> phelaStack;

    //Inserting the elements in our phelaStack using push fnc
    phelaStack.push(2);
    phelaStack.push(3);
    phelaStack.push(4);

    //Removing the last input from the stack using pop fnc
    phelaStack.pop();//it will remove 4 from phelaStack

    cout<<"Printing the top element "<<phelaStack.top()<<endl;

    if(phelaStack.empty())
    {
        cout<<"phelaStack is empty bro"<<endl;
    }
    else
    {
        cout<<"phelaStack contains some elements bro"<<endl;
    }

    
    Stack meraStack(5);
    meraStack.push(22);
    meraStack.push(23);
    meraStack.push(24);
    meraStack.push(25);
    meraStack.push(26);
    cout<<"elements of meraStack: "<<endl;
    meraStack.print();
    meraStack.pop();
    cout<<endl<<"Topmost element of meraStack : "<<meraStack.peek()<<endl;
    meraStack.pop();
    cout<<endl<<"Topmost element of meraStack : "<<meraStack.peek()<<endl;
    meraStack.push(81);
    meraStack.push(69);
    meraStack.print();
    meraStack.push(1);

    newStack apnaStack;
    cout<<apnaStack.empty()<<endl;
    apnaStack.push(99);
    apnaStack.push(98);
    apnaStack.print();
    cout<<endl<<apnaStack.top();
    apnaStack.pop();
    cout<<endl;
    apnaStack.print();
    return 0;
}