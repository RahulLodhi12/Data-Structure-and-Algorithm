#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int val){  // constructor
        this->data = val;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int val){ // If you pass Node* head instead of Node* &head, and if "head" is changed, the change will not be available in the main function
    Node* temp = new Node(val); // create new node
    temp->next = head;
    head = temp;
}
// T.C - O(1) , S.C -O(1)

void printList(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Approach 1
void removeFromEnd1(Node* &head, int n){
    Node* temp = head;
    int length = 1;
    while(temp!=NULL){
        temp = temp->next;
        length++;
    }

    Node* ptr = head;
    Node* prev;
    int pos=1;
    int k = length - n; // formula
    while(pos<k){
        prev = ptr;
        ptr = ptr->next;
        pos++;
    }
    prev->next = ptr->next;
    ptr->next = NULL;
    free(ptr);
}
// T.C - O(2N) , S.C - O(1)


// Approach 2 - Two pointer
void removeFromEnd2(Node* &head, int n){
    Node* temp = new Node(-1); // dummy node
    temp->next = head;

    Node* fast_ptr = temp;
    Node* slow_ptr = temp;
    for(int i=1;i<=n;i++){
        fast_ptr = fast_ptr->next;
    }
    while(fast_ptr->next!=NULL){
        fast_ptr = fast_ptr->next;
        slow_ptr = slow_ptr->next;
    }
    slow_ptr->next = slow_ptr->next->next;
    head = temp->next;
}
// T.C - O(N) , S.C - O(1)

int main(){
    Node* node = new Node(5); // node is name of object, new node is created.
    // cout<<node->data<<endl;

    Node* head = node; // pointer

    insertAtHead(head,10);
    insertAtHead(head,12);
    insertAtHead(head,15);
    insertAtHead(head,20);
    // insertAtEnd(head,7);
    printList(head);

    // removeFromEnd1(head,2);
    // printList(head);

    removeFromEnd2(head,5);
    printList(head);


}