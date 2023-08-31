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

void func(stack<int>& st, int x){
    //base case
    if(st.empty()==1){
        st.push(x);
        return;
    }

    int n = st.top();
    st.pop();
    func(st,x);
    st.push(n);
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

    func(st,3);

    cout<<"After insert: "<<endl;
    printStack(st);
}