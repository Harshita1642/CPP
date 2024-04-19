#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string s="harshita";
    stack<char> reverse;
    for(int i=0 ; i<s.length() ; i++)
    {
        reverse.push(s[i]);
    }
    string ans="";
    while(!reverse.empty())
    {
        ans.push_back(reverse.top());
        reverse.pop();
    }
    cout<<"reversed string is "<<ans<<endl;
    return 0;
}