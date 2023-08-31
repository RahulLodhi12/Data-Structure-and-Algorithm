#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int>& st){ // bottom to top
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

void sortInsert(stack<int>&st, int x){
    if(st.empty()==1 || ((st.empty()==0) && (st.top()<x))){
        st.push(x);
        return;
    }

    int n = st.top();
    st.pop();
    sortInsert(st,x);
    st.push(n);
}

void sortStack(stack<int>& st){
    //base case
    if(st.empty()==1){
        return;
    }

    int x = st.top();
    st.pop();
    sortStack(st);

    sortInsert(st,x);
}

int main(){
    stack<int> st;

    //5 -2 9 -7 3
    st.push(5);
    st.push(-2);
    st.push(9);
    st.push(-7);
    st.push(3);

    printStack(st);

    sortStack(st);

    printStack(st);
}