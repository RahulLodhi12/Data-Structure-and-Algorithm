bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> st;

    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch=='{' || ch=='(' || ch=='['){ // opening bracket
            st.push(ch);
        }
        else{ // closing bracket
            if(st.empty()==0){
                char top = st.top();
                if((top=='(' && ch==')') || (top=='{' && ch=='}') || (top=='[' && ch==']')){
                    st.pop();
                }
                else{ // not matching
                    return false;
                }
            }
            else{ // stack is empty
                return false;
            }
        }
    }
    return true;
}