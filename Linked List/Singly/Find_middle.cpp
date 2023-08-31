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

void findMiddleApp1(Node* head){  // approach 1
    Node* ptr = head;
    int count = 0;
    while(ptr!=NULL){
        ptr = ptr->next;
        count++;
    }
    // cout<<count<<endl;

    int middle = count/2; // 2

    Node* temp = head;
    while(middle--){
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}
// T.C -> O(N): 2 traversal , S.C -> O(1)

void findMiddleApp2(Node* head){  // approach 2
    Node* slow_ptr = head;
    Node* fast_ptr = head;

    while(fast_ptr!=NULL && fast_ptr->next!=NULL){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    cout<<slow_ptr->data<<endl;
}
// T.C -> O(N): single traversal , S.C -> O(1)

int main(){
    Node* node = new Node(5); // node is name of object, new node is created.
    // cout<<node->data<<endl;

    Node* head = node; // pointer

    insertAtHead(head,10);
    insertAtHead(head,12);
    insertAtHead(head,15);
    insertAtHead(head,20);
    insertAtHead(head,21);
    
    printList(head);

    findMiddleApp1(head);

    findMiddleApp2(head);    


}