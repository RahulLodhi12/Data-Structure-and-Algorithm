#include<bits/stdc++.h>
using namespace std;

bool isValid(string str){
    stack<char> st;

    for(int i=0;i<str.length();i++){
        char ch = str[i];

        //if ch is opening bracket
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else{ //if ch is closing bracket
            if(st.empty() == 0){
                char top = st.top();
                if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(st.empty() == 1){
        return true;
    }

    return false;

}

int main(){
    string str;
    cin>>str;

    if(isValid(str)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
}