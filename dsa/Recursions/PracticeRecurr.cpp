//Check for a string is palindrome or not
// #include<iostream>
// using namespace std;
// bool isPalindrome(string input){
//     if(input.length()==0 || input.length()==1) return true;
//     if(input[0]==input[input.length()-1]){
//         cout<<input<<endl;;
//         return isPalindrome(input.substr(1,input.length()-2));
//     }
//     return false;
// }
// int main(){
//     cout<<isPalindrome("racecar");
//     return 0;
// }
//Converting decimal into binary 
// #include<iostream>
// using namespace std;
// string solve(int n,string ans){
//     if(n==0) return ans;
//     return solve(n/2,ans)+=(n%2+48);
// }
// int main(){
//     string ans="";
//     cout<<solve(233,ans);
//     return 0;
// }
//Sum of all natural numbers
// #include<iostream>
// using namespace std;
// int solve(int n){
//     if(n<=1) return n;
//     // cout<<n<<endl;
//     return solve(n-1)+n;
// }
// int main(){
//     cout<<solve(10)<<endl;
//     return 0;
// }
//Binary Search Using Recursion
// #include<iostream>
// using namespace std;
// int binarySearch(int arr[],int target,int start,int end){
//     if(start>end) return -1;
//     int mid=(start+end)/2;
//     if(arr[mid]==target) return mid;
//     if(arr[mid]<target) return binarySearch(arr,target,mid+1,end);
//     else return binarySearch(arr,target,start,mid-1);
// }
// int main(){
//     int arr[]={12,14,18,23,25,34,67,89};
//     cout<<binarySearch(arr,18,0,7);
//     return 0;
// }
//Fibbonacci
// #include<iostream>
// using namespace std;
// int fibb(int n){
//     if(n==1 || n==0) return 1;
//     return fibb(n-1)+fibb(n-2);
// }
// int main(){
//     cout<<fibb(6)<<endl;
//     return 0;
// }
//Merge Sort
// #include<iostream>
// using namespace std;
// void merge(int arr[],int start,int mid,int end){
//     int out[end-start+1];
//     int i=start,j=mid+1;
//     int k=0;
//     while(i<=mid && j<=end){
//         if(arr[i]<=arr[j]){
//             out[k++]=arr[i++];
//         }
//         else{
//             out[k++]=arr[j++];
//         }
//     }
//     while(i<=mid){
//         out[k++]=arr[i++];
//     }
//     while(j<=end){
//         out[k++]=arr[j++];
//     }
//     for(int i=start ; i<=end ; i++){
//         arr[i]=out[i-start];
//     }
// }
// void mergeSort(int arr[],int start,int end){
//      if(start<end) {
//         int mid = (start + end) / 2;
//         mergeSort(arr, start, mid);
//         mergeSort(arr, mid + 1, end);
//         merge(arr, start, mid, end);
//     }
// }
// int main(){
//     int arr[]={-5,20,10,3,2,0,8};
//     mergeSort(arr,0,6);
//     for(int i=0 ; i<7 ; i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }
//LinkedListReversal
// #include<iostream>
// using namespace std;
// class Node{
// public:
//     int data;
//     Node *next;
//     Node(int data){
//         this->data=data;
//         this->next=nullptr;
//     }
// };
// Node* reverseList(Node* head){
//     if(head==NULL || head->next==NULL) return head;
//     Node* p=reverseList(head->next);
//     head->next->next=head;
//     head->next=nullptr;
//     return p;
// }
// void insertionAtTail(Node* &tail,int data){
//     Node* temp=new Node(data);
//     if(tail==NULL) {
//         tail=temp;
//     }
//     else{
//         tail->next=temp;
//         tail=temp;
//     }
// }
// void print(Node* head){
//     while(head){
//         cout<<head->data<<" ";
//         head=head->next;
//     }
//     cout<<endl;
// }
// int main(){
//     Node* head=new Node(1);
//     Node* tail=head;
//     insertionAtTail(tail,2);
//     insertionAtTail(tail,3);
//     insertionAtTail(tail,4);
//     insertionAtTail(tail,5);
//     insertionAtTail(tail,6);
//     print(head);
//     head=reverseList(head);
//     print(head);
//     return 0; 
// }
//Merge Sorted Linked Lists
// #include<iostream>
// using namespace std;
// class Node{
// public:
//     int data;
//     Node *next;
//     Node(int data){
//         this->data=data;
//         this->next=nullptr;
//     }
// };
// Node* SortedMerge(Node* A,Node* B){
//     if(A==nullptr) return B;
//     if(B==nullptr) return A;
//     if(A->data < B->data){
//         A->next=SortedMerge(A->next,B);
//         return A;
//     }
//     else{
//         B->next=SortedMerge(A,B->next);
//         return B;
//     }
// }
// void insertionAtTail(Node* &tail,int data){
//     Node* temp=new Node(data);
//     if(tail==NULL) {
//         tail=temp;
//     }
//     else{
//         tail->next=temp;
//         tail=temp;
//     }
// }
// void print(Node* head){
//     while(head){
//         cout<<head->data<<" ";
//         head=head->next;
//     }
//     cout<<endl;
// }
// int main(){
//     Node* A=new Node(1);
//     Node* tailA=A;
//     insertionAtTail(tailA,8);
//     insertionAtTail(tailA,22);
//     insertionAtTail(tailA,40);
//     Node* B=new Node(4);
//     Node* tailB=B;
//     insertionAtTail(tailA,11);
//     insertionAtTail(tailA,16);
//     insertionAtTail(tailA,20);
//     Node* ans=SortedMerge(A,B);
//     print(ans);
//     return 0;
// }
//Insert Value Into Binary Search Tree
// #include<iostream>
// #include<queue>
// using namespace std;
// class Node{
// public:
//     int data;
//     Node* left;
//     Node* right;
//     Node(int data){
//         this->data=data;
//         this->left=nullptr;
//         this->right=nullptr;
//     }
// };
// void levelOrderTraversal(Node* root) {
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);

//     while(!q.empty()) {
//         Node* temp = q.front();
//         q.pop();

//         if(temp == NULL) { 
//             //purana level complete traverse ho chuka hai
//             cout << endl;
//             if(!q.empty()) { 
//                 //queue still has some child ndoes
//                 q.push(NULL);
//             }  
//         }
//         else{
//             cout << temp -> data << " ";
//             if(temp ->left) {
//                 q.push(temp ->left);
//             }

//             if(temp ->right) {
//                 q.push(temp ->right);
//             }
//         }
//     }

// }
// Node* insertNode(Node* head,int data){
//     if(head==nullptr){
//         head=new Node(data);
//         return head;
//     }
//     if(head->data<data){
//         head->right=insertNode(head->right,data);
//     }else{
//         head->left=insertNode(head->left,data);
//     }
//     return head;
// }
// void printLeafNodes(Node* head){
//     if(head==nullptr) return;
//     if(head->left==nullptr && head->right==nullptr){
//         cout<<head->data<<",";
//         return;
//     }
//     if(head->left!=nullptr) printLeafNodes(head->left);
//     if(head->right!=nullptr) printLeafNodes(head->right);
// }
// int main(){
//     Node* tree=new Node(100);
//     insertNode(tree,120);
//     insertNode(tree,110);
//     insertNode(tree,115);
//     insertNode(tree,80);
//     insertNode(tree,108);
//     levelOrderTraversal(tree);
//     printLeafNodes(tree);
//     return 0;
// }
//Depth-First Search
