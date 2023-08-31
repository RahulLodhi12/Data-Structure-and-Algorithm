#include <bits/stdc++.h>
using namespace std;

// Approach 1: T.C: O(1) , S.C: O(N)
class specialStack1
{
    stack<pair<int, int>> st;

public:
    void push(int x)
    {
        if (st.empty() == true)
        {
            int mini = x;
            st.push({x, mini});
        }
        else
        {
            int mini = min(x, st.top().second); // important, used to solve run-time errors
            st.push({x, mini});
        }
        
    }

    void pop()
    {
        if(st.empty()==false){
            st.pop();
        }
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

// Approach 2: T.C: O(1) , S.C: O(1)
class specialStack2
{
    stack<int> st;

public:
    int mini = INT_MAX;
    void push(int x)
    {
        int curr = x;
        if (st.empty() == true) // for first element
        {
            st.push(curr);
            mini = min(curr,mini);
        }
        else // for other elements
        {
            if (curr < mini)
            {
                int val = 2 * curr - mini;
                mini = curr;
                st.push(val);
            }
            else
            {
                st.push(curr);
            }
        }
    }

    void pop()
    {
        int curr = st.top();
        if (curr < mini)
        {
            int val = 2 * mini - curr;
            mini = val;
            st.pop();
        }
        else
        {
            st.pop();
        }
    }

    int top(){
        if(st.empty()==true){
            return -1;
        }
        else{
            int curr = st.top();
            if(curr<mini){
                return mini;
            }
            else{
                return curr;
            }
        }
    }

    int getMin()
    {
        return mini;
    }

    bool isEmpty(){
        return st.empty();
    }
};

int main()
{

    specialStack2 obj;

    obj.push(13);
    obj.push(47);
    // obj.push(-3);
    // cout << obj.getMin() << endl;
    obj.pop();
    cout<<obj.top()<<endl;


}