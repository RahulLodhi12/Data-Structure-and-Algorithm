#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(Node* &head, int val){
    Node* temp = new Node(val);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtEnd(Node* &head, int val){
    Node* temp = new Node(val);
    Node* ptr = head;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
}

void insertAtPos(Node* &head, int val, int k){ // insertAfterNode(head->next, 8);
    Node* temp = new Node(val);
    Node* ptr = head;
    Node* Prev;
    int pos = 1;
    while(pos<k){
        Prev = ptr;
        ptr = ptr->next;
        pos++;
    }
    Prev->next = temp;
    temp->prev = Prev;
    ptr->prev = temp;
    temp->next = ptr;
}

void printList(Node* &head){
    Node* ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
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
    Node* Prev;
    while(ptr->next!=NULL){
        Prev = ptr;
        ptr = ptr->next;
    }
    Prev->next = NULL;
    free(ptr);
}

void deleteFromPos(Node* &head, int k){
    Node* ptr = head;
    Node* Prev;
    int pos=1;
    while(pos<k){
        Prev = ptr;
        ptr = ptr->next;
        pos++;
    }
    Prev->next = ptr->next;
    ptr->next->prev = Prev;
}

bool searchNode(Node* &head, int key){
    Node* ptr = head;
    while(ptr!=NULL){
        if(ptr->data == key){
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

int main(){
    Node* node = new Node(5);
    Node* head = node;

    insertAtHead(head,10);
    insertAtHead(head,12);
    insertAtHead(head,15);
    insertAtEnd(head,3);
    insertAtEnd(head,-1);
    printList(head);

    insertAtPos(head,7,3);
    printList(head);

    deleteFromHead(head);
    printList(head);

    deleteFromEnd(head);
    printList(head);

    deleteFromPos(head,3);
    printList(head);

    cout<<searchNode(head,10)<<endl;
}