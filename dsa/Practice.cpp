// // #include <iostream>
// // using namespace std;
// // int main() {
// //     int firstvalue = 5, secondvalue = 15;
// //     char thirdvalue = 'a';
// //     int * p1, * p2;
// //     char * p3;
// //     p1 = & firstvalue; // p1 = address of firstvalue... *p1=5
// //     p2 = & secondvalue; // p2 = address of secondvalue... *p2=15
// //     p3 = & thirdvalue; // p3 = address of thirdvalue... *p3='a'
// //     * p1 = 10; // value pointed to by p1 = 10
// //     * p2 = * p1; // value pointed to by p2 = value pointed to by p1
// //     p1 = p2; // p1 = p2 (value of pointer is copied)
// //     * p1 = 20; // value pointed to by p1 = 20
// //     * p3 = 'b'; // value pointed to by p3 = ‘b ’
// //     cout << "firstvalue is " << firstvalue << endl;
// //     cout << "secondvalue is " << secondvalue << endl;
// //     cout << "thirdvalue is " << thirdvalue << endl;
// //     return 0;
// // }
// // #include <iostream>
// // using namespace std;
// // int main() {
// //     // Null Pointer 
// //     int * ptr = NULL;
// //     cout << "The value of ptr is " << ptr;
// //     return 0;
// // }
// //Double Pointers
// // #include<iostream>
// // using namespace std;
// // int main() {
// //     int a = 10;
// //     int * p = & a; //pointer
// //     int ** q = & p; //pointer-to-pointer
// //     /* Next three statements will print same value i.e. address of a */
// //     cout << & a << endl;
// //     cout << p << endl;
// //     cout << * q << endl;
// //     /* Next two statements will print same value i.e. address of p */
// //     cout << & p << endl;
// //     cout << q << endl;
// //     /* Next three statements will print same value i.e. value of a */
// //     cout << a << endl;
// //     cout << * p << endl;
// //     cout << ** q << endl;
// //     return 0;
// // }
// // #include<iostream>
// // using namespace std;
// // int * fun() {
// //     int x = 10;
// //     return &x;
// // }
// // int main() {
// //     int * p = fun();
// //     // p points to something which is not 
// //     // valid anymore 
// //     cout << * p;
// //     return 0;
// // }
// // #include<iostream>
// // #include<bits/stdc++.h>
// // using namespace std;
// // bool panagram(string s){
// //     int alpha[26]={0};
// //     for(int i=0 ; i<s.length() ; i++){
// //         if(s[i]!=' ')alpha[s[i]-97]+=1;
// //     }
// //     for(int i=0 ; i<26 ; i++){
// //         if(alpha[i]==0) return false;
// //     }
// //     return true;
// // }
// // string removeSpaces(string s){
// //     string ans;
// //     for(int i=0 ; i<s.length() ; i++){
// //        if(s[i]==' ') ans+=i;
// //     }
// //     return ans;
// // }
// // int main(){
// //     string s;
// //     getline(cin,s);
// //     cout<<panagram(s)<<endl;
// //     cout<<removeSpaces(s);
// //     return 0;
// // }
// // #include<iostream>
// // using namespace std;
// // void rotateString(string &s,int k){
// //     int n=s.length();
// //     for(int i=0 ; i<k ; i++){
// //         char first=s[0];
// //         for(int j=0 ; j<n ; j++){
// //             s[j]=s[j+1];
// //         }
// //         s[n-1]=first;
// //     }
// // }
// // int main(){
// //     string s;
// //     getline(cin,s);
// //     int k=6;
// //     rotateString(s,k);
// //     cout<<s;
// //     return 0;
// // }
// #include<iostream>
// using namespace std;
// class Room{
//     private:
//     int cute=1;
//     public:
//     int l=1,b=2,h=3;
//     Room(){//default
//         cout<<"constructor"<<endl;
//     }
//     Room(int l,int b,int h){//parameterised
//         this->l=l;
//         this->b=b;
//         this->h=h;
//     }
//     void print() const{
//         cout<<l<<" "<<b<<" "<<h<<endl;
//     }
//     void getPrivate(){
//         cout<<this->cute<<endl;
//     }
//     ~Room(){
//         cout<<"destructor"<<endl;
//     }
//     int volume(Room* r);
// };
// int Room::volume(Room* r){
//     return r->l*r->b*r->h;
// }
// class my_class;
// class my_num{
//     public:
//     static int a;
//     my_num(){
//         cout<<"hi"<<endl;
//     }
//     // void display(my_Class obj){
//     //     cout<<obj.x<<" "<<obj.y<<endl;
//     // }
// };
// class my_Class
// {
//  private:
//  int x=6;
//  protected:
//  int y=7;
//     friend int add(my_Class o);
//     friend class my_num;
// };
// int add(my_Class obj)
// {
// return obj.x + obj.y;
// }
// int my_num::a=50;
// int main(){
//     my_num n;
//     cout<<sizeof(my_num)<<endl;
//     cout<<sizeof(my_num::a);
    
