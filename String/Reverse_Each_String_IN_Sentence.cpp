#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);

    stack<char> st;

    string ans = "";

    for(int i=0;i<s.length();i++){
        if(s[i] != ' '){
            st.push(s[i]);
        }
        else{
            while(st.empty()==0){
                ans += st.top();
                st.pop();
            }
            ans += " ";
        }
    }

    // for last word of the sentence
    while(st.empty()==0){
        ans += st.top();
        st.pop();
    }

    cout<<ans<<endl;
}