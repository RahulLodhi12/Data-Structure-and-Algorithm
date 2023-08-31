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

int lengthLL(Node* &head){
    Node* ptr = head;
    int length=0;
    while(ptr!=NULL){
        ptr = ptr->next;
        length++;
    }
    return length;
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
Node* cycleDetect1(Node* head) {
    bool flag;
    unordered_set<Node*> hashTable;
    while(head != NULL) {
        if(hashTable.find(head) != hashTable.end()){
            return head;
        }
        hashTable.insert(head);
        head = head->next;
    }
    return NULL;
}
// T.C : O(N) , S.C : O(N)


// Approach 2
Node* cycleDetect2(Node* head) {
    Node* f = head;
    Node* s = head;
    Node* e = head;
    while(f->next->next!=NULL && f->next!=NULL){
        f = f->next->next;
        s = s->next;
        if(s == f){
            while(s!=e){
                s = s->next;
                e = e->next;
            }
            return e;
        }
    }
    return NULL;
}
// T.C : O(N) , S.C : O(1)

int main(){ // Node = Pointer
    Node* node = new Node(10);

    Node* head = node; // pointer

    insertAtHead(head,6);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);

    createCycle(head,3,6);

    // Approach 1
    // Node* ptr1 = head;
    // int pos1=0;
    // // Node* newNode1 = cycleDetect1(head);
    // if(newNode1 == NULL){
    //     cout<<"No cycle"<<endl;
    // }
    // else{
    //     while(ptr1!=newNode1){
    //         ptr1 = ptr1->next;
    //         pos1++;
    //     }
    //     cout<<"tail connects to node index "<<pos1<<endl;
    // }

    // Approach 2
    Node* ptr2 = head;
    int pos2 = 0;
    Node* newNode2 = cycleDetect2(head);
    if(newNode2 == NULL){
        cout<<"No cycle"<<endl;
    }
    else{
        while(ptr2!=newNode2){
            ptr2 = ptr2->next;
            pos2++;
        }
        cout<<"tail connects to node index "<<pos2<<endl;
    }

}