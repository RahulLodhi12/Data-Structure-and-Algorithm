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

// Approach 1
Node* intersectionPresent1(Node *&head1, Node *&head2)
{
    Node *p1 = NULL;
    Node *p2 = head2;
    while (p2 != NULL) // keep
    {
        p1 = head1;
        while (p1 != NULL) // check
        {
            if (p1 == p2)
            {
                return p1;
            }
            p1 = p1->next;
        }
        p2 = p2->next;
    }
    return NULL;
}
// Time Complexity: O(m*n) Reason: For each node in list 2 entire lists 1 are iterated. 
// Space Complexity: O(1) Reason: No extra space is used.


// Approach 2
Node* intersectionPresent2(Node *&head1, Node *&head2)
{
    unordered_set<Node*> st;
    while(head1!=NULL){
        st.insert(head1);
        head1 = head1->next;
    }
    while(head2!=NULL){
        if(st.find(head2) != st.end()){
            return head2;
        }
        head2 = head2->next;
    }
    return NULL;
}


// Approach 3
Node* intersectionPresent3(Node* &head1, Node* &head2){
    Node* d1 = head1;
    Node* d2 = head2;
    while(d1!=d2){
        // correct method
        d1 = d1 == NULL? head2:d1->next;
        d2 = d2 == NULL? head1:d2->next;
    }
    return d1;
}

int main()
{
    Node *head1 = NULL; // pointer

    insertAtEnd(head1, 1);
    insertAtEnd(head1, 3);
    insertAtEnd(head1, 1);
    insertAtEnd(head1, 2);
    insertAtEnd(head1, 4);
    printList(head1);

    head1 = head1->next->next->next;
    Node *head2 = NULL;
    insertAtEnd(head2, 3);
    head2->next = head1;
    printList(head2);

    Node* ansNode = intersectionPresent3(head1, head2);
    if(ansNode == NULL){
        cout<<"No intersection"<<endl;
    }
    else{
        cout<<"The intersection at "<<ansNode->data<<endl;
    }
}