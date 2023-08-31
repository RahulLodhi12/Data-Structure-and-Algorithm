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

void insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val); // create new node
    temp->next = head;
    head = temp;
}
// T.C - O(1) , S.C -O(1)

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
    cout<<count<<endl;
    return count;
}

void reverseKnodes(Node *&head, int k)
{
    int length = lengthLL(head);
    Node *d = new Node(-1);
    d->next = head;
    Node *pre = d;
    Node *curr;
    Node *nex;
    while (length >= k)
    {
        curr = pre->next;
        nex = curr->next;
        for (int i = 1; i < k; i++){ // since k-1 links are interchanged.
            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next;
        }
        length = length - k;
        pre = curr;
    }
    Node* newHead = d->next;
    printList(newHead);
}

int main()
{ // Node = Pointer
    Node *node = new Node(8);

    Node *head = node; // pointer

    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    reverseKnodes(head, 3);

    // printList(head);
}