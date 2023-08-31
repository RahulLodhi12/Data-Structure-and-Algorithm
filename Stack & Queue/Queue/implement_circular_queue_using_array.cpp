#include <bits/stdc++.h> 
using namespace std;

class CircularQueue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool enqueue(int value){ //push
        if((front==0 && rear==size-1) || (rear==(front-1)%(size-1))){ // check queue is full
            // cout<<"Queue is full"<<endl;
            return false;
        }
        else if(front == -1 ){ // for first element to push(single element)
            front = 0;
            rear = 0;
            arr[rear] = value;
        }
        else if(rear==size-1 && front!=0){ // to maintain circular queue
            rear = 0;
            arr[rear] = value;
        }
        else{ // normal flow
            rear++;
            arr[rear] = value;
        }
        return true;
    }

    int dequeue(){ //pop
        if(front==-1){ // check queue is empty
            // cout<<"Queue is empty"<<endl;
            return -1;
        }
        else if(front == rear){ // for the first element to pop(single element)
            int popE = arr[front];
            arr[front] = -1;
            front = -1;
            rear = -1;
            return popE;
        }
        else if(front == size-1){ // to maintain cicular queue
            int popE = arr[front];
            arr[front] = -1;
            front = 0;
            return popE;
        }
        else{ // normal flow
            int popE = arr[front];
            arr[front] = -1;
            front++;
            return popE;
        }
    }
};

int main(){
    CircularQueue q(10);
    cout<<q.enqueue(13)<<endl;
    cout<<q.enqueue(33)<<endl;
    cout<<q.enqueue(53)<<endl;
    cout<<q.enqueue(73)<<endl;

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
}