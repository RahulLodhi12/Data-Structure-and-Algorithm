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

// Approach : Using Stack
void reverse1(queue<int> &Queue, int k)
{
    stack<int> Stack;
    // Step 1: push first k elements into stack from queue
    for(int i=0;i<k;i++){
        Stack.push(Queue.front());
        Queue.pop();
    }
    
    // Step 2: push that k element into queue from stack
    while (Stack.empty()==0)
    {
        Queue.push(Stack.top());
        Stack.pop();
    }

    //step 3: pop n-k elements from front and push at back of queue
    int n = Queue.size();
    for(int i=0;i<n-k;i++){
        int x = Queue.front();
        Queue.pop();
        Queue.push(x);
    }
}


int main()
{
    queue<int> Queue;
    Queue.push(1);
    Queue.push(2);
    Queue.push(3);
    Queue.push(4);
    Queue.push(5);

    reverse1(Queue,3);
    
    
    Print(Queue);
}