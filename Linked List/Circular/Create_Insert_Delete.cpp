#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next = this;
    }
};

void insertAtHead(Node* &tail, int val){
    Node* temp = new Node(val);
    temp->next = tail->next;
    tail->next = temp;
}

void insertAtTail(Node* &tail, int val){
    Node* temp = new Node(val);
    Node* ptr = tail;
    temp->next = ptr->next;
    tail->next = temp;
    tail = tail->next;
}

void insertAtPos(Node* &tail, int val, int k){
    Node* temp = new Node(val);
    Node* ptr = tail->next;
    int pos=1;
    while(pos<k){
        ptr = ptr->next;
        pos++;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

void printList(Node* &tail){
    Node* ptr = tail;
    ptr = ptr->next;
    while(ptr!=tail){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<ptr->data<<" ";
    cout<<endl;
}

void deleteFromHead(Node* &tail){
    Node* ptr = tail->next;
    tail->next = ptr->next;
    free(ptr);
}

void deleteFromTail(Node* &tail){
    Node* ptr = tail;
    while(ptr->next!=tail){
        ptr = ptr->next;
    }
    ptr->next = tail->next;
    free(tail);
    tail = ptr;
}

void deleteFromPos(Node* &tail, int k){
    Node* ptr = tail->next;
    Node* prev;
    int pos = 1;
    while(pos<k){
        prev = ptr;
        ptr = ptr->next;
        pos++;
    }
    prev->next = ptr->next;
    free(ptr);
}

int main(){
    Node* node = new Node(5);

    // Node* head = node;

    Node* tail = node;

    insertAtHead(tail,10);
    insertAtHead(tail,12);
    insertAtHead(tail,15);
    printList(tail);

    insertAtTail(tail,2);
    insertAtTail(tail,-1);
    printList(tail);

    insertAtPos(tail,7,3);
    printList(tail);

    deleteFromHead(tail);
    printList(tail);

    deleteFromTail(tail);
    printList(tail);

    deleteFromPos(tail,3);
    printList(tail);

}