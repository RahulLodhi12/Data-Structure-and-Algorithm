#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int>& st){
    //base case
    if(st.empty() == 1){
        return;
    }

    int n = st.top();
    st.pop();
    printStack(st);
    cout<<n<<endl;
    st.push(n);
}

void insertAtBottom(stack<int>& st, int x){
    //base case
    if(st.empty()==1){
        st.push(x);
        return;
    }

    int n = st.top();
    st.pop();
    insertAtBottom(st,x);;
    st.push(n);
}

void reverse(stack<int>& st){
    //base case
    if(st.empty()==1){
        return;
    }

    int x = st.top(); // select element to insertAtBottom
    st.pop();

    reverse(st);

    insertAtBottom(st,x);
}

int main(){
    stack<int> st;

    st.push(5);
    st.push(7);
    st.push(9);
    st.push(17);
    st.push(21);

    cout<<"Before insert: "<<endl;
    printStack(st);

    reverse(st);

    cout<<"After insert: "<<endl;
    printStack(st);
}