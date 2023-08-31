#include <bits/stdc++.h> 
class Deque
{
public:
    // Initialize your data structure.
    int size;
    int *arr;
    int front;
    int rear;

    Deque(int n)
    {
        // Write your code here.
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if(isFull()){ //check queue is full
            return false;
        }
        else if(front==-1){ // for single element
            front = 0;
            rear = 0;
            arr[front] = x;
            return true;
        }
        else if(front==0){
            front = size-1;
            arr[front] = x;
        }
        else{
            front--;
            arr[front] = x;
        }
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x) // push of circular queue
    {
        // Write your code here.
        if(isFull()){ //check queue is full
            return false;
        }
        else if(front==-1){ // for single element
            front = 0;
            rear = 0;
            arr[rear] = x; 
        }
        else if(rear == size-1){
            rear = 0;
            arr[rear] = x;
        }
        else{
            rear++;
            arr[rear] = x;
        }
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront() // pop of circular queue
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        else if(front == rear){ //for single element
            int popE = arr[front];
            arr[front] = -1; 
            front = -1;
            rear = -1;
            return popE;
        }
        else if(front == size-1){
            int popE = arr[front];
            arr[front] = -1;
            front = 0;
            return popE;
        }
        else{
            int popE = arr[front];
            arr[front] = -1;
            front++;
            return popE;
        }
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        else if(front == rear){ //for single element
            int popE = arr[rear];
            arr[rear] = -1; 
            front = -1;
            rear = -1;
            return popE;
        }
        else if(rear == 0){
            int popE = arr[rear];
            arr[rear] = -1;
            rear = size-1;
            return popE;
        }
        else{
            int popE = arr[rear];
            arr[rear] = -1;
            rear--;
            return popE;
        }
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front == -1){
            return true;
        }
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if((front == 0 && rear == size-1) || (front!=0 && rear==(front-1)%(size-1))){
            return true;
        }
        return false;
    }
};