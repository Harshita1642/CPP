#include<iostream>
using namespace std;
class kQueues
{
public:
    //Data members required
    int n,k;
    int *arr;
    int *front;  
    int *rear;
    int *next;
    int freespot;
    //Constructor
    kQueues(int n,int k)
    {
        this->n=n;
        this->k=k;
        front=new int[k];//for tracking the elements of queues for pop operation
        rear=new int[k];//for tracking the elements of queues for push operation
        arr=new int[n];//this our main array with k queues
        next=new int[n];//for tracking indexes of free list as well as keep record of which queue's element present at what index
        for(int i=0; i<k ;i++)
        {
            front[i]=-1;
        }
        for(int i=0; i<k ;i++)
        {
            rear[i]=-1;
        }
        for(int i=0; i<n-1 ;i++)
        {
            next[i]=i+1;
        }
        next[n-1]=-1;
        freespot=0;
    }
    bool enqueue(int data,int qn){
        if(freespot==-1)//if ur freespot reaches the -1 of the next index while traversing this means arr is full
        {
            return false;
        }
        int index=freespot; //finding the vacany where to insert the element
        freespot=next[index];//updating the value of freespot
        //if its ur 1st element
        if(front[qn-1]==-1)
        {
            front[qn-1]=index;
        }
        else
        {//link new element to the prev element
            next[rear[qn-1]]=index;
        }
        //update next
        next[index]=-1;
        //update rear
        rear[qn-1]=index;
        //push element
        arr[index]=data;
        return true;
    }
    int dequeue(int qn)
    {
        if(front[qn-1]==-1) //check undderflow
        {
            return -1;
        }

        int index=front[qn-1];
        front[qn-1]=next[index];
        next[index]=freespot;
        freespot=index;
        return arr[index];
    }
};
int main()
{
    kQueues q(10,3);
    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    return 0;
}