#include<bits/stdc++.h>
using namespace std;

bool isRedundant(string s){
    stack<char> st;

    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            st.push(ch);
        }
        else{
            if(ch==')'){ // checking starts from down here.
                bool isRedundant = true;
                while(st.top() != '('){
                    char top = st.top();
                    if(top=='+' || top=='-' || top=='*' || top=='/'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true){ // check before pop.
                    return true;
                }
                st.pop();
            }
        }
    }
    
    return false;
}

int main(){
    string str;
    cin>>str;

    if(isRedundant(str)==false){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
}