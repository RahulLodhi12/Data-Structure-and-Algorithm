#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

class Stack{
    public:
        Node* top; // head of LL

    Stack(){
        top = NULL;
    }

    void push(int x){ // similar to insertAtHead
        Node* temp = new Node(x);// create temp node(object) and allocate memory in heap
        if(temp==NULL){// if heap is full, temp will not create
            cout<<"Stack Overflow"<<endl;
        }

        temp->data = x;
        temp->next = top;

        top = temp;
    }

    void pop(){ // similar to deleteFromHead
        if(top==NULL){
            cout<<"Stack Underflow"<<endl;
        }

        Node* ptr = top;
        top = top->next;
        free(ptr);
    }

    int peek(){
        if(top==NULL){
            return -1;
        }
        return top->data;
    }

    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        return false;
    }
};

int main(){

    Stack st;
    st.push(5);
    st.push(7);
    st.push(9);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    cout<<st.isEmpty()<<endl;
}