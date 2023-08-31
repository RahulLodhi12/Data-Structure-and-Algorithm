#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    { // constructor
        this->data = val;
        this->next = NULL;
    }
};

void insertAtEnd(Node *&head, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}
// T.C - O(N) , S.C - O(1)

void printList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int lengthLL(Node *&head)
{
    Node *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}

// Approach 1
void rotateLL1(Node* &head, int k){
    for(int i=0;i<k;i++){
        Node* ptr = head;
        Node* prev = NULL;
        while(ptr->next!=NULL){
            prev = ptr;
            ptr = ptr->next;
        }
        ptr->next = head;
        prev->next = NULL;
        head = ptr;
    }
}
// T.C : O(K*N) , S.C : O(1) 


// Approach 2
void rotateLL2(Node* &head, int k){
    int length = lengthLL(head);
    k = k % length;
    int nl = length - k;
    Node* p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = head;

    Node* ptr = head;
    Node* prev; 
    for(int i=1;i<=nl;i++){
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    head = ptr;
}
// T.C : O(N) + O(N - K) , S.C : O(1)


int main(){ // Node = Pointer
    Node* node = new Node(1); // node is name of object, new node is created.
    // cout<<node->data<<endl;

    Node* head = node; // pointer

    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    // insertAtEnd(head,7);
    printList(head);

    rotateLL2(head,2);
    printList(head);

}