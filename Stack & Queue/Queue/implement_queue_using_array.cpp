#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
        int size;
        int *arr;
        int front;
        int rear;

    Queue(int s){
        this->size = s;
        this->arr = new int[s];
        this->front = 0;
        this->rear = 0;
    }

    void push(int x){ //enqueue
        if(rear == size){
            cout<<"Stack Overflow"<<endl;
        }
        arr[rear] = x;
        rear++;
    }

    int pop(){ //dequeue
        if(front==rear){
            return -1; // Stack Underflow
        }
        int popE = arr[front];
        arr[front] = -1; // like it is poped by assign -1.
        front++;
        if(front==rear){ // to avoid the wastage of space in array.
            front=0;
            rear=0;
        }
        return popE;
    }

    bool isEmpty(){
        if(front==rear){
            return true;
        }
        return false;
    }

    int Head(){ // Front()
        if(front==rear){
            return -1;
        }
        return arr[front];
    }
};

int main(){

    Queue q(6);
    q.push(1);
    q.push(5);
    q.push(7);
    q.push(8);
    q.push(12);

    cout<<"Front: "<<q.Head()<<endl;

    cout<<"PopE: "<<q.pop()<<endl;
    cout<<"PopE: "<<q.pop()<<endl;

    cout<<"Front: "<<q.Head()<<endl;
}
