#include<bits/stdc++.h>
using namespace std;

int main(){

    string str = "Rahul";

    stack<char> st;

    // pushing str character in stack st
    for(int i=0;i<str.length();i++){
        st.push(str[i]);
    }

    // replace str character by stack st items(char)
    for(int i=0;i<str.length();i++){
        str[i] = st.top();
        st.pop();
    }

    cout<<"Reverse using stack: "<<str<<endl;
}
