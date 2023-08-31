#include<bits/stdc++.h>
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

void createCycle(Node* &head,int a,int b) {
    int cnta = 0,cntb = 0;
    Node* p1 = head;
    Node* p2 = head;
    while(cnta != a || cntb != b) {
        if(cnta != a) p1 = p1->next, ++cnta;
        if(cntb != b) p2 = p2->next, ++cntb;
    }
    p2->next = p1;
}

// Approach 1
bool cycleDetect1(Node* head) {
    unordered_set<Node*> hashTable;
    while(head != NULL) {
        if(hashTable.find(head) != hashTable.end()){
            return true;
        } 
        hashTable.insert(head);
        head = head->next;
    }
    return false;
}

// Approach 2
bool cycleDetect2(Node* head) {
    Node* f = head;
    Node* s = head;
    while(f->next->next!=NULL && f->next!=NULL){
        f = f->next->next;
        s = s->next;
        if(s == f){
            return true;
        }
    }
    return false;
}

int main(){ // Node = Pointer
    Node* node = new Node(4);

    Node* head = node; // pointer

    insertAtHead(head,0);
    insertAtHead(head,2);
    insertAtHead(head,3);

    createCycle(head,1,3);

    // printList(head);

    if(cycleDetect2(head) == true)
    cout<<"Cycle detected\n";
    else
    cout<<"Cycle not detected\n";
    return 0;

}