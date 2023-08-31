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

void reverseLL(Node* &head){
    Node* ptr = head;
    Node* prev = NULL;
    Node* temp = NULL; // to store ptr->next
    while(ptr!=NULL){
        temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    // head->next = NULL;
    head = prev;
}

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

    reverseLL(head);
    printList(head);


}