//     const Room r;
//     r.print();
//     my_Class obj;
//     cout << "Addition of Private & Protected members - " << add(obj);
//     return 0;
// }
// #include<iostream>
// #include<algorithm>
// using namespace std;
// bool isPalindrome(string s){
//     string t=s;
//     reverse(s.begin(),s.end());
//     return t==s;
// }
// int main(){
//     // string s="aMy b yMa";
//     string s="dnnaa";
//     for(int i=0 ; i<s.length()-1 ; i++){
//         for(int j=i+1; j<s.length() ; j++){
//             if(s[i]==s[j]){
//                 s.erase(s.begin()+j);
//                 s.erase(s.begin()+i);
//                 i--;
//                 cout<<s<<endl;
//             }
//         }
//     }
//     if(isPalindrome(s)) cout<<"palindrome"<<endl;
//     else cout<<"not"<<endl;
//     return 0;
// }
//Split Arrays
// #include<iostream>
// #include<vector>
// using namespace std;
// void solve(vector<int> arr,int j,int n,vector<int> left,vector<int> right,int &cnt){
//     if(j==n){
//         int lsum=0;
//         int rsum=0;
//         for(int i=0 ; i<left.size() ; i++){
//             lsum+=left[i];
//         }
//         for(int i=0 ; i<right.size() ; i++){
//             rsum+=right[i];
//         }
//         if(lsum==rsum){
//         for(int i=0 ; i<left.size() ; i++){
//             cout<<left[i]<<" ";
//         }
//         cout<<"and ";
//         for(int i=0 ; i<right.size() ; i++){
//             cout<<right[i]<<" ";
//         }
//         cnt++;
//         cout<<endl;
//     }
//         return;
//     }
//     //include
//     int a=arr[j];
//     left.push_back(a);
//     solve(arr,j+1,n,left,right,cnt);
//     left.pop_back();
//     right.push_back(a);
//     solve(arr,j+1,n,left,right,cnt);
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr;
//     for(int i=0 ; i<n ; i++){
//         int data;
//         cin>>data;
//         arr.push_back(data);
//     }
//     vector<int> left;
//     vector<int> right;
//     int ans=0;
//     solve(arr,0,n,left,right,ans);
//     cout<<ans<<endl;
// }
//To reach nth stair
// #include<iostream>
// using namespace std;
// int solve(int i,int n){
//     if(i>=n-1) return 1;
//     return solve(i+1,n)+solve(i+2,n);
// }
// int main(){
//     cout<<solve(0,3);
//     return 0;
// }
// #include <iostream>
// using namespace std;

// int main()
// {
//     string arr[10], temp;

//     cout << "Enter 10 words: " << endl;
//     for(int i = 0; i < 3; ++i)
//     {
//       getline(cin, arr[i]);
//     }

//     // Use Bubble Sort to arrange words
//     for (int i = 0; i < 2; ++i) {
//         for (int j = 0; j < 2 - i; ++j) {
//             if (arr[j] > arr[j + 1]) {
//                 temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }

//     cout << "In lexicographical order: " << endl;

//     for(int i = 0; i < 3; ++i)
//     {
//        cout << arr[i] << endl;
//     }
//     return 0;
// }
#include<iostream>
using namespace std;
void solve(string in,int i,int n,string out,string track){
    if(i==n){
        cout<<out<<endl;
        return;
    }
    track+=in[i];
    cout<<char(int(in[i])+16)<<endl;
    out+=char(int(in[i])+16);
    solve(in,i+1,n,out,track);
    track.pop_back();
    out+=char(int(in[i])+16);
    solve(in,i+1,n,out,track);
}
int main(){
    string in="123";
    solve(in,0,in.size(),"","");
    return 0;
}