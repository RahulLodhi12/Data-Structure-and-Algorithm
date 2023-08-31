#include <iostream>
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
{                               // If you pass Node* head instead of Node* &head, and if "head" is changed, the change will not be available in the main function
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

// Approach 1
void merge1(Node *&head1, Node *&head2)
{
    Node *p1 = head1;
    Node *p2 = head2;

    Node *dummy = new Node(-1);
    Node *p3 = dummy;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data <= p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else if (p2->data <= p1->data)
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    Node *newhead = dummy->next;
    printList(newhead);
}
// Time Complexity: O(N+M).
// Let N be the number of nodes in list l1 and M be the number of nodes in list l2.
// We have to iterate through both lists. So, the total time complexity is O(N+M).

// Space Complexity: O(N+M).
// We are creating another linked list that contains the (N+M) number of nodes in the list.
// So, space complexity is O(N+M).

// Approach 2
void merge2(Node *&head1, Node *&head2)
{
    Node *l1 = head1;
    Node *l2 = head2;
    if (l1->data >= l2->data)
    {
        swap(l1, l2);
    }

    Node *res = l1;

    Node *temp;
    while (l2 != NULL) // for swapping l1 & l2.
    {
        temp = NULL;
        while (l1 != NULL && l1->data <= l2->data) // for iteration of l1.
        {
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        swap(l1, l2);
    }

    printList(res);
}
// T.C - O(N+M) , S.C - O(1)

int main()
{
    Node *node1 = new Node(9); // node is name of object, new node is created.
    Node *node2 = new Node(10);

    Node *head1 = node1; // pointer
    Node *head2 = node2;

    insertAtHead(head1,7);
    insertAtHead(head1,5);
    

    insertAtHead(head2,8);
    insertAtHead(head2,4);
    insertAtHead(head2,3);

    printList(head1);
    printList(head2);

    // merge1(head1, head2);

    merge2(head1, head2);
}