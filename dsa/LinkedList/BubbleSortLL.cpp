#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

void insertAtTail(Node*& tail, int data) {
    if (tail == nullptr) {
        tail = new Node(data);
    } else {
        tail->next = new Node(data);
        tail = tail->next;
    }
}

int length(Node* head) {
    Node* temp = head;
    int cnt = 0;
    while (temp != nullptr) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

Node* sortList(Node* head) {
    int n = length(head);
    if (n <= 1) {
        return head; // No need to sort a list with 0 or 1 elements.
    }

    for (int i = 0; i < n - 1; i++) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* agla = head->next;
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (curr->data > agla->data) {
                // Swap curr and agla data
                swapped = true;
                Node* temp = agla->next;
                agla->next = curr;
                curr->next = temp;

                if (prev != nullptr) {
                    prev->next = agla;
                } else {
                    head = agla; // Update head if agla is the new head
                }

                prev = agla;
                agla = temp;
            } else {
                prev = curr;
                curr = agla;
                agla = agla->next;
            }
        }

        // If no swapping happened in this pass, the list is already sorted
        if (!swapped) {
            break;
        }
    }

    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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
    printList(l1Head->next);

    Node* sortedList = sortList(l1Head->next);

    cout << "Sorted List: ";
    printList(sortedList);

    return 0;
}
