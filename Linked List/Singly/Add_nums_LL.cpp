#include <iostream>
#include <math.h>
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

// Only Approach - optimal
void addNums(Node *&head1, Node *&head2)
{
    Node *l1 = head1;
    Node *l2 = head2;

    Node *d = new Node(-1);
    Node *temp = d;

    int carry = 0;  // carry -> carry hoti hai.
    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum = sum + l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum = sum + l2->data;
            l2 = l2->next;
        }
        if(carry){
            sum = sum + carry;
            carry--;
        }
        carry = sum / 10;
        Node *n = new Node(sum % 10);
        temp->next = n;
        temp = n;
    }
    printList(d->next);
}
// T.C - O(max(N,M)) , S.C - O(max(N,M))

int main()
{
    Node *node1 = new Node(3); // node is name of object, new node is created.
    Node *node2 = new Node(9);

    Node *head1 = node1; // pointer
    Node *head2 = node2;

    insertAtHead(head1, 4);
    insertAtHead(head1, 2);

    insertAtHead(head2, 7);
    insertAtHead(head2, 6);
    insertAtHead(head2, 5);

    printList(head1);
    printList(head2);

    addNums(head1, head2);
}