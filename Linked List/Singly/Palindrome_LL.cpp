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

// Approach 1
bool isPalindrome1(Node* &head){
    vector<int> arr;
    while(head!=NULL){
        arr.push_back(head->data);
        head = head->next;
    }
    int n = arr.size();
    for(int i=0;i<n/2;i++){
        if(arr[i] != arr[n-i-1]){
            return false;
        }
    }
    return true;
}
// T.C : O(N) , S.C : O(N)


// Approach 2
bool isPalindrome2(Node* &head){
    Node* s = head;
    Node* f = head;
    //middle : s
    while(f->next!=NULL && f->next->next!=NULL){
        s = s->next;
        f = f->next->next;
    }
    //reverse
    Node* ptr = s->next;
    Node* prev = NULL;
    Node* temp = NULL; // store ptr->next
    while(ptr!=NULL){
        temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    s->next = prev;
    s = s->next;

    //check for palindrome
    Node* d = head;
    while(s!=NULL){
        if(d->data != s->data){
            return false;
        }
        d = d->next;
        s = s->next;
    }
    return true;
}

int main()
{ // Node = Pointer
    Node *node = new Node(1);

    Node *head = node; // pointer

    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    cout<<isPalindrome2(head)<<endl;
}