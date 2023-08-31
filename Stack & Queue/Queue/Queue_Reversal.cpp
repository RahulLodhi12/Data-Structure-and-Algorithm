#include <bits/stdc++.h>
using namespace std;

void Print(queue<int> &Queue)
{
    while (!Queue.empty())
    {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

// Approach 1: Using Stack
void reverse1(queue<int> &Queue)
{
    stack<int> Stack;
    // Step 1: push into stack from queue
    while (!Queue.empty())
    {
        Stack.push(Queue.front());
        Queue.pop();
    }
    
    // Step 2: push into queue from stack
    while (!Stack.empty())
    {
        Queue.push(Stack.top());
        Stack.pop();
    }
}


// Approach 2: Using Recursion
void reverse2(queue<int>& q){
    //base case
    if(q.empty()){
        return;
    }

    //recursive case
    int x = q.front();
    q.pop();

    reverse2(q);

    q.push(x);
}

int main()
{
    queue<int> Queue;
    Queue.push(10);
    Queue.push(20);
    Queue.push(30);
    Queue.push(40);
    Queue.push(50);
    Queue.push(60);
    Queue.push(70);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);

    // reverse1(Queue);
    
    reverse2(Queue);
    
    Print(Queue);
}