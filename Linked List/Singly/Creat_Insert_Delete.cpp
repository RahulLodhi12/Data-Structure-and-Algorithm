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


void insertAtEnd(Node* &head, int val){
    Node* temp = new Node(val);
    Node* ptr = head;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}
// T.C - O(N) , S.C - O(1)

void insertAtpos(Node* &head, int val, int k){ // insertAfterNode(head->next, 8);
    Node* temp = new Node(val);
    Node* ptr = head;
    int pos=1;
    while(pos<k-1){
        ptr = ptr->next;
        pos++;
    }
    temp->next = ptr->next; // step 1 (ullta)
    ptr->next = temp;       // step 2
}

void printList(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void deleteFromHead(Node* &head){
    Node* ptr = head;
    head = ptr->next;
    free(ptr);
}

void deleteFromEnd(Node* &head){
    Node* ptr = head;
    Node* prev;
    while(ptr->next!=NULL){
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    free(ptr);
}

void deleteFromPos(Node* &head, int k){
    Node* ptr = head;
    Node* prev;
    int pos=1;
    while(pos<k){
        prev = ptr;
        ptr = ptr->next;
        pos++;
    }
    prev->next = ptr->next;
    free(ptr);
}

bool searchNode(Node* &head, int key){ // Iterative approach
    Node* ptr = head;
    while(ptr!=NULL){
        if(ptr->data == key){
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

int main(){ // Node = Pointer
    Node* node = new Node(5); // node is name of object, new node is created.
    // cout<<node->data<<endl;

    Node* head = node; // pointer

    insertAtHead(head,10);
    insertAtHead(head,12);
    insertAtHead(head,15);
    insertAtHead(head,20);
    insertAtEnd(head,7);
    printList(head);

    insertAtpos(head,11,4);
    printList(head);

    deleteFromHead(head);
    printList(head);

    deleteFromEnd(head);
    printList(head);

    deleteFromPos(head,3);
    printList(head);

    cout<<searchNode(head,11)<<endl;
}