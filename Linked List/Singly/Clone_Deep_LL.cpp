#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* random;
        Node(int val) {
            data = val;
            next = NULL;
            random = NULL;
        }
};

void printList(Node* head) {
    while(head != NULL) {
        cout<<head->data<<':';
        head->next != NULL ? cout<<head->next->data:cout<<"NULL";
        head->random != NULL ? cout<<","<<head->random->data:cout<<",NULL";
        cout<<endl;
        head = head->next;
    }
}

Node* deepCopyLL(Node* head){
    unordered_map<Node*, Node*> hashMap;
    Node* temp = head;
    while(temp!=NULL){
        Node* newNode = new Node(temp->data);
        hashMap[temp] = newNode;
        temp = temp->next; 
    }

    Node* t = head;
    while(t!=NULL){
        Node* ptr = hashMap[t]; //pointer
        ptr->next = hashMap[t->next];
        ptr->random = hashMap[t->random];
        t = t->next;
    }
    return hashMap[head];
}
// T.C : O(2*N) , S.C : O(N)


Node* deepCopyLL2(Node* &head){
    // step 1
    Node* p = head;
    Node* t;
    while(p!=NULL){
        Node* temp = new Node(p->data);
        t = p->next;
        p->next = temp;
        temp->next = t;
        p = t;
    }
    
    // step 2
    Node* itr = head;
    while(itr!=NULL){
        if(itr->random != NULL)
            itr->next->random = itr->random->next;
        itr = itr->next->next;
    }

    // step 3
    Node* d = new Node(-1);
    Node* pt = head;
    Node* fast;
    Node* tp = d;
    while(pt!=NULL){
        fast = pt->next->next;
        tp->next = pt->next;
        pt->next = fast;
        tp = tp->next;
        pt = fast;
    }
    return d->next;
}
// T.C : O(N) , S.C : O(1)

int main() {
    Node* head = NULL;
    
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    head = node1;
    head->next = node2;
    head->next->next = node3;
    head->next->next->next = node4;
    
    head->random = node4;
    head->next->random = node1;
    head->next->next->random = NULL;
    head->next->next->next->random = node2;
    
    cout<<"Original list:(current node:node pointed by next pointer,node pointed by random pointer)"<<endl;
    printList(head);
    
    cout<<"Copy list:(current node:node pointed by next pointer,node pointed by random pointer)"<<endl;
    Node* newHead = deepCopyLL2(head);
    printList(newHead);
    return 0;
}