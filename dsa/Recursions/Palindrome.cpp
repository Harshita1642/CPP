#include<iostream>
using namespace std;
bool Palindrome(string str,int j,int i)
{
    if(i>j)
        return true;
    if(str[i]!=str[j])
        return false;
    else
    {
        i++;
        return Palindrome(str,j-1,i);
    }
    
}
int main()
{
    string str="madam";
    cout<<Palindrome(str,str.length()-1,0)<<endl;
    return 0;
}