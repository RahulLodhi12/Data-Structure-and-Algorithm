#include<bits/stdc++.h>
using namespace std;

int findMinimumCost(string str){
    if(str.length()%2 != 0){
        return -1;
    }

    stack<char> st;

    // find valid part of string and push invalid part in stack
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        if(ch=='{'){
            st.push(ch);
        }
        else{ // if ch is closing brace
            if(st.empty()==0 && st.top()=='{'){
                st.pop(); //for valid part
            }
            else{
                st.push(ch); //for invalid part
            }
        }
    }

    //now stack contains invalid string
    int a=0,b=0;
    while(st.empty()==0){
        if(st.top() == '{'){
            a++; // closing bracket
        }
        else{
            b++; // opening bracket
        }
        st.pop();
    }

    int ans = (a+1)/2 + (b+1)/2;

    return ans;
}

int main(){
    string str;
    cin>>str;

    cout<<findMinimumCost(str)<<endl;
}