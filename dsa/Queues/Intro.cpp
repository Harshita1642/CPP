#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q;
    if(q.empty())
    {
        cout<<"Queue is empty "<<endl;
    }
    else
    {
        cout<<"Queue is not empty "<<endl;
    }
    q.push(12);
    q.push(13);
    q.push(14);
    cout<<"Front element of the queue "<<q.front()<<endl;
    cout<<"size of queue "<<q.size()<<endl;
    q.pop();
    cout<<"size of queue "<<q.size()<<endl;
    q.pop();
    q.pop();
    cout<<"size of queue "<<q.size()<<endl;
    if(q.empty())
    {
        cout<<"Queue is empty "<<endl;
    }
    else
    {
        cout<<"Queue is not empty "<<endl;
    }
    return 0;
}