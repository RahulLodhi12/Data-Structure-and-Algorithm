#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int> st){
    //base case
    if(st.empty()==1){
        return;
    }

    int x = st.top();
    st.pop();
    printStack(st); // recursive call
    cout<<x<<endl;
    st.push(x);
}

void deleteMiddle(stack<int> &st, int cnt, int size){
    //base case
    if(cnt == size/2){
        st.pop();
        return;
    }

    int x = st.top();
    st.pop();
    deleteMiddle(st,cnt+1,size);
    st.push(x);
}

int main(){
    stack<int> st;

    st.push(5);
    st.push(7);
    st.push(8);
    st.push(12);
    st.push(15);

    cout<<"Before Deleting middle element from stack: "<<endl;
    printStack(st); // using recursion
    cout<<"Size before deleting: "<<st.size()<<endl;

    int cnt=0;
    int n = st.size();
    deleteMiddle(st, cnt, n);

    cout<<"After Deleting middle element from stack: "<<endl;
    printStack(st);
    cout<<"Size after deleting: "<<st.size()<<endl;
